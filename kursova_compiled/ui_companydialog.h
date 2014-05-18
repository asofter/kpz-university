/********************************************************************************
** Form generated from reading UI file 'companydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPANYDIALOG_H
#define UI_COMPANYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CompanyDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *addressLabel;
    QLineEdit *addressLineEdit;
    QLabel *telLabel;
    QLineEdit *telLineEdit;
    QLabel *mobTelLabel;
    QLineEdit *mobTelLineEdit;
    QLabel *faxLabel;
    QLineEdit *faxLineEdit;
    QLabel *descriptionLabel;
    QPlainTextEdit *descriptionTextEdit;
    QDialogButtonBox *buttonBox;
    QLabel *labelDataName;
    QLabel *labelDataAddress;
    QLabel *labelDataTel;
    QLabel *labelDataMobTel;
    QLabel *labelDataFax;
    QLabel *labelDataDesc;

    void setupUi(QDialog *CompanyDialog)
    {
        if (CompanyDialog->objectName().isEmpty())
            CompanyDialog->setObjectName(QStringLiteral("CompanyDialog"));
        CompanyDialog->setWindowModality(Qt::WindowModal);
        CompanyDialog->resize(400, 300);
        gridLayout = new QGridLayout(CompanyDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        nameLabel = new QLabel(CompanyDialog);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        nameLineEdit = new QLineEdit(CompanyDialog);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameLineEdit->sizePolicy().hasHeightForWidth());
        nameLineEdit->setSizePolicy(sizePolicy);

        gridLayout->addWidget(nameLineEdit, 0, 1, 1, 1);

        addressLabel = new QLabel(CompanyDialog);
        addressLabel->setObjectName(QStringLiteral("addressLabel"));

        gridLayout->addWidget(addressLabel, 1, 0, 1, 1);

        addressLineEdit = new QLineEdit(CompanyDialog);
        addressLineEdit->setObjectName(QStringLiteral("addressLineEdit"));

        gridLayout->addWidget(addressLineEdit, 1, 1, 1, 1);

        telLabel = new QLabel(CompanyDialog);
        telLabel->setObjectName(QStringLiteral("telLabel"));

        gridLayout->addWidget(telLabel, 2, 0, 1, 1);

        telLineEdit = new QLineEdit(CompanyDialog);
        telLineEdit->setObjectName(QStringLiteral("telLineEdit"));

        gridLayout->addWidget(telLineEdit, 2, 1, 1, 1);

        mobTelLabel = new QLabel(CompanyDialog);
        mobTelLabel->setObjectName(QStringLiteral("mobTelLabel"));

        gridLayout->addWidget(mobTelLabel, 3, 0, 1, 1);

        mobTelLineEdit = new QLineEdit(CompanyDialog);
        mobTelLineEdit->setObjectName(QStringLiteral("mobTelLineEdit"));

        gridLayout->addWidget(mobTelLineEdit, 3, 1, 1, 1);

        faxLabel = new QLabel(CompanyDialog);
        faxLabel->setObjectName(QStringLiteral("faxLabel"));

        gridLayout->addWidget(faxLabel, 4, 0, 1, 1);

        faxLineEdit = new QLineEdit(CompanyDialog);
        faxLineEdit->setObjectName(QStringLiteral("faxLineEdit"));

        gridLayout->addWidget(faxLineEdit, 4, 1, 1, 1);

        descriptionLabel = new QLabel(CompanyDialog);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 5, 0, 1, 1);

        descriptionTextEdit = new QPlainTextEdit(CompanyDialog);
        descriptionTextEdit->setObjectName(QStringLiteral("descriptionTextEdit"));

        gridLayout->addWidget(descriptionTextEdit, 5, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CompanyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 0, 1, 3);

        labelDataName = new QLabel(CompanyDialog);
        labelDataName->setObjectName(QStringLiteral("labelDataName"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelDataName->sizePolicy().hasHeightForWidth());
        labelDataName->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelDataName, 0, 2, 1, 1);

        labelDataAddress = new QLabel(CompanyDialog);
        labelDataAddress->setObjectName(QStringLiteral("labelDataAddress"));
        sizePolicy1.setHeightForWidth(labelDataAddress->sizePolicy().hasHeightForWidth());
        labelDataAddress->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelDataAddress, 1, 2, 1, 1);

        labelDataTel = new QLabel(CompanyDialog);
        labelDataTel->setObjectName(QStringLiteral("labelDataTel"));
        sizePolicy1.setHeightForWidth(labelDataTel->sizePolicy().hasHeightForWidth());
        labelDataTel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelDataTel, 2, 2, 1, 1);

        labelDataMobTel = new QLabel(CompanyDialog);
        labelDataMobTel->setObjectName(QStringLiteral("labelDataMobTel"));
        sizePolicy1.setHeightForWidth(labelDataMobTel->sizePolicy().hasHeightForWidth());
        labelDataMobTel->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelDataMobTel, 3, 2, 1, 1);

        labelDataFax = new QLabel(CompanyDialog);
        labelDataFax->setObjectName(QStringLiteral("labelDataFax"));
        sizePolicy1.setHeightForWidth(labelDataFax->sizePolicy().hasHeightForWidth());
        labelDataFax->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(labelDataFax, 4, 2, 1, 1);

        labelDataDesc = new QLabel(CompanyDialog);
        labelDataDesc->setObjectName(QStringLiteral("labelDataDesc"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelDataDesc->sizePolicy().hasHeightForWidth());
        labelDataDesc->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(labelDataDesc, 5, 2, 1, 1);


        retranslateUi(CompanyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CompanyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CompanyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CompanyDialog);
    } // setupUi

    void retranslateUi(QDialog *CompanyDialog)
    {
        CompanyDialog->setWindowTitle(QApplication::translate("CompanyDialog", "Dialog", 0));
        nameLabel->setText(QApplication::translate("CompanyDialog", "TextLabel", 0));
        addressLabel->setText(QApplication::translate("CompanyDialog", "TextLabel", 0));
        telLabel->setText(QApplication::translate("CompanyDialog", "TextLabel", 0));
        mobTelLabel->setText(QApplication::translate("CompanyDialog", "TextLabel", 0));
        faxLabel->setText(QApplication::translate("CompanyDialog", "TextLabel", 0));
        descriptionLabel->setText(QApplication::translate("CompanyDialog", "TextLabel", 0));
        labelDataName->setText(QString());
        labelDataAddress->setText(QString());
        labelDataTel->setText(QString());
        labelDataMobTel->setText(QString());
        labelDataFax->setText(QString());
        labelDataDesc->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CompanyDialog: public Ui_CompanyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPANYDIALOG_H
