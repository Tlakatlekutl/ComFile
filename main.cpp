#include "startwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    system("chcp 866");
//    setlocale(LC_ALL, "Russian");
    QApplication a(argc, argv);
    StartWindow w;
    w.show();

    return a.exec();
}
