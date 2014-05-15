#ifndef COMPANYMODEL_H
#define COMPANYMODEL_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class CompanyModel : public QObject
{
    Q_OBJECT
public:
    explicit CompanyModel(QObject *parent = 0);
    void add(QStringList data, QString subCategoryId);
    void del(QString name);
    void createTable();
    void update(QStringList list);
    QStringList list(QString subCategoryId);
    QStringList dataByName(QString name);

signals:

public slots:

};

#endif // COMPANYMODEL_H
