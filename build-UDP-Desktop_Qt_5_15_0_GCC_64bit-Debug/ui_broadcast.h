/********************************************************************************
** Form generated from reading UI file 'broadcast.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BROADCAST_H
#define UI_BROADCAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Broadcast
{
public:
    QLabel *broadcastLabel;

    void setupUi(QDialog *Broadcast)
    {
        if (Broadcast->objectName().isEmpty())
            Broadcast->setObjectName(QString::fromUtf8("Broadcast"));
        Broadcast->resize(400, 300);
        broadcastLabel = new QLabel(Broadcast);
        broadcastLabel->setObjectName(QString::fromUtf8("broadcastLabel"));
        broadcastLabel->setGeometry(QRect(10, 100, 381, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        broadcastLabel->setFont(font);

        retranslateUi(Broadcast);

        QMetaObject::connectSlotsByName(Broadcast);
    } // setupUi

    void retranslateUi(QDialog *Broadcast)
    {
        Broadcast->setWindowTitle(QCoreApplication::translate("Broadcast", "Dialog", nullptr));
        broadcastLabel->setText(QCoreApplication::translate("Broadcast", "Broadcasting...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Broadcast: public Ui_Broadcast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BROADCAST_H
