#include "connecttodialog.h"
#include "ui_connecttodialog.h"
#include <QtNetwork>
#include <QRegExp>

ConnectToDialog::ConnectToDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectToDialog)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(TCPPort, QUdpSocket::ShareAddress);

    connect(udpSocket, &QUdpSocket::readyRead, this, &ConnectToDialog::processPendingDatagrams);
    // Connect the "connect" button to fire off our new
    // connectButtonPressed method
    // This is a standard button, so we connect to the
    // "accepted" mtehod on the QDialogButtonBox
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &ConnectToDialog::connectButtonPressed);
}

ConnectToDialog::~ConnectToDialog()
{
    delete ui;
}

void ConnectToDialog::connectButtonPressed() {

    // Grab values from dialog and cast
    // Note: Once again, there is no error correction to save time

    QHostAddress address = QHostAddress(ui->ipAddressLineEdit->text().trimmed());
    quint64 port = (quint64)ui->portLineEdit->text().trimmed().toUInt();

    // Emit the signal
    emit userIntendsConnection(address, port);
}

void ConnectToDialog::processPendingDatagrams()
{
    QByteArray datagram;
    while (udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        udpSocket->readDatagram(datagram.data(), datagram.size());
        if (options.indexOf(datagram.data()) == -1) {
            options.push_back(datagram.data());
            QString DataAsString = QString(datagram);
            QStringList list = DataAsString.split(" ");
            addEntry(list[0], list[1]);
        }
    }
}

void ConnectToDialog::addEntry(QString IP_name, QString portName) {
    qDebug() << "Adding new task";
    Entry* entry = new Entry(IP_name, portName);
    mEntries.append(entry);
    ui->entriesLayout->insertWidget(0, entry);
    index++;
    connect(entry, &Entry::userChose, this, &ConnectToDialog::userChoice);
}

void ConnectToDialog::userChoice(Entry* entry) {
    ui->ipAddressLineEdit->setText(entry->IP);
    ui->portLineEdit->setText(entry->port);
}

