#include "entry.h"
#include "ui_entry.h"

#include "entry.h"
#include "ui_entry.h"
#include "connecttodialog.h"

Entry::Entry(QString IP_name, QString portName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Entry)
{
    this->IP = IP_name;
    this->port = portName;
    ui->setupUi(this);
    setIP(IP_name);
    setPort(portName);
    connect(ui->IP, &QPushButton::clicked, this, &Entry::IPButtonPressed);
    connect(ui->Port, &QPushButton::clicked, this, &Entry::IPButtonPressed);
    connect(ui->IP_ph, &QPushButton::clicked, this, &Entry::IPButtonPressed);
    connect(ui->Port_ph, &QPushButton::clicked, this, &Entry::IPButtonPressed);
}

Entry::~Entry()
{
    delete ui;
}

void Entry::setIP(QString IP_name) {
    ui->IP->setText(IP_name);
}

void Entry::setPort(QString portName) {
    ui->Port->setText(portName);
}

void Entry::IPButtonPressed() {
    emit userChose(this);
}
