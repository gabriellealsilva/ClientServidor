#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QObject>
#include <QAbstractSocket>

namespace Ui {

class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:

    void on_pushButton_3_clicked();

private:
    Ui::Client *ui;
    QAbstractSocket *socket;
};

#endif // CLIENT_H
