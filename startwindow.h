#ifndef StartWindow_H
#define StartWindow_H

#include <QDialog>
#include "basicinclude.h"
#include "mainwindow.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::StartWindow *ui;
};

#endif // StartWindow_H
