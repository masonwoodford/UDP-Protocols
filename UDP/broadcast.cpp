#include "broadcast.h"
#include "ui_broadcast.h"
#include "mainwindow.h"

Broadcast::Broadcast(int portChoice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Broadcast)
{
    ui->setupUi(this);
    udpSocket = new QUdpSocket(this);

    connect(&timer, &QTimer::timeout, this, &Broadcast::broadcastDatagram);
    startBroadcasting();
    this->portChoice = portChoice;
}

Broadcast::~Broadcast()
{
    delete ui;
}

void Broadcast::startBroadcasting() {
    qDebug() << "Began Broadcasting";
    timer.start(1000);
}


void Broadcast::broadcastDatagram()
{
    std::string IP = "";
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    QByteArray data = "";

    for (const QHostAddress &temp_address: QNetworkInterface::allAddresses()) {
        if (shouldBroadcast == false) {
            qDebug() << "Stopped Broadcasting";
            break;
        }
        if (temp_address.protocol() == QAbstractSocket::IPv4Protocol && temp_address != localhost) {
             data += temp_address.toString();
             data += " ";
             qDebug() << data;
             qDebug() << i;
             i++;
             data += QByteArray::number(portChoice);
             udpSocket->writeDatagram(data, QHostAddress(temp_address.toString()), TCPPort);
        }
    }
}

void Broadcast::stopBroadcasting() {
    timer.stop();
    shouldBroadcast = false;
    ui->broadcastLabel->setText("Stopped Broadcasting...");
}
