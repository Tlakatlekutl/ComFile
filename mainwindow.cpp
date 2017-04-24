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
    tupoBaud = baud;
    initPort();
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
int MainWindow::Wait() {
    QByteArray response;
    if (readFromPort(response)) {
        return SelectFrame(response);
        log("Wait finish: "+ response);
    } else {
        log("timeout!");
        return -1;
    }
}

void MainWindow::on_pushButton_clicked()
{
    auto item = ui->listWidget->currentItem();
    if (item) {
        log(item->text());
        filename = item->text();
        writeToPort(FilePickFrame(filename));
        Wait();
    }

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
    first = true;
    log("Start conn... Sync baud");
    for(int tryV = 0; tryV < 10; tryV++)
    {
        if (SyncTick())
            break;
    }

    log((first)?"my state is first":" my state is second");
    if (first) {
        log("first sync");
        SyncFiles();
        Wait();
    }
    if (!first) {
        Wait();
        SyncFiles();
    }
    Wait();


}
bool MainWindow::SyncTick()
{
    qsrand(QTime::currentTime().msec());
    int syncTimeout = qrand()%(5000-100 + 1) + 100;
//    log("Rand: "+QString::number(syncTimeout));
    QByteArray response1;
    if (readFromPort(response1, syncTimeout)) {
        log("Response: " + QString(response1));
        SelectFrame(response1);
        return true;
    } else {
        QByteArray data = SyncFrame();
        writeToPort(SyncFrame());
//        log("i`m first");
        return false;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    log("strt hosting for 30 sec");
    QByteArray response;
    if (readFromPort(response, 30000)) {
        SelectFrame(response);
    } else {
        log("timeout!, no jion found");
    }
}
