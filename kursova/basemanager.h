#ifndef BASEMANAGER_H
#define BASEMANAGER_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "categorymodel.h"
#include "subcategorymodel.h"
#include "companymodel.h"

class BaseManager : public QObject
{
    Q_OBJECT
private:
    CategoryModel *categoryModel;
    SubcategoryModel *subcategoryModel;
    CompanyModel *companyModel;
public:
    explicit BaseManager(QObject *parent = 0);
    void addSubcategory(QString name, QString catName);
    void addCategory(QString name);
    void addCompany(QStringList data, QString subName);
    void delCategory(QString name);
    void delSubcategory(QString name);
    void delCompany(QString name);
    void createBase();
    void updateCompany(QStringList list);
    void updateCategory(QString newName, QString oldName);
    void updateSubcategory(QString newName, QString oldName);
    QStringList categoryList();
    QStringList companyList(QString name);
    QStringList subcategoryList(QString name);
    QStringList companyDataByName(QString name);
    
signals:
    
public slots:
    
};

#endif // BASEMANAGER_H
