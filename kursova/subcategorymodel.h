#ifndef SUBCATEGORYMODEL_H
#define SUBCATEGORYMODEL_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "categorymodel.h"

class SubcategoryModel : public QObject
{
    Q_OBJECT
public:
    explicit SubcategoryModel(QObject *parent = 0);
    void add(QString name, QString catId);
    void del(QString name);
    void createTable();
    void update(QString newName, QString oldName);
    QStringList list(QString id);
    QString subcatIdByName(QString name);

signals:

public slots:

};

#endif // SUBCATEGORYMODEL_H
