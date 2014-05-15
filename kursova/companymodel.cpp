#include "companymodel.h"

CompanyModel::CompanyModel(QObject *parent) :
    QObject(parent)
{

}

void CompanyModel::createTable()
{
    QSqlQuery query;
    query.exec("CREATE TABLE Company (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL , indexId INTEGER, "
                         "name TEXT, address TEXT, tel TEXT, mobTel TEXT, fax TEXT, description TEXT)");
}

void CompanyModel::add(QStringList data, QString subCategoryId)
{
    QSqlQuery query;
    query.exec(QString("INSERT INTO \"Company\" (indexId, name, address, tel, mobTel, fax, description) "
                                        "VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7');")
                                .arg(subCategoryId, data.at(0), data.at(1), data.at(2), data.at(3), data.at(4),
                                     data.at(5)));
}

void CompanyModel::del(QString name)
{
    QSqlQuery query;
    query.exec(QString("DELETE FROM \"Company\" WHERE \"name\"='%1';")
                                .arg(name));
}

QStringList CompanyModel::list(QString subCategoryId)
{
    QStringList list;
    QSqlQuery query;

    query.exec(QString("SELECT \"name\" FROM \"Company\" WHERE \"indexId\"='%1';").arg(subCategoryId));
    while (query.next()) {
        list << query.value(0).toString();
    }
    return list;
}

QStringList CompanyModel::dataByName(QString name)
{
    QStringList list;
    QSqlQuery query;

    query.exec(QString("SELECT \"name\", \"address\", \"tel\", \"mobTel\", \"fax\", \"description\", \"id\" FROM \"Company\" WHERE \"name\"='%1';").arg(name));
    while (query.next()) {
        for (int i = 0; i < 7; ++i) {
            list << query.value(i).toString();
        }
    }
    qDebug()<<list.count();
    return list;
}

void CompanyModel::update(QStringList list)
{
    QSqlQuery query;
    query.exec(QString("UPDATE \"Company\" SET \"name\"='%1', \"address\"='%2', \"tel\"='%3', \"mobTel\"='%4', \"fax\"='%5', \"description\"='%6' WHERE \"ID\"='%7';")
               .arg(list.at(0), list.at(1), list.at(2), list.at(3), list.at(4), list.at(5), list.at(6)));
}
