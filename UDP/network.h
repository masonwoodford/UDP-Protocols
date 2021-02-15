#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <vector>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(quint64 port, QObject *parent = nullptr);

private:
    QTcpServer* server;
    QTcpSocket* peerSocket;
    std::vector<char> buffer;
    void didConnect();

signals:
    void messageReceived(QString message, QString peerAddressString);
    void stopBroadcast();

public slots:
    void connectToClient(QHostAddress address, quint64 port);
    void sendMessageToPeer(QString message);

private slots:
    void didReceiveClientConnection();
    void didReceiveData();

};

#endif // NETWORK_H
