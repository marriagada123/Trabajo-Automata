/********************************************************************************
** Form generated from reading UI file 'secondwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECONDWINDOW_H
#define UI_SECONDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SecondWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Confirmar;
    QTextBrowser *textBrowser_Mostrar;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_Est_Ini;
    QLabel *label_Est_Fin;
    QLabel *label_Trans;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_Est_Ini;
    QLabel *label_Asterisco1;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_Est_Fin;
    QLabel *label_Asterisco2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_Trans;
    QLabel *label_Asterisco3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SecondWindow)
    {
        if (SecondWindow->objectName().isEmpty())
            SecondWindow->setObjectName(QStringLiteral("SecondWindow"));
        SecondWindow->resize(371, 316);
        centralwidget = new QWidget(SecondWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton_Confirmar = new QPushButton(centralwidget);
        pushButton_Confirmar->setObjectName(QStringLiteral("pushButton_Confirmar"));
        pushButton_Confirmar->setGeometry(QRect(250, 130, 75, 23));
        textBrowser_Mostrar = new QTextBrowser(centralwidget);
        textBrowser_Mostrar->setObjectName(QStringLiteral("textBrowser_Mostrar"));
        textBrowser_Mostrar->setGeometry(QRect(70, 180, 251, 81));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(56, 42, 276, 82));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_Est_Ini = new QLabel(widget);
        label_Est_Ini->setObjectName(QStringLiteral("label_Est_Ini"));

        verticalLayout->addWidget(label_Est_Ini);

        label_Est_Fin = new QLabel(widget);
        label_Est_Fin->setObjectName(QStringLiteral("label_Est_Fin"));

        verticalLayout->addWidget(label_Est_Fin);

        label_Trans = new QLabel(widget);
        label_Trans->setObjectName(QStringLiteral("label_Trans"));

        verticalLayout->addWidget(label_Trans);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_Est_Ini = new QLineEdit(widget);
        lineEdit_Est_Ini->setObjectName(QStringLiteral("lineEdit_Est_Ini"));
        lineEdit_Est_Ini->setLayoutDirection(Qt::RightToLeft);
        lineEdit_Est_Ini->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(lineEdit_Est_Ini);

        label_Asterisco1 = new QLabel(widget);
        label_Asterisco1->setObjectName(QStringLiteral("label_Asterisco1"));
        label_Asterisco1->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_Asterisco1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_Asterisco1);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_Est_Fin = new QLineEdit(widget);
        lineEdit_Est_Fin->setObjectName(QStringLiteral("lineEdit_Est_Fin"));
        lineEdit_Est_Fin->setLayoutDirection(Qt::RightToLeft);
        lineEdit_Est_Fin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEdit_Est_Fin);

        label_Asterisco2 = new QLabel(widget);
        label_Asterisco2->setObjectName(QStringLiteral("label_Asterisco2"));
        label_Asterisco2->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_Asterisco2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_Asterisco2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_Trans = new QLineEdit(widget);
        lineEdit_Trans->setObjectName(QStringLiteral("lineEdit_Trans"));
        lineEdit_Trans->setLayoutDirection(Qt::RightToLeft);
        lineEdit_Trans->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(lineEdit_Trans);

        label_Asterisco3 = new QLabel(widget);
        label_Asterisco3->setObjectName(QStringLiteral("label_Asterisco3"));
        label_Asterisco3->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_Asterisco3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_Asterisco3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout_2);

        SecondWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SecondWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 371, 21));
        SecondWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(SecondWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SecondWindow->setStatusBar(statusbar);

        retranslateUi(SecondWindow);

        QMetaObject::connectSlotsByName(SecondWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SecondWindow)
    {
        SecondWindow->setWindowTitle(QApplication::translate("SecondWindow", "MainWindow", Q_NULLPTR));
        pushButton_Confirmar->setText(QApplication::translate("SecondWindow", "Confirmar", Q_NULLPTR));
        label_Est_Ini->setText(QApplication::translate("SecondWindow", "Ingrese estado inicial:", Q_NULLPTR));
        label_Est_Fin->setText(QApplication::translate("SecondWindow", "Ingrese estado final:", Q_NULLPTR));
        label_Trans->setText(QApplication::translate("SecondWindow", "Ingrese las transiciones:", Q_NULLPTR));
        label_Asterisco1->setText(QApplication::translate("SecondWindow", "*", Q_NULLPTR));
        label_Asterisco2->setText(QApplication::translate("SecondWindow", "*", Q_NULLPTR));
        label_Asterisco3->setText(QApplication::translate("SecondWindow", "*", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SecondWindow: public Ui_SecondWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECONDWINDOW_H
