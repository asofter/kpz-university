#ifndef COMPANYDIALOG_H
#define COMPANYDIALOG_H

#include "basemanager.h"

#include <QDialog>
#include <QDebug>
#include <QAbstractButton>
#include <QMessageBox>
#include <QPushButton>
#include <QToolButton>

namespace Ui {
class CompanyDialog;
}

class CompanyDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CompanyDialog(QWidget *parent = 0);
    QStringList comData();
    void setComData(QStringList list);
    void add();
    void view();
    void edit();
    QString id;
    QStringList data;
    bool editFlag;
    QToolButton *buttonEdit;
    QPushButton *buttonSave;
    QToolButton *buttonDel;
    ~CompanyDialog();
    
private:
    Ui::CompanyDialog *ui;

private slots:
    void butEditClicked();
    void butDelClicked();
    void butSaveClicked();
};

#endif // COMPANYDIALOG_H
