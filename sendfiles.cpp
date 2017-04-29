#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>


QByteArray MainWindow::FilePickFrame(QString filename) {
    return QByteArray("\x03" + filename.toUtf8());
}
void MainWindow::StartFileSending(QString filename) {
    QFile file("./files/"+filename);
    if (file.exists()) {
        log("Success file founding");
        file.open(QIODevice::ReadOnly);
        QByteArray filecontent = file.readAll();
        file.close();
        int count = filecontent.size()%64+1;  // size of file frame 64 byte
        writeToPort(FileInfoFrame(count));

        log("Split file to " + QString::number(count));
        int offset = 0;
        int cycles = 0;
        for (int i = 0; i < count;) {
            cycles++;
            QByteArray part = filecontent.mid(offset, 64);
            writeToPort(FilePartFrame(part));
            QByteArray response;
            readFromPort(response);
            if (response[0] == '\x42') {
                log("total offset: " + QString::number(offset));
                offset +=64;
                i++;
            } else if (response[0] == '\x06') {
                log("Repeat send file frame");
            }
            if (cycles > 40) {
                log("ERROR somthing was wrong");
                break;
            }
        }
    } else {
        log("error file opening. File does nor exists");
    }

}

QByteArray MainWindow::FileInfoFrame(int count) {
    return QByteArray("\x04"+QByteArray::number(count));
}

QByteArray MainWindow::FilePartFrame(QByteArray part) {
    return QByteArray("\x05"+ part);
}

void MainWindow::FileDownload(int count) {
    log("start file downloading...");
    log("Count tick: " + QString::number(count));
    QByteArray fileBytes;
    ui->progressBar->setValue(0);
    for (int i = 0; i < count; i++) {
        int progress = (i*100)/count;
        ui->progressBar->setValue(progress);
        log("value: " + QString::number(progress));
        QByteArray part;
        int status = readFromPort(part);
        if (status == 1) {
            log("tick "+ QString::fromUtf8(part));
            if (part[0] == '\x05') {
                log("append");
                fileBytes.append(part.mid(1));
                writeToPort(OKframe());
            }
        } else if (status == 2) {
            writeToPort(QByteArray("\x06"));
        } else {
            log("timeout file part waiting");
            return; //  ??
        }
    }
    ui->progressBar->setValue(100);

    if (filename == "")
        log("filename error");
    QFile file(filename);
    file.open(QIODevice::WriteOnly);
    file.write(fileBytes);
    file.close();
    log("Download Completed!");
}
