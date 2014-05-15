#include "basemanager.h"

BaseManager::BaseManager(QObject *parent) :
    QObject(parent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("catalog.sqlite");
    bool ok = db.open();
    qDebug()<<ok;

    // Init models
    categoryModel = new CategoryModel();
    subcategoryModel = new SubcategoryModel();
    companyModel = new CompanyModel();
}

void BaseManager::createBase()
{
    categoryModel->createTable();
    subcategoryModel->createTable();
    companyModel->createTable();
}

void BaseManager::addCategory(QString name)
{
    categoryModel->add(name);
}

void BaseManager::addSubcategory(QString name, QString catName)
{
    QString catId = categoryModel->catIdByName(catName);
    subcategoryModel->add(name, catId);
}

void BaseManager::addCompany(QStringList data, QString subName)
{
    QString subCategoryId = subcategoryModel->subcatIdByName(subName);
    companyModel->add(data, subCategoryId);
}

void BaseManager::delCategory(QString name)
{
    categoryModel->del(name);
}

void BaseManager::delSubcategory(QString name)
{
    subcategoryModel->del(name);
}

void BaseManager::delCompany(QString name)
{
    companyModel->del(name);
}

QStringList BaseManager::categoryList()
{
    return categoryModel->list();
}

QStringList BaseManager::subcategoryList(QString name)
{
    QString catId = categoryModel->catIdByName(name);
    return subcategoryModel->list(catId);
}

QStringList BaseManager::companyList(QString name)
{
    QString subCategoryId = subcategoryModel->subcatIdByName(name);
    return companyModel->list(subCategoryId);
}

QStringList BaseManager::companyDataByName(QString name)
{
    return companyModel->dataByName(name);
}

void BaseManager::updateCompany(QStringList list)
{
    companyModel->update(list);
}

void BaseManager::updateCategory(QString newName, QString oldName)
{
    categoryModel->update(newName, oldName);
}

void BaseManager::updateSubcategory(QString newName, QString oldName)
{
    subcategoryModel->update(newName, oldName);
}
