/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *bienvenidos;
    QPushButton *pushButton_Comenzar;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(380, 240);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        bienvenidos = new QLabel(centralWidget);
        bienvenidos->setObjectName(QStringLiteral("bienvenidos"));
        bienvenidos->setGeometry(QRect(80, 40, 231, 71));
        bienvenidos->setAlignment(Qt::AlignCenter);
        bienvenidos->setWordWrap(false);
        pushButton_Comenzar = new QPushButton(centralWidget);
        pushButton_Comenzar->setObjectName(QStringLiteral("pushButton_Comenzar"));
        pushButton_Comenzar->setGeometry(QRect(140, 110, 100, 50));
        pushButton_Comenzar->setLayoutDirection(Qt::LeftToRight);
        pushButton_Comenzar->setIconSize(QSize(32, 32));
        pushButton_Comenzar->setAutoRepeatDelay(300);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 380, 21));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(pushButton_Comenzar, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "M\303\241quina de Turing", Q_NULLPTR));
        bienvenidos->setText(QApplication::translate("MainWindow", "Bienvenidos al Simulador de M\303\241quina de Turing ", Q_NULLPTR));
        pushButton_Comenzar->setText(QApplication::translate("MainWindow", "Comenzar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
