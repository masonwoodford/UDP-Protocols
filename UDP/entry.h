#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>

namespace Ui {
class Entry;
}

class Entry : public QWidget
{
    Q_OBJECT

public:
    explicit Entry(QString IP_name, QString portName, QWidget *parent = nullptr);
    ~Entry();
    void setIP(QString IP_name);
    QString IP_name() const;
    void setPort(QString portName);
    QString portName() const;
    QString IP;
    QString port;

private:
    Ui::Entry *ui;
    void IPButtonPressed();

signals:
    void userChose(Entry* entry);

};
#endif // ENTRY_H
