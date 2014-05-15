#ifndef CATEGORYMODEL_H
#define CATEGORYMODEL_H

#include <QObject>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

class CategoryModel : public QObject
{
    Q_OBJECT
public:
    explicit CategoryModel(QObject *parent = 0);
    void add(QString name);
    void del(QString name);
    void createTable();
    void update(QString newName, QString oldName);
    QStringList list();
    QString catIdByName(QString name);

signals:

public slots:

};

#endif // CATEGORYMODEL_H
