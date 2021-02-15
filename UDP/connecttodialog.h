#ifndef CONNECTTODIALOG_H
#define CONNECTTODIALOG_H

#include <QDialog>
#include <QHostAddress>
#include <QWidget>
#include <QVector>
#include <QFile>
#include "entry.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ConnectToDialog;
}
class QLabel;
class QUdpSocket;
QT_END_NAMESPACE

class ConnectToDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectToDialog(QWidget *parent = nullptr);
    ~ConnectToDialog();

private:
    Ui::ConnectToDialog *ui;
    void connectButtonPressed();
    QUdpSocket *udpSocket = nullptr;
    QVector<Entry*> mEntries;
    QVector<QString> options;
    int index = 0;
    void addEntry(QString IP_name, QString portName);
    int TCPPort = 45454;

public slots:
    void userChoice(Entry* entry);
private slots:
    void processPendingDatagrams();

signals:
    void userIntendsConnection(QHostAddress address, quint64 port);

};

#endif // CONNECTTODIALOG_H
