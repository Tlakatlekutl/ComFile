#include "mainwindow.h"

bool MainWindow::writeToPort(QByteArray data)
{
    int waitTimeout = 3000;

    QByteArray encoded = hammingEncode(data);

    serial.write(encoded);
    if (serial.waitForBytesWritten(waitTimeout)) {
        return true;
    } else {
        log("Timeout data writing");
        return false;
    }
}

int MainWindow::readFromPort(QByteArray &response,int timeout)
{
    int currentWaitTimeout = timeout;
        if (serial.waitForReadyRead(currentWaitTimeout)) {
            QByteArray responseData = serial.readAll();
//            while (serial.waitForReadyRead(10))
//                responseData += serial.readAll();

            bool hasEr=true;
            response = hammingDecode(responseData, hasEr);
//            response = responseData;
            if(hasEr) {
                log("fatal error in hamming decode");
                log(response);
                return 2;
            }
            return 1;

    } else {
        //error("Timeout data reading");
//        QByteArray ans("error");
        return 0;
    }
}
