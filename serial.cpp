#include "mainwindow.h"

bool MainWindow::writeToPort(QByteArray data)
{
    int waitTimeout = 3000;

    QBitArray bits(bytes.count()*8);

    // Convert from QByteArray to QBitArray
    for(int i=0; i<data.count(); ++i) {    //magic
        for(int b=0; b<8;b++) {
            bits.setBit( i*8+b, bytes.at(i)&(1<<(7-b)) );
        }
    }
    QBitArray encoded =  hammingEncode(bits);

    serial.write(data);
    if (serial.waitForBytesWritten(waitTimeout)) {
        return true;
    } else {
        error("Timeout data writing");
        return false;
    }
}

bool MainWindow::readFromPort(QByteArray &response,int timeout)
{
    int currentWaitTimeout = timeout;
        if (serial.waitForReadyRead(currentWaitTimeout)) {
            QByteArray responseData = serial.readAll();
            while (serial.waitForReadyRead(10))
                responseData += serial.readAll();

            response = responseData;
            return true;

    } else {
        //error("Timeout data reading");
//        QByteArray ans("error");
        return false;
    }
}
