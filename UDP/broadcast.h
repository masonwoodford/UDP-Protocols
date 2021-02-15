#ifndef BROADCAST_H
#define BROADCAST_H

#include <QDialog>
#include <QTimer>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui {
class Broadcast;
}
class QLabel;
class QPushButton;
class QUdpSocket;
QT_END_NAMESPACE

class Broadcast : public QDialog
{
    Q_OBJECT

public:
    explicit Broadcast(int portChoice, QWidget *parent = nullptr);
    ~Broadcast();
    int portChoice;

public slots:
    void stopBroadcasting();

private:
    Ui::Broadcast *ui;
    QUdpSocket *udpSocket = nullptr;
    QTimer timer;
    bool shouldBroadcast = true;
    int i = 0;
    int TCPPort = 45454;

private slots:
    void broadcastDatagram();
    void startBroadcasting();
};

#endif // BROADCAST_H
