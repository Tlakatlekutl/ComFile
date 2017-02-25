/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
        StartWindow->resize(196, 187);
        pushButton = new QPushButton(StartWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 150, 75, 23));
        SerialPortComboBox = new QComboBox(StartWindow);
        SerialPortComboBox->setObjectName(QStringLiteral("SerialPortComboBox"));
        SerialPortComboBox->setGeometry(QRect(100, 50, 69, 22));
        BaudComboBox = new QComboBox(StartWindow);
        BaudComboBox->setObjectName(QStringLiteral("BaudComboBox"));
        BaudComboBox->setGeometry(QRect(100, 90, 69, 22));
        SerialPortLabel = new QLabel(StartWindow);
        SerialPortLabel->setObjectName(QStringLiteral("SerialPortLabel"));
        SerialPortLabel->setGeometry(QRect(40, 55, 47, 13));
        QFont font;
        font.setPointSize(12);
        SerialPortLabel->setFont(font);
        BaudLabel = new QLabel(StartWindow);
        BaudLabel->setObjectName(QStringLiteral("BaudLabel"));
        BaudLabel->setGeometry(QRect(40, 96, 47, 13));
        BaudLabel->setFont(font);
        SettingsLabel = new QLabel(StartWindow);
        SettingsLabel->setObjectName(QStringLiteral("SettingsLabel"));
        SettingsLabel->setGeometry(QRect(70, 10, 71, 31));
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
        SerialPortLabel->setText(QApplication::translate("StartWindow", "Port", Q_NULLPTR));
        BaudLabel->setText(QApplication::translate("StartWindow", "Baud", Q_NULLPTR));
        SettingsLabel->setText(QApplication::translate("StartWindow", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
