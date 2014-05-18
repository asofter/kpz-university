#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Title"));
    setWindowIcon(QIcon(":/icons/icon.png"));

    ui->lineEdit->setPlaceholderText(tr("Search"));
    ui->label->setPixmap(QPixmap(":/icons/about.jpg"));
    ui->label_2->setTextFormat(Qt::RichText);
    ui->label_2->setText("<h3>Зроблена Яремчуком Олександром</h3>");
    ui->toolButton->setIcon(QPixmap(":/icons/back.png"));
    ui->pushButton->setIcon(QPixmap(":/icons/add.png"));
    ui->toolButton->setHidden(true);

    ui->pushButton_2->setToolTip("Відкрити файл довідки");
    ui->pushButton_2->setText("Довідка");

    ui->pushButton->setToolTip("Натисніть, щоб додати новий елемент");
    ui->lineEdit->setToolTip("Починайте вводити слово для пошуку потрібного елемента.");

    QShortcut *helpShortcut = new QShortcut(QKeySequence("F1"), this);
    QObject::connect(helpShortcut, SIGNAL(activated()), ui->pushButton_2, SLOT(animateClick()));

    QShortcut *addShortcut = new QShortcut(QKeySequence("Ctrl+a"), this);
    QObject::connect(addShortcut, SIGNAL(activated()), ui->pushButton, SLOT(animateClick()));

    listView = new QListView(this);
    ui->catTab->layout()->addWidget(listView);
    listView->setContextMenuPolicy(Qt::ActionsContextMenu);
    connect(listView, SIGNAL(doubleClicked(QModelIndex)),this,  SLOT(catalogCliked(QModelIndex)));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(search(QString)));

    ui->tabWidget->setTabText(0,tr("Catalog"));
    ui->tabWidget->setTabText(1,tr("About"));
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QAction *delAct = new QAction(tr("Delete"), this);
    delAct->setIcon(QIcon(":/icons/remove.svgz"));
    QAction *editAct = new QAction(tr("Edit"), this);
    editAct->setIcon(QIcon(":/icons/edit.svgz"));

    connect(delAct, SIGNAL(triggered()), this, SLOT(delData()));
    connect(editAct, SIGNAL(triggered()), this, SLOT(editData()));

    QShortcut *delShortcut = new QShortcut(QKeySequence("Ctrl+d"), this);
    QObject::connect(delShortcut, SIGNAL(activated()), this, SLOT(delData()));

    QShortcut *editShortcut = new QShortcut(QKeySequence("Ctrl+e"), this);
    QObject::connect(editShortcut, SIGNAL(activated()), this, SLOT(editData()));

    listView->addAction(delAct);
    listView->addAction(editAct);

    model = new QStringListModel(this);
    catModel = new QStringListModel(this);
    subModel = new QStringListModel(this);
    comModel = new QStringListModel(this);
    sql = new BaseManager();
    sql->createBase();
    currentPos = 0;

    updateCategory();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::catalogCliked(QModelIndex index)
{
    ui->toolButton->setHidden(false);
    name = index.data().toString();
    if(currentPos < 3){
        currentPos++;
        searchClear();
    }
    if(currentPos == 1){
        catName = name;
        updateSubcategory();
    } else if (currentPos == 2){
        subName = name;
        updateCompany();
    } else if (currentPos == 3){
        CompanyDialog comDiag(this);
        comDiag.view();
        comDiag.setComData(sql->companyDataByName(name));
        if (comDiag.exec() == 1) {
            sql->updateCompany(comDiag.comData());
        }
        updateCompany();
        currentPos--;
    }
}

