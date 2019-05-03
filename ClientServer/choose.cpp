#include "choose.h"
#include "ui_choose.h"

Choose::Choose(bool isServer, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Choose)
{
    ui->setupUi(this);

    _isServer = isServer;

    if( _isServer )
    {
         cliente = nullptr;
         servidor = new Server();
         servidor->hide();
    }
    else
    {
        servidor = nullptr;
        cliente = new Client();
        cliente->hide();
    }

}

Choose::~Choose()
{
    delete servidor;
    delete cliente;
    delete ui;
}

void Choose::on_pushButton_clicked()
{

    if( ui->radioButton  )
    this->hide();
    if(_isServer) servidor->show();
    else cliente->show();
}

