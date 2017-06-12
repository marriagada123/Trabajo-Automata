#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <maqturing.h>

#include <iostream>
#include <cstdlib>

MaqTuring *maq = new MaqTuring();

SecondWindow::SecondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    // estilo de ventana
    ui->label_Asterisco1->setVisible(false);
    ui->label_Asterisco2->setVisible(false);
    ui->label_Asterisco3->setVisible(false);
    ui->label_Asterisco4->setVisible(false);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_Confirmar_clicked()
{
    //MaqTuring*  = new MaqTuring();
    QString estadoIni = ui->lineEdit_Est_Ini->text();
    QString estadoFin = ui->lineEdit_Est_Fin->text();
    QString transiciones = ui->lineEdit_Trans->text();
    QString palabraEnt = ui->lineEdit_Pal_Ent->text();
    int numEst = 0;
    std::string str;
    QString numEstString;


    // VALIDACIONES
    bool validaIni = maq->validaEstado(estadoIni);
    bool validaFin = maq->validaEstado(estadoFin);
    //bool validaTrans = maq->validaEstado(transiciones);
    bool validaOrden = maq->ordenEstados(estadoIni,estadoFin);

    //VALIDACION ESTADO INICIAL
    if(!validaIni || !validaOrden){
        ui->label_Asterisco1->setVisible(true);
        ui->lineEdit_Est_Ini->setStyleSheet("border: 1px solid red");
    }else{
        ui->label_Asterisco1->setVisible(false);
        ui->lineEdit_Est_Ini->setStyleSheet(styleSheet());
    }
    //VALIDACION ESTADO FINAL
    if(!validaFin || !validaOrden){
        ui->label_Asterisco2->setVisible(true);
        ui->lineEdit_Est_Fin->setStyleSheet("border: 1px solid red");
    }else{
        ui->label_Asterisco2->setVisible(false);
        ui->lineEdit_Est_Fin->setStyleSheet(styleSheet());
    }

    //VALIDACION TRANSICIONES
    if(transiciones == ""){
        ui->label_Asterisco3->setVisible(true);
        ui->lineEdit_Trans->setStyleSheet("border: 1px solid red");
    }else{
        ui->label_Asterisco3->setVisible(false);
        ui->lineEdit_Trans->setStyleSheet(styleSheet());
    }

    //VALIDACION PALABRA DE ENTRADA
    if(palabraEnt == ""){
        ui->label_Asterisco4->setVisible(true);
        ui->lineEdit_Pal_Ent->setStyleSheet("border: 1px solid red");
    }else{
        ui->label_Asterisco4->setVisible(false);
        ui->lineEdit_Pal_Ent->setStyleSheet(styleSheet());
    }

    if(validaFin && validaIni && validaOrden){
        numEst = maq->calculaNumEst(estadoIni,estadoFin);
        str = std::to_string(numEst);
        numEstString = QString::fromStdString(str);
    }
    //std::cout<<numEst<< std::endl;
    ui->textBrowser_Mostrar->setText("Estado Inicial: "+estadoIni+"\n"+
                                     "Estado Final: "+estadoFin+"\n"+
                                     "Transiciones: "+transiciones+"\n"+
                                     "Palabra de Entrada: "+palabraEnt+"\n"+
                                     "Numero de estados: "+numEstString);
}

