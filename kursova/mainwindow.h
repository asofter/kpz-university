#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basemanager.h"
#include "companydialog.h"
#include "dialog.h"

#include <QMainWindow>
#include <QWidget>
#include <QDebug>
#include <QMenu>
#include <QTabWidget>
#include <QListView>
#include <QStringListModel>
#include <QTextDocumentFragment>
#include <QShortcut>
#include <QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    BaseManager *sql;
    QStringListModel *model;
    QStringListModel *catModel;
    QStringListModel *subModel;
    QStringListModel *comModel;
    QListView *listView;
    int currentPos;
    QString catName;
    QString subName;
    QString searchText;
    QStringList subList;
    QStringList catList;
    QStringList comList;
    QString name;

public slots:
    void catalogCliked(QModelIndex index);
    void delData();
    void editData();
    void updateCompany();
    void updateCategory();
    void updateSubcategory();
    void posChanged();
    void search(QString text);
    void searchClear();
private slots:
    void on_pushButton_clicked();
    void on_toolButton_clicked();
};

#endif // MAINWINDOW_H
