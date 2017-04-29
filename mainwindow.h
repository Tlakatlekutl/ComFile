#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBitArray>
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

    void on_pushButton_2_clicked();

private:
    bool first;
    void closeEvent(QCloseEvent *event);
    Ui::MainWindow *ui;
    QString portName;
    QSerialPort::BaudRate baud;
    QSerialPort serial;
    int tupoBaud = 2400;
    void initPort();
    void hello(); // sync conn and check
    void syncFiles();
    void download(QString filename);
    void closeConn();
    void print(QBitArray array);
    bool writeToPort(QByteArray data);
    int readFromPort(QByteArray &response, int timeout = 3000);
    QByteArray hammingEncode( const QByteArray&);
    QByteArray hammingDecode(const QByteArray&, bool&);
    bool SyncTick();
    QByteArray SyncFrame();
//    QByteArray BaudFrame(int speed);
    QByteArray OKframe();
    int SelectFrame(QByteArray);
    void ParseBaud(QByteArray);
    void SyncFiles();
    QByteArray FilelistFrame(QString);
    void ShowFileLists(QByteArray);
    int Wait();
    QByteArray FilePickFrame(QString filename);
    void StartFileSending(QString);
    QByteArray FilePartFrame(QByteArray);
    QByteArray FileInfoFrame(int);
    void FileDownload(int);
    QString filename;
};

#endif // MAINWINDOW_H
