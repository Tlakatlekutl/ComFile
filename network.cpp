#include "mainwindow.h"

QByteArray MainWindow::SyncFrame() {
    return QByteArray("\x01"+QByteArray::number(tupoBaud));
}

//    QByteArray BaudFrame(int speed);
QByteArray MainWindow::OKframe() {
    return QByteArray("\x42OK");
}

int MainWindow::SelectFrame(QByteArray frame) {
    char type = frame[0];
    switch (type) {
    case '\x42':
        log("OK frame recived");
        return 1;
    case '\x01':
        log("Syncframe recived");
        ParseBaud(frame.mid(1));
        return 2;
    case '\x02':
        log("FileList recived: "+ frame);
        ShowFileLists(frame.mid(1));
        writeToPort(OKframe());
        return 3;
    case '\x03':
        log("PickFileFrame recived");
        StartFileSending(QString::fromUtf8(frame.mid(1)));
        return 4;
    case '\x04':
        log("FileinfoFrame recived");
        FileDownload(frame.mid(1).toInt());
        return 5;
    case '\x07':
        log("Клиент разорвал соединение");
        return 6;
    default:
        log("unknown frame recived: " + QString::number(type));
        return 0;
    }
}
void MainWindow::ParseBaud(QByteArray baudB) {
     int recivedBaud = baudB.toInt();
     if (recivedBaud < tupoBaud) {
         tupoBaud = recivedBaud;
         log("Change baud to"+ QString::number(tupoBaud));
         // here change baud;;
         writeToPort(SyncFrame());
     } else if (recivedBaud > tupoBaud) {
         log("Send baud"+ QString::number(tupoBaud));
         writeToPort(SyncFrame());
         first = false;
     } else {
         log("Sync Complete"+ QString::number(tupoBaud));
         first = false;
         writeToPort(OKframe());
     }


}
