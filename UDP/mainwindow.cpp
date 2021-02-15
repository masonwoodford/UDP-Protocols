#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    // Before starting the application
    bool ok = false;
    while(!ok) {
        portChoice = QInputDialog::getInt(this, "Select hosting port", "What port do you want to host your chat on? (Cancel to quit)",
                                              0, 0, 65535, 1, &ok);
    }
    if (ok) {
        network = new Network(portChoice, this);
    } else {
        exit(0);
    }

    // Create the messages
    messages = new Messages();
    // Connect our Messages model to the network
    connect(network, &Network::messageReceived, messages, &Messages::appendNetworkMessage);
    // Attach it to the list view
    ui->messagesListView->setModel(messages);

    // Connect the send button to our validation/send method
    connect(this->ui->sendButton, &QPushButton::pressed, this, &MainWindow::doCheckAndSendMessage);
    // Also connect pressing Return on our keyboard to this method
    connect(this->ui->messageEdit, &QLineEdit::returnPressed, this, &MainWindow::doCheckAndSendMessage);
    // connect the "Connect" button in our UI to the "Connect To" dialog
    connect(this->ui->connectButton, &QPushButton::pressed, this, &MainWindow::openConnectToDialog);
    // connect the "broadcastButton" in our UI to the "Broadcast" dialog
    connect(this->ui->broadcastButton, &QPushButton::pressed, this, &MainWindow::openBroadcast);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doCheckAndSendMessage() {
    // grab trimmed message from send box
    QString messageString = this->ui->messageEdit->text().trimmed();

    // check that the string isn't empty
    if (messageString.size() == 0) {
        return;
    }

    // if it is not, we continue
    // clear box
    this->ui->messageEdit->clear();

    // append to the model
    this->messages->append(messageString);

    // send over the network
    network->sendMessageToPeer(messageString);
}

void MainWindow::openConnectToDialog() {
    ConnectToDialog* connectToDialog = new ConnectToDialog();
    connect(connectToDialog, &ConnectToDialog::userIntendsConnection, network, &Network::connectToClient);
    connectToDialog->show();
}

void MainWindow::openBroadcast() {
    broadcast = new Broadcast(portChoice);
    connect(network, &Network::stopBroadcast, broadcast, &Broadcast::stopBroadcasting);
    broadcast->show();
}

