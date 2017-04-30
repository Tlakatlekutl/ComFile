/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *pushButton;
    QComboBox *SerialPortComboBox;
    QComboBox *BaudComboBox;
    QLabel *SerialPortLabel;
    QLabel *BaudLabel;
    QLabel *SettingsLabel;

    void setupUi(QDialog *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(237, 221);
        pushButton = new QPushButton(StartWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(80, 180, 81, 23));
        SerialPortComboBox = new QComboBox(StartWindow);
        SerialPortComboBox->setObjectName(QStringLiteral("SerialPortComboBox"));
        SerialPortComboBox->setGeometry(QRect(150, 70, 69, 22));
        BaudComboBox = new QComboBox(StartWindow);
        BaudComboBox->setObjectName(QStringLiteral("BaudComboBox"));
        BaudComboBox->setGeometry(QRect(150, 110, 69, 22));
        SerialPortLabel = new QLabel(StartWindow);
        SerialPortLabel->setObjectName(QStringLiteral("SerialPortLabel"));
        SerialPortLabel->setGeometry(QRect(20, 69, 71, 20));
        QFont font;
        font.setPointSize(11);
        SerialPortLabel->setFont(font);
        BaudLabel = new QLabel(StartWindow);
        BaudLabel->setObjectName(QStringLiteral("BaudLabel"));
        BaudLabel->setGeometry(QRect(20, 110, 121, 20));
        BaudLabel->setFont(font);
        SettingsLabel = new QLabel(StartWindow);
        SettingsLabel->setObjectName(QStringLiteral("SettingsLabel"));
        SettingsLabel->setGeometry(QRect(30, 10, 171, 31));
        QFont font1;
        font1.setPointSize(14);
        SettingsLabel->setFont(font1);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QDialog *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Settings", Q_NULLPTR));
        pushButton->setText(QApplication::translate("StartWindow", "OK", Q_NULLPTR));
        SerialPortLabel->setText(QApplication::translate("StartWindow", "\320\237\320\276\321\200\321\202", Q_NULLPTR));
        BaudLabel->setText(QApplication::translate("StartWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 (\320\261\320\276\320\264)", Q_NULLPTR));
        SettingsLabel->setText(QApplication::translate("StartWindow", "\320\224\320\276\320\261\321\200\320\276 \320\277\320\276\320\266\320\260\320\273\320\276\320\262\320\260\321\202\321\214!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
