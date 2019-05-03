#include "client.h"
#include "ui_client.h"

#include <QMessageBox>
#include <QAbstractButton>
#include <QPushButton>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QNetworkInterface>

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
    ui->setupUi(this);
    QMessageBox mBox;
    mBox.setWindowTitle("Protocolo");
    mBox.setText("Selecione o protocolo:");
    QAbstractButton *tcp = mBox.addButton(QString("TCP"), QMessageBox::ActionRole );
    mBox.addButton(QString("UDP"), QMessageBox::ActionRole );
    mBox.exec();
    if (  mBox.clickedButton() == tcp )
    {
        socket = new QTcpSocket(this);
        connect(socket, &QTcpSocket::readyRead, [&](){
            QTextStream T(socket);
            ui->listWidget->addItem(T.readAll());});
}
    else
    {
        socket = new QUdpSocket(this);
            connect(socket, &QUdpSocket::readyRead, [&](){
                   if(dynamic_cast<QUdpSocket *>(socket)->hasPendingDatagrams())
                   {
                        QByteArray datagrama;
                        datagrama.resize(dynamic_cast<QUdpSocket *>(socket)->pendingDatagramSize());
                        dynamic_cast<QUdpSocket *>(socket)->readDatagram(datagrama.data(), datagrama.size());
                        ui->listWidget->addItem(QString(datagrama));
                    }
            }
            );
        ui->lineEdit->setText("Sem IP");
        ui->lineEdit->setReadOnly(true);
                
    }
}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButton_3_clicked()
{
    auto temp = dynamic_cast<QTcpSocket *>(socket);
    if(temp != nullptr)
    {
       if(temp->isOpen())
       {
           temp->close();
       }
       QString porta;
       porta = QString("Porta: ") + QString::number(ui->spinBox->value()) + QString("\n") + QString("IP: ");
       QList<QHostAddress> list = QNetworkInterface::allAddresses();
       if( ui->lineEdit->text() == QString("localhost"))
       {
            for(int nIter=0; nIter<list.count(); nIter++)

             {
                 if(!list[nIter].isLoopback())
                  {   if (list[nIter].protocol() == QAbstractSocket::IPv4Protocol )
                     {
                         porta += list[nIter].toString();
                     }
                 }
             }
       }
       else porta += ui->lineEdit->text();



       temp->connectToHost(ui->lineEdit->text(), ui->spinBox->value());
       QMessageBox::information(this,"Conexão", porta);
    }
    else
    {
        if (dynamic_cast<QUdpSocket *>(socket)->isOpen()) dynamic_cast<QUdpSocket *>(socket)->close();
        dynamic_cast<QUdpSocket *>(socket)->bind(  ui->spinBox->value(), QUdpSocket::ShareAddress);
        QMessageBox::information(this,"Conexão", (QString("Porta: ") + QString::number(ui->spinBox->value())));
    }
}
