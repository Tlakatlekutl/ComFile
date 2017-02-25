#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTime>

MainWindow::MainWindow(QString portName, QSerialPort::BaudRate baud, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    portName(portName),
    baud(baud)
{
    ui->setupUi(this);
    /*initPort();*/       // start connection
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::log(QString msg)
{
    ui->logArea->append(msg);
}
void MainWindow::error(QString error)
{
    QMessageBox::critical(this,  "Error", error);
    ui->logArea->append("Error: "+error);
}

void MainWindow::on_pushButton_clicked()
{
    initPort();
}
void MainWindow::initPort()
{
    log("Starting programm...");
    log("init port with COM="+portName+" and baud rate: "+QString::number(baud));
    serial.setPortName(portName);
    serial.setBaudRate(QSerialPort::Baud1200);
    serial.setFlowControl(QSerialPort::NoFlowControl);


    if (!serial.open(QIODevice::ReadWrite)) {
        log("!!! error opening port !!!");
        this->close();                      //Add modal error
    }
    log("Start conn... Sync baud");

    qsrand(QTime::currentTime().msec());
    int syncTimeout = qrand()%(5000-100 + 1) + 100;
    log("Rand: "+QString::number(syncTimeout));
    QByteArray response1;
    if (readFromPort(response1, syncTimeout)) {
        log("Response: " + QString(response1));
    } else {
        writeToPort(QByteArray("hello"));
        log("i`m first");
    }
}
