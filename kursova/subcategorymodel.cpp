#include "subcategorymodel.h"

SubcategoryModel::SubcategoryModel(QObject *parent) :
    QObject(parent)
{

}

void SubcategoryModel::createTable()
{
    QSqlQuery query;

    query.exec("CREATE TABLE Subcategory (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL , indexId INTEGER, name TEXT)");
}

void SubcategoryModel::add(QString name, QString catId)
{
    QSqlQuery query;
    query.exec(QString("INSERT INTO \"Subcategory\" (name, indexId) VALUES ('%1', '%2');")
                                .arg(name, catId));
}

void SubcategoryModel::del(QString name)
{
    QSqlQuery query;
    QString   subId = subcatIdByName(name);
    query.exec(QString("DELETE FROM \"Company\" WHERE \"indexId\"='%1';")
                                        .arg(subId));
    query.exec(QString("DELETE FROM \"Subcategory\" WHERE \"id\"='%1';")
                                .arg(subId));
}

QStringList SubcategoryModel::list(QString id)
{
    QStringList list;
    QSqlQuery query;

    query.exec(QString("SELECT \"name\" FROM \"Subcategory\" WHERE \"indexId\"='%1';").arg(id));
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}

QString SubcategoryModel::subcatIdByName(QString name)
{
    QSqlQuery query;
    query.exec(QString("SELECT \"id\" FROM \"Subcategory\" WHERE \"name\"='%1';").arg(name));
    query.first();
    return query.value(0).toString();
}

void SubcategoryModel::update(QString newName, QString oldName)
{
    QSqlQuery query;
    query.exec(QString("UPDATE \"Subcategory\" SET \"name\"='%1' WHERE \"name\"='%2';")
               .arg(newName, oldName));
}
