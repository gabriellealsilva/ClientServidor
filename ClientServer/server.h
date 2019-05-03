#ifndef SERVER_H
#define SERVER_H

#include <QMainWindow>

#include <QAbstractSocket>
#include <QMessageBox>
#include <QObject>
#include <QFile>

#include <QString>
#include <QTextStream>

class QAbstractSocket;

namespace Ui
{
    class Server;
}

class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();
    void enviaDado(const QString &dado);

private slots:
    void on_conectarButton_clicked();

    void on_enviarButton_clicked();

private:
    Ui::Server *ui;
    QObject *servidor;
    QAbstractSocket *socket;
};

#endif // SERVER_H
