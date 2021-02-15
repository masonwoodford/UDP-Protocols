/********************************************************************************
** Form generated from reading UI file 'entry.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRY_H
#define UI_ENTRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Entry
{
public:
    QPushButton *IP_ph;
    QPushButton *IP;
    QPushButton *Port_ph;
    QPushButton *Port;

    void setupUi(QWidget *Entry)
    {
        if (Entry->objectName().isEmpty())
            Entry->setObjectName(QString::fromUtf8("Entry"));
        Entry->resize(400, 38);
        IP_ph = new QPushButton(Entry);
        IP_ph->setObjectName(QString::fromUtf8("IP_ph"));
        IP_ph->setGeometry(QRect(0, 10, 31, 25));
        IP = new QPushButton(Entry);
        IP->setObjectName(QString::fromUtf8("IP"));
        IP->setGeometry(QRect(30, 10, 171, 25));
        Port_ph = new QPushButton(Entry);
        Port_ph->setObjectName(QString::fromUtf8("Port_ph"));
        Port_ph->setGeometry(QRect(200, 10, 41, 25));
        Port = new QPushButton(Entry);
        Port->setObjectName(QString::fromUtf8("Port"));
        Port->setGeometry(QRect(240, 10, 151, 25));

        retranslateUi(Entry);

        QMetaObject::connectSlotsByName(Entry);
    } // setupUi

    void retranslateUi(QWidget *Entry)
    {
        Entry->setWindowTitle(QCoreApplication::translate("Entry", "Form", nullptr));
        IP_ph->setText(QCoreApplication::translate("Entry", "IP:", nullptr));
        IP->setText(QString());
        Port_ph->setText(QCoreApplication::translate("Entry", "Port:", nullptr));
        Port->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Entry: public Ui_Entry {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRY_H
