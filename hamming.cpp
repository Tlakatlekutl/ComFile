#include "mainwindow.h"
#include <QBitArray>
#include <QDebug>

void MainWindow::print(QBitArray array){
    QString ans;
    for (int i = 0; i < array.count(); i++)
    {
        ans.append((array.at(i)?"1":"0"));
    }
    log(ans);
}

QByteArray MainWindow::hammingEncode(const QByteArray &input)
{

    QBitArray temp(8);
    QBitArray hamT(14);
    QBitArray output(input.count()*14);
//    temp.fill(0);
    hamT.fill(0);
//    output.fill(0);
//    error(QString::number(input.count()*14));

    // Convert from QByteArray to QBitArray

    log("get:" + QString(input.toHex()));

    for(int i=0; i<input.count(); ++i) {    //magic
        for(int b=0; b<8;b++) {
            temp.setBit(b, input.at(i)&(1<<(7-b)));

        }
        log("bin input");
        print(temp);
//        error("1");

        int pos = 4;
        hamT[13] = temp[pos + 3];
        hamT[12] = temp[pos + 2];
        hamT[11] = temp[pos + 1];
        hamT[10] = hamT[6+7]^hamT[5+7]^hamT[4+7];
        hamT[9] = temp[pos+0];
        hamT[8] = hamT[6+7]^hamT[5+7]^hamT[2+7];
        hamT[7] = hamT[6+7]^hamT[4+7]^hamT[2+7];
        pos=0;
        hamT[6] = temp[pos + 3];
        hamT[5] = temp[pos + 2];
        hamT[4] = temp[pos + 1];
        hamT[3] = hamT[6]^hamT[5]^hamT[4];
        hamT[2] = temp[pos+0];
        hamT[1] = hamT[6]^hamT[5]^hamT[2];
        hamT[0] = hamT[6]^hamT[4]^hamT[2];
        log("middle bin");
        print(hamT);

        for (int b = 0; b < 14; ++b) {
            output[i*14+b] = hamT[b];
        }

    }
    log("finnals bin");
    print(output);
    QByteArray bytes;
    bytes.resize(output.count()/8+1);
    bytes.fill(0);
    // Convert from QBitArray to QByteArray

    for(int b=0; b<output.count();++b) {
        bytes[b/8] = (bytes.at(b/8) | ((output[b]?1:0)<<(7-(b%8))));
    }
    log("return bytes");
    log(QString(bytes.toHex()));
    return bytes;
}

QByteArray MainWindow::hammingDecode(const QByteArray &input, bool &hasErrors)
{
    QBitArray temp(8);
    QBitArray hamT(7);
    QBitArray output(input.count()*8);
    log("---------------");
    // Convert from QByteArray to QBitArray

    for(int i=0; i<input.count(); ++i) {    //magic
        for(int b=0; b<8; b++) {
            output.setBit( i*8+b, input.at(i)&(1<<(7-b)) );
        }
    }
//    error("1");
    log("bin code in");
    print(output);
    QBitArray result(output.size()*4/7-input.count()/2); // Супер магический костыль ВАТАФАК


    for (int i=0; i < output.size()/14; i++)
    {
//        error("2");
        result[i*8+7] = output[i*14+13];
        result[i*8+6] = output[i*14+12];
        result[i*8+5] = output[i*14+11];
        result[i*8+4] = output[i*14+9];
        result[i*8+3] = output[i*14+6];
        result[i*8+2] = output[i*14+5];
        result[i*8+1] = output[i*14+4];
          result[i*8] = output[i*14+2];

        log("result and output: "+QString::number(i));
        print(output);
        print(result);
//        bool ch1 = (((output[i+13]^output[i+12])^output[i+11]) == output[i+10]);
//        bool ch2 = (((output[i+13]^output[i+12])^output[i+9]) == output[i+8]);
//        bool ch3 = (((output[i+13]^output[i+11])^output[i+9]) == output[i+7]);
//        bool ch4 = (((output[i+6]^output[i+5])^output[i+4]) == output[i+3]);
//        bool ch5 = (((output[i+6]^output[i+5])^output[i+2]) == output[i+1]);
//        bool ch6 = (((output[i+6]^output[i+4])^output[i+2]) == output[i]);
//        if (ch1 && ch2 && ch3 &&ch4&&ch5&&ch6)
            hasErrors = false;
//        else {
//            hasErrors = true;
//            log("hamming has errors!");
//        }
//        error("3");
    }
    QByteArray bytes;
    bytes.resize(result.count()/8);
    log("params");
    log(QString::number(result.count()));
    bytes.fill(0);

    error("4");
    // Convert from QBitArray to QByteArray
    for(int b=0; b<result.count();++b) {
        bytes[b/8] = (bytes.at(b/8) | ((result[b]?1:0)<<(7-(b%8))));
    }
//    error("5");
    return bytes;
}