void MainWindow::delData()
{
    QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);

    name = listView->currentIndex().data().toString();
    if(currentPos == 0) {
        msgBox.setText(tr("Do you really want to remove this category?"));
        if(msgBox.exec() == QMessageBox::Ok){
            sql->delCategory(name);
            posChanged();
        }
    } else if(currentPos == 1) {
        msgBox.setText(tr("Do you really want to remove this subcategory?"));
        if(msgBox.exec() == QMessageBox::Ok){
            sql->delSubcategory(name);
            posChanged();
        }
    } else if(currentPos == 2) {
        msgBox.setText(tr("Do you really want to remove this company?"));
        if(msgBox.exec() == QMessageBox::Ok){
            sql->delCompany(name);
            posChanged();
        }
    }
}

void MainWindow::editData()
{
    QString str;
    name = listView->currentIndex().data().toString();
    if(currentPos == 2){

        CompanyDialog comDiag(this);
        comDiag.edit();
        comDiag.editFlag = true;
        comDiag.setComData(sql->companyDataByName(name));

        if (comDiag.exec() == 1) {
            sql->updateCompany(comDiag.comData());
            updateCompany();
        }
    } else {
        Dialog diag(this);
        if(currentPos == 0)
            diag.setWindowTitle(tr("Category"));
        else if(currentPos == 1)
            diag.setWindowTitle(tr("Subcategory"));
        diag.setText(name);
        if (diag.exec() == 1) {
            str = diag.text();
            if(currentPos == 0){
                sql->updateCategory(str, name);
                updateCategory();
            } else if(currentPos == 1){
                sql->updateSubcategory(str, name);
                updateSubcategory();
            }
        }
    }
}

void MainWindow::on_pushButton_2_clicked() {
    QDesktopServices::openUrl(QUrl::fromLocalFile("documentation.pdf"));
}

void MainWindow::on_pushButton_clicked()
{
    QString str;
    if(currentPos == 2){
        CompanyDialog comDiag(this);
        comDiag.add();
        if (comDiag.exec() == 1) {
            sql->addCompany(comDiag.comData(), subName);
            updateCompany();
        }
    } else {
        Dialog diag(this);
        if(currentPos == 0)
            diag.setWindowTitle(tr("Category"));
        else if(currentPos == 1)
            diag.setWindowTitle(tr("Subcategory"));
        if (diag.exec() == 1) {
            str = diag.text();
            if(currentPos == 0){
                sql->addCategory(str);
                updateCategory();
            } else if(currentPos == 1){
                sql->addSubcategory(str, name);
                updateSubcategory();
            }
        }
    }
}

void MainWindow::updateCompany()
{
    ui->label_3->setText(catName + " >> " + subName);
    comList = sql->companyList(subName);
    comModel->setStringList(comList.filter(searchText, Qt::CaseInsensitive));
    listView->setModel(comModel);
}

void MainWindow::updateCategory()
{
    ui->label_3->setText(tr("Category"));
    catList = sql->categoryList();
    model->setStringList(catList.filter(searchText, Qt::CaseInsensitive));
    listView->setModel(model);
}

void MainWindow::updateSubcategory()
{
    ui->label_3->setText(catName);
    subList = sql->subcategoryList(catName);
    model->setStringList(subList.filter(searchText, Qt::CaseInsensitive));
    listView->setModel(model);
}

void MainWindow::on_toolButton_clicked()
{
    if (currentPos > 0){
        currentPos--;
        searchClear();
    }
    if (currentPos < 3)
        ui->catTab->layout()->addWidget(listView);
    if(currentPos == 0){
        ui->toolButton->setHidden(true);
        updateCategory();
    } else if (currentPos == 1){
        updateSubcategory();
    }
}

void MainWindow::posChanged()
{
    if(currentPos == 0){
        updateCategory();
    } else if(currentPos == 1){
        updateSubcategory();
    } else if(currentPos == 2){
        updateCompany();
    }
}

void MainWindow::search(QString text)
{
    searchText = text;
    if(currentPos == 0){
        updateCategory();
    } else if(currentPos == 1){
        updateSubcategory();
    } else if(currentPos == 2){
        updateCompany();
    }
}

void MainWindow::searchClear()
{
    searchText.clear();
    ui->lineEdit->clear();
    ui->lineEdit->clearFocus();
}
