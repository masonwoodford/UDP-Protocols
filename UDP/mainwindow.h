#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include "messages.h"
#include "network.h"
#include "connecttodialog.h"
#include "broadcast.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QLabel;
class QUdpSocket;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int portChoice;

private:
    Ui::MainWindow *ui;
    Messages* messages;
    Network* network;
    Broadcast* broadcast;

private slots:
    void doCheckAndSendMessage();
    void openConnectToDialog();
    void openBroadcast();
};
#endif // MAINWINDOW_H
