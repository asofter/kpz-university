#include <QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QTranslator>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    QTranslator translator;
    translator.load(":/translat_ua.qm");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();
    return a.exec();
}
