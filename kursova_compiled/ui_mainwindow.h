/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *catTab;
    QGridLayout *gridLayout_4;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QToolButton *pushButton;
    QLabel *label_3;
    QWidget *aboutTab;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(412, 418);
        MainWindow->setIconSize(QSize(48, 48));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        catTab = new QWidget();
        catTab->setObjectName(QStringLiteral("catTab"));
        gridLayout_4 = new QGridLayout(catTab);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        widget = new QWidget(catTab);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(toolButton, 0, 0, 1, 1);

        pushButton = new QToolButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setIconSize(QSize(32, 32));

        gridLayout_2->addWidget(pushButton, 0, 2, 1, 1);


        gridLayout_4->addWidget(widget, 0, 0, 1, 1);

        label_3 = new QLabel(catTab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 1, 0, 1, 1);

        tabWidget->addTab(catTab, QString());
        aboutTab = new QWidget();
        aboutTab->setObjectName(QStringLiteral("aboutTab"));
        gridLayout_3 = new QGridLayout(aboutTab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(aboutTab);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 1, 1, 1, 1);

        label_2 = new QLabel(aboutTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 2, 2, 1, 1);

        pushButton_2 = new QPushButton(aboutTab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 0, 2, 1, 1);

        tabWidget->addTab(aboutTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lineEdit->setText(QString());
        toolButton->setText(QApplication::translate("MainWindow", "<-", 0));
        pushButton->setText(QApplication::translate("MainWindow", "...", 0));
        label_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(catTab), QApplication::translate("MainWindow", "Tab 1", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(aboutTab), QApplication::translate("MainWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
