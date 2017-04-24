#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>

void MainWindow::SyncFiles() {
    QDir d("./files");
    log(d.absolutePath());
    QStringList filesList = d.entryList(QDir::Files);
    QString filesString = filesList.join(';')+";file0.txt";
        writeToPort(FilelistFrame(filesString));
        log("File string: " + filesString);
}

QByteArray MainWindow::FilelistFrame(QString fl) {
    return QByteArray("\x02" + fl.toUtf8());
}

void MainWindow::ShowFileLists(QByteArray fileList) {
    QString fileStr = QString::fromUtf8(fileList);
    QStringList files = fileStr.split(';');
    ui->listWidget->addItems(files);
}
