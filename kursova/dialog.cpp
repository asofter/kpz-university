#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    setWindowFlags (windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->lineEdit->setFocus();
    ui->buttonBox->clear();
    buttonSave = new QPushButton(tr("Save"), this);
    connect(buttonSave,  SIGNAL(clicked()), this, SLOT(butSaveClicked()));
    ui->buttonBox->addButton(tr("Cansel"), QDialogButtonBox::RejectRole);
    ui->buttonBox->addButton(buttonSave,  QDialogButtonBox::ActionRole);
    ui->lineEdit->setToolTip(tr("tool tip name"));
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::text()
{
    return ui->lineEdit->text();
}

void Dialog::setText(QString name)
{
    ui->lineEdit->setText(name);
}

void Dialog::butSaveClicked()
{
    if(ui->lineEdit->text().isEmpty()){
        QMessageBox msgBox;
        msgBox.warning(this, tr("Warning!"), tr("Name can not be empty!"), QMessageBox::Ok );
        ui->lineEdit->setFocus();
    } else {
        done(1);
    }
}
