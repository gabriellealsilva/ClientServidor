#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    if(escolha != nullptr) delete escolha;
    delete ui;
}

void MainWindow::on_serverButton_clicked()
{
    escolha = new Server();
    this->hide();
    escolha->show();
}

void MainWindow::on_clientButton_clicked()
{
    escolha = new Client();
    this->hide();
    escolha->show();
}
