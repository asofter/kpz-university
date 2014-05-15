#include "companydialog.h"
#include "ui_companydialog.h"

CompanyDialog::CompanyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompanyDialog)
{
    ui->setupUi(this);

    setWindowIcon(QIcon(":/icon.png"));
    setWindowTitle(tr("Company"));
    setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->nameLabel->setText(tr("Name:"));
    ui->addressLabel->setText(tr("Address:"));
    ui->telLabel->setText(tr("Tel.:"));
    ui->mobTelLabel->setText(tr("Mob. Tel.:"));
    ui->faxLabel->setText(tr("Fax:"));
    ui->descriptionLabel->setText(tr("Description:"));

    ui->nameLineEdit->setToolTip(tr("tool tip name"));
    ui->addressLineEdit->setToolTip(tr("tool tip address"));
    ui->telLineEdit->setToolTip(tr("tool tip phone"));
    ui->mobTelLineEdit->setToolTip(tr("tool tip mob phone"));
    ui->faxLineEdit->setToolTip(tr("tool tip fax"));
    ui->descriptionTextEdit->setToolTip(tr("tool tip description"));
}

CompanyDialog::~CompanyDialog()
{
    delete ui;
}

QStringList CompanyDialog::comData()
{
    QStringList list;
    list << ui->nameLineEdit->text();
    list << ui->addressLineEdit->text();
    list << ui->telLineEdit->text();
    list << ui->mobTelLineEdit->text();
    list << ui->faxLineEdit->text();
    list << ui->descriptionTextEdit->toPlainText();
    if(editFlag)
        list << id;
    return list;
}

void CompanyDialog::setComData(QStringList list)
{
    data = list;
    ui->labelDataName->setText(data.at(0));
    ui->labelDataAddress->setText(data.at(1));
    ui->labelDataTel->setText(data.at(2));
    ui->labelDataMobTel->setText(data.at(3));
    ui->labelDataFax->setText(data.at(4));
    ui->labelDataDesc->setText(data.at(5));
    id = data.at(6);
    setWindowTitle(QString(data.at(0)));
}

void CompanyDialog::add()
{
    ui->telLineEdit->setInputMask("(\\099) 99-99-99");
    ui->mobTelLineEdit->setInputMask("(\\099) 9999-999");
    ui->faxLineEdit->setInputMask("(\\099) 99-99-99");

    ui->buttonBox->clear();
    buttonSave = new QPushButton(tr("Save"), this);
    connect(buttonSave,  SIGNAL(clicked()), this, SLOT(butSaveClicked()));
    ui->buttonBox->addButton(tr("Cansel"), QDialogButtonBox::RejectRole);
    ui->buttonBox->addButton(buttonSave,  QDialogButtonBox::ActionRole);
}

void CompanyDialog::view()
{
    ui->nameLineEdit->setHidden(true);
    ui->addressLineEdit->setHidden(true);
    ui->telLineEdit->setHidden(true);
    ui->mobTelLineEdit->setHidden(true);
    ui->faxLineEdit->setHidden(true);
    ui->descriptionTextEdit->setHidden(true);

    buttonEdit = new QToolButton(this);
    buttonDel  = new QToolButton(this);
    buttonEdit->setIconSize(QSize(24,24));
    buttonDel->setIconSize(QSize(24,24));
    buttonEdit->setIcon(QIcon(":/icons/edit.svgz"));
    buttonDel->setIcon(QIcon(":/icons/remove.svgz"));
    connect(buttonEdit, SIGNAL(clicked()), this, SLOT(butEditClicked()));
    connect(buttonDel,  SIGNAL(clicked()), this, SLOT(butDelClicked()));

    ui->buttonBox->clear();
    ui->buttonBox->addButton(buttonEdit, QDialogButtonBox::NoRole);
    ui->buttonBox->addButton(buttonDel,  QDialogButtonBox::NoRole);
}

void CompanyDialog::edit()
{
    ui->labelDataName->setHidden(true);
    ui->labelDataAddress->setHidden(true);
    ui->labelDataTel->setHidden(true);
    ui->labelDataMobTel->setHidden(true);
    ui->labelDataFax->setHidden(true);
    ui->labelDataDesc->setHidden(true);

    ui->nameLineEdit->setHidden(false);
    ui->addressLineEdit->setHidden(false);
    ui->telLineEdit->setHidden(false);
    ui->mobTelLineEdit->setHidden(false);
    ui->faxLineEdit->setHidden(false);
    ui->descriptionTextEdit->setHidden(false);

    ui->nameLineEdit->setText(data.at(0));
    ui->addressLineEdit->setText(data.at(1));
    ui->telLineEdit->setText(data.at(2));
    ui->mobTelLineEdit->setText(data.at(3));
    ui->faxLineEdit->setText(data.at(4));
    ui->descriptionTextEdit->setPlainText(data.at(5));

    ui->buttonBox->clear();
    buttonSave = new QPushButton(tr("Save"), this);
    connect(buttonSave,  SIGNAL(clicked()), this, SLOT(butSaveClicked()));
    ui->buttonBox->addButton(tr("Cansel"), QDialogButtonBox::RejectRole);
    ui->buttonBox->addButton(buttonSave,  QDialogButtonBox::ActionRole);

    ui->telLineEdit->setInputMask("(\\099) 99-99-99");
    ui->mobTelLineEdit->setInputMask("(\\099) 9999-999");
    ui->faxLineEdit->setInputMask("(\\099) 99-99-99");
}

void CompanyDialog::butEditClicked()
{
    edit();
}

void CompanyDialog::butDelClicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Notification"));
    msgBox.setText(tr("Do you really want to remove this company?"));
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    if(msgBox.exec() == QMessageBox::Ok){
        BaseManager base;
        base.delCompany(data.at(0));
    }
}

void CompanyDialog::butSaveClicked()
{
    if(ui->nameLineEdit->text().isEmpty() || ui->addressLineEdit->text().isEmpty()){
        QMessageBox msgBox;
        msgBox.warning(this,tr("Warning!"), tr("Name and address can not be empty!"), QMessageBox::Ok );
    } else {
        done(1);
    }
}

