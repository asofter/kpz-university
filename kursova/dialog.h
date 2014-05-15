#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    QString text();
    void setText(QString name);
    QPushButton *buttonSave;
    ~Dialog();
    
private:
    Ui::Dialog *ui;

private slots:
    void butSaveClicked();
};

#endif // DIALOG_H
