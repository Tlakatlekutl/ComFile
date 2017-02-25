#include "mainwindow.h"

bool MainWindow::writeToPort(QByteArray data)
{
    int waitTimeout = 3000;

    QByteArray encoded =  hammingEncode(data);

    serial.write(encoded);
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

            bool hasEr;
            response = hammingDecode(responseData, hasEr);
            if(!hasEr)
                log("fatal error in hamming decode");
            return true;

    } else {
        //error("Timeout data reading");
//        QByteArray ans("error");
        return false;
    }
}
