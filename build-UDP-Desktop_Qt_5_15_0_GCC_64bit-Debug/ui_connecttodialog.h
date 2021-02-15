/********************************************************************************
** Form generated from reading UI file 'connecttodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTTODIALOG_H
#define UI_CONNECTTODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectToDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLineEdit *ipAddressLineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *portLineEdit;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *entriesLayout;
    QHBoxLayout *horizontalLayout_3;

    void setupUi(QDialog *ConnectToDialog)
    {
        if (ConnectToDialog->objectName().isEmpty())
            ConnectToDialog->setObjectName(QString::fromUtf8("ConnectToDialog"));
        ConnectToDialog->resize(533, 423);
        buttonBox = new QDialogButtonBox(ConnectToDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 390, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(ConnectToDialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(140, 310, 391, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        ipAddressLineEdit = new QLineEdit(horizontalLayoutWidget);
        ipAddressLineEdit->setObjectName(QString::fromUtf8("ipAddressLineEdit"));

        horizontalLayout->addWidget(ipAddressLineEdit);

        horizontalLayoutWidget_2 = new QWidget(ConnectToDialog);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(140, 340, 391, 41));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        portLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout_2->addWidget(portLineEdit);

        verticalLayoutWidget = new QWidget(ConnectToDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 531, 311));
        entriesLayout = new QVBoxLayout(verticalLayoutWidget);
        entriesLayout->setObjectName(QString::fromUtf8("entriesLayout"));
        entriesLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        entriesLayout->addLayout(horizontalLayout_3);


        retranslateUi(ConnectToDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectToDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectToDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectToDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectToDialog)
    {
        ConnectToDialog->setWindowTitle(QCoreApplication::translate("ConnectToDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ConnectToDialog", "IP Address", nullptr));
        label_2->setText(QCoreApplication::translate("ConnectToDialog", "Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectToDialog: public Ui_ConnectToDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTTODIALOG_H
