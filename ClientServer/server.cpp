#include "server.h"
#include "ui_server.h"

#include <QString>
#include <QFile>
#include <QObject>
#include <QTextStream>
#include <QTcpServer>
#include <QUdpSocket>
#include <QTcpSocket>
#include <QFileSystemModel>
#include <QTreeView>
#include <QDesktopWidget>
#include <QNetworkInterface>


Server::Server(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Server)
{
    ui->setupUi(this);
    QList<QHostAddress> list = QNetworkInterface::allAddresses();

     for(int nIter=0; nIter<list.count(); nIter++)

      {
          if(!list[nIter].isLoopback())
              if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol )
              {
                 QString temp = QString("SERVIDOR - IP: ") + list[nIter].toString();
                 QByteArray ba = temp.toLocal8Bit();
                 const char *c_str2 = ba.data();
                 QWidget::setWindowTitle(  c_str2 );
              }
      }

    QMessageBox mBox;
    mBox.setWindowTitle("Protocolo");
    mBox.setText("Selecione o protocolo:");
    QAbstractButton *tcp = mBox.addButton(QString("TCP"), QMessageBox::ActionRole );
    mBox.addButton(QString("UDP"), QMessageBox::ActionRole );
    mBox.exec();

    if (  mBox.clickedButton() == tcp )
    {
        servidor = new QTcpServer(this);
        socket = new QTcpSocket(this);
        //auto temp = dynamic_cast<QTcpServer*>(servidor);
        QObject::connect(dynamic_cast<QTcpServer*>(servidor), &QTcpServer::newConnection,[&](){socket =
        dynamic_cast<QTcpServer*>(servidor)->nextPendingConnection();} );
    }
    else
    {
        servidor = new QUdpSocket(this);
    }
}

void Server::enviaDado(const QString &data )
{
    if(socket)
    {
        QTextStream T(socket);
        T << data;
        socket->flush();
    }
}

Server::~Server()
{
    if(socket != nullptr ) delete socket;
    delete servidor;
    delete ui;
}

void Server::on_conectarButton_clicked()
{
    auto temp = dynamic_cast<QTcpServer*>(servidor);
    if(temp != nullptr )
    {
        if(temp->isListening())
        {
            temp->close();
        }
        QString porta;
        porta = QString("Conectado a porta ") + QString::number(ui->portaBox->value()) + QString("!");
        if(!temp->listen(QHostAddress::Any, ui->portaBox->value())) QMessageBox::critical(this, "Error", temp->errorString());
        else QMessageBox::information(this,"Servidor", porta);
    }
    else
    {
       QMessageBox::warning(this,"Aviso","UDP não precisa de conexão!");
    }
}

void Server::on_enviarButton_clicked()
{
    auto temp = dynamic_cast<QTcpServer *>(servidor);
    if(temp != nullptr)
    {
        if(temp->isListening())enviaDado(ui->lineEdit->text());
        else  QMessageBox::critical(this,"Erro","Conecte-se a uma porta primeiro!");
    }
    else
    {
        auto datagrama = ui->lineEdit->text().toLatin1();
        dynamic_cast<QUdpSocket *>(servidor)->writeDatagram(datagrama, QHostAddress::Broadcast,ui->portaBox->value());
    }
}
