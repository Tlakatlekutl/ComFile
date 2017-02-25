#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "basicinclude.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString portName, QSerialPort::BaudRate baud, QWidget *parent = 0);
    void log(QString msg);
    void error(QString error);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString portName;
    QSerialPort::BaudRate baud;
    QSerialPort serial;
    void initPort();
    void hello(); // sync conn and check
    void syncFiles();
    void download(QString filename);
    void closeConn();
    bool writeToPort(QByteArray data);
    bool readFromPort(QByteArray &response, int timeout = 3000);
    QByteArray hammingEncode(const QByteArray&);
    QByteArray hammingDecode(const QByteArray&, bool);

};

#endif // MAINWINDOW_H
