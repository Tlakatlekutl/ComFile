#include "startwindow.h"
#include "ui_StartWindow.h"



StartWindow::StartWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos)
        ui->SerialPortComboBox->addItem(info.portName());

    ui->BaudComboBox->addItem("1200", QSerialPort::Baud1200);
    ui->BaudComboBox->addItem("2400", QSerialPort::Baud2400);
    ui->BaudComboBox->addItem("4800", QSerialPort::Baud4800);
    ui->BaudComboBox->addItem("9600", QSerialPort::Baud9600);
    ui->BaudComboBox->addItem("19200", QSerialPort::Baud19200);
    ui->BaudComboBox->addItem("38400", QSerialPort::Baud38400);
    ui->BaudComboBox->addItem("57600", QSerialPort::Baud57600);
    ui->BaudComboBox->addItem("115200", QSerialPort::Baud115200);
    ui->BaudComboBox->setCurrentIndex(6);

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
    MainWindow *window = new MainWindow(
                ui->SerialPortComboBox->currentText(),
                ui->BaudComboBox->currentData().value<QSerialPort::BaudRate>());
    window->show();
    this->close();
}
