#include "categorymodel.h"

CategoryModel::CategoryModel(QObject *parent) :
    QObject(parent)
{

}

void CategoryModel::createTable()
{
    QSqlQuery query;
    query.exec("CREATE TABLE Category (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL , name TEXT)");
}

void CategoryModel::add(QString name)
{
    QSqlQuery query;
    query.exec(QString("INSERT INTO \"Category\" (name) VALUES ('%1');").arg(name));
}

void CategoryModel::del(QString name)
{
    QSqlQuery query;
    QSqlQuery temp;
    QString catId = catIdByName(name);
    query.exec(QString("DELETE FROM \"Category\" WHERE \"ID\"='%1';")
                                .arg(catId));
    query.exec(QString("SELECT \"id\" FROM \"Subcategory\" WHERE \"indexId\"='%1';").arg(catId));
    while (query.next()) {
        temp.exec(QString("DELETE FROM \"Company\" WHERE \"indexId\"='%1';")
                                        .arg(query.value(0).toString()));
    }
    query.exec(QString("DELETE FROM \"Subcategory\" WHERE \"indexId\"='%1';")
                                    .arg(catId));
}

QStringList CategoryModel::list()
{
    QStringList list;
    QSqlQuery query;
    query.exec(QString("SELECT \"name\" FROM \"Category\";"));
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}

QString CategoryModel::catIdByName(QString name)
{
    QSqlQuery query;
    query.exec(QString("SELECT \"id\" FROM \"Category\" WHERE \"name\"='%1';").arg(name));
    query.first();
    return query.value(0).toString();
}

void CategoryModel::update(QString newName, QString oldName)
{
    QSqlQuery query;
    query.exec(QString("UPDATE \"Category\" SET \"name\"='%1' WHERE \"name\"='%2';")
               .arg(newName, oldName));
}
