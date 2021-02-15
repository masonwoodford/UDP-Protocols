#include "network.h"
#include "broadcast.h"

Network::Network(quint64 port, QObject *parent) : QObject(parent)
{
    // initialize server
    this->server = new QTcpServer(this);

    // ask the server to listen
    // if it cannot listen, something out of our control went wrong, and we should exit.
    if (!server->listen(QHostAddress::AnyIPv4, port)) {
        qDebug() << "Could not initalize Network layer server, exiting";
        // server->close();
        exit(-1);
    }

    connect(server, &QTcpServer::newConnection, this, &Network::didReceiveClientConnection);
}

void Network::didReceiveClientConnection() {
    qDebug() << "did receive client conn";

    // set peer socket
    peerSocket = this->server->nextPendingConnection();

    didConnect();
    emit stopBroadcast();
    // close the server
    // this will prevent any further connections
    server->close();


}

void Network::connectToClient(QHostAddress address, quint64 port) {
    // close our server for incoming connections, since we are starting an outgoing connection.
    // Note: there is no error checking here, so this assumes we input a valid and active IP and port.
    server->close();

    // create a new peerSocket
    this->peerSocket = new QTcpSocket();

    qDebug() << "Attempting outgoing connection";
    peerSocket->connectToHost(address, port);
    didConnect(); // no error checking
}

void Network::didReceiveData() {
    // read all available data from socket and append to buffer
    // 1
    while(peerSocket->bytesAvailable()) {
        // read and analyze the byte being sent
        //2
        char c;
        peerSocket->getChar(&c);
        if (c == '\n') {

            // 3
            // we've reached a message break

            // Null terminate our buffer
            buffer.push_back('\0');

            // flush the buffer out as a C-style char* string
            char* message_char_arr = buffer.data();

            // cast our message into a QString, and grab the peer address
            emit messageReceived(QString(message_char_arr), peerSocket->peerAddress().toString());

            // clear the buffer
            buffer.clear();
        } else {
            // 4
            buffer.push_back(c);
        }
    }
}

void Network::didConnect() {
    // Establish a connection to let us know when data is available to read
    connect(peerSocket, &QTcpSocket::readyRead, this, &Network::didReceiveData);
}

void Network::sendMessageToPeer(QString message) {
    if (peerSocket != nullptr) {
        // prepare message for sending by appending return
        message.append('\n');

        // grab the data from the QString, in the form of QData*
        const QChar* data = message.constData();
        const int messageDataSize = message.size();

        // allocate a char* to hold our message
        char* messageCharArr = (char*)calloc(messageDataSize, sizeof(char));

        // copy character by character from our data to our char* array
        for (int i =0; i < messageDataSize; i++) {
            messageCharArr[i] = data[i].toLatin1();
        }
        // write out our message to the peer socket
        peerSocket->write(messageCharArr, messageDataSize);

        // deallocate array (to avoid memory leaks)
        free(messageCharArr);
    }
}
