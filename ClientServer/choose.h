#ifndef CHOOSE_H
#define CHOOSE_H

#include <QMainWindow>
#include <server.h>
#include <client.h>

namespace Ui
{
    class Choose;
}

class Choose : public QMainWindow
{
    Q_OBJECT

public:
    explicit Choose(bool isServer, QWidget *parent = nullptr);
    ~Choose();

private slots:
    void on_pushButton_clicked();

    void on_tcpButton_clicked();

    void on_tcpButton_clicked(bool checked);

private:
    Ui::Choose *ui;
    Server *servidor;
    Client *cliente;
    bool _isServer;
};

#endif // CHOOSE_H
