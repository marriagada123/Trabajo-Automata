#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <maqturing.h>
#include <transiciones.h>

#include <iostream>
#include <cstdlib>
#include <QStandardItemModel>
#include <QStringList>
#include <QDebug>

MaqTuring *maq = new MaqTuring();
Transiciones *tran = new Transiciones();

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

/*
 * metodo del boton confirmar que genera la lista doblemente enlazada donde ira la palabra
 */
void SecondWindow::on_pushButton_Confirmar_clicked()
{
    MaqTuring *maq2 = new MaqTuring();
    QString palabra = ui->lineEdit_Pal_Ent->text();
    QString estado = ui->lineEdit_Trans_1->text();
    std::string str;
    str = std::to_string(estadoInicial);
    QString estString = QString::fromStdString(str);

    std::string strf;
    strf = std::to_string(estadoFinal);
    QString estStringF = QString::fromStdString(strf);

    int largoPalabra = palabra.length();
    //delete[] maq;
    QString sim = "";
    for(int i = 0; i < largoPalabra; i++){
        sim = palabra[i];
        maq2->inserta(sim,estString);
    }
    QString pal = maq2->imprimePalabra();
    ui->textBrowser_Mostrar->setText(pal);
    if(maq2->verificarPalabra(tran,estStringF)){
        ui->textBrowser_Mostrar->setText("palabra aceptada");
    }else{
        ui->textBrowser_Mostrar->setText("palabra rechazada");
    }

}

/*
 *en este metodo genera la lista enlazada con las transiciones ademas crea la tabla donde se muestras dichas transiciones
 */
void SecondWindow::on_pushButton_inserta_clicked()
{
    QString estadoIni = ui->lineEdit_Est_Ini->text();
    QString estadoFin = ui->lineEdit_Est_Fin->text();
    QString estadoQ = ui->lineEdit_Trans_1->text();
    QString simboloQ = ui->lineEdit_Trans_2->text();
    QString estadoP = ui->lineEdit_Trans_3->text();
    QString simboloP = ui->lineEdit_Trans_4->text();
    QString direccion = ui->lineEdit_Trans_5->text();
    QString palabraEnt = ui->lineEdit_Pal_Ent->text();
    int numEst = 0;
    std::string str;
    QString numEstString;


    // BOOLEANOS VALIDACIONES
    bool validaIni = maq->validaEstado(estadoIni);
    bool validaFin = maq->validaEstado(estadoFin);
    bool validaTrans1 = maq->valEstActSig(estadoIni,estadoFin,estadoQ);
    bool validaTrans2 = maq->validaSimbolo(simboloQ);
    bool validaTrans3 = maq->valEstActSig(estadoIni,estadoFin,estadoP);
    bool validaTrans4 = maq->validaSimbolo(simboloP);
    bool validaTrans5 = maq->validaDireccion(direccion);
    bool validaOrden = maq->ordenEstados(estadoIni,estadoFin);
    bool verifica = tran->verificaIngresoTran(estadoQ,simboloQ);
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
    if(!validaTrans1 || !verifica){        
        ui->lineEdit_Trans_1->setStyleSheet("border: 1px solid red");
    }else{
        ui->lineEdit_Trans_1->setStyleSheet(styleSheet());
    }
    if(!validaTrans2 || !verifica){
        ui->lineEdit_Trans_2->setStyleSheet("border: 1px solid red");
    }else{
        ui->lineEdit_Trans_2->setStyleSheet(styleSheet());
    }
    if(!validaTrans3){
        ui->lineEdit_Trans_3->setStyleSheet("border: 1px solid red");
    }else{
        ui->lineEdit_Trans_3->setStyleSheet(styleSheet());
    }
    if(!validaTrans4){
        ui->lineEdit_Trans_4->setStyleSheet("border: 1px solid red");
    }else{
        ui->lineEdit_Trans_4->setStyleSheet(styleSheet());
    }
    if(!validaTrans5){
        ui->lineEdit_Trans_5->setStyleSheet("border: 1px solid red");
    }else{
        ui->lineEdit_Trans_5->setStyleSheet(styleSheet());
    }
    if(validaFin && validaIni && validaOrden){
        numEst = maq->calculaNumEst(estadoIni,estadoFin);
        numeroEstado = numEst;
        str = std::to_string(numEst);
        numEstString = QString::fromStdString(str);
    }
    //INSERTA NODO DE TRANSICION
    //
    if(validaIni && validaFin && validaOrden && validaTrans1 && validaTrans2 && validaTrans3 && validaTrans4 && validaTrans5 && verifica){
        ui->label_Asterisco3->setVisible(false);
        estadoInicial = atoi(estadoIni.toStdString().c_str());
        estadoFinal = atoi(estadoFin.toStdString().c_str());

        //inserta nodo con la transicion
        tran->inserta(estadoQ,simboloQ,estadoP,simboloP,direccion);
        ui->textBrowser_Mostrar->setText(tran->imprimeTrans());

        QString leng = tran->lenguaje();
        int tamlen = leng.length();
        //crear el header
        QString aux2;
        QStringList aux;
        aux.clear();
        aux.append("Q | S");
        for(int i = 0; i < tamlen ; i++){
            aux2 = leng[i];
            aux.append(aux2);
        }
        //genera columna principal
        ui->tableWidget_datos->setColumnCount(aux.size());
        ui->tableWidget_datos->setHorizontalHeaderLabels(aux);
        ui->tableWidget_datos->setColumnWidth(0,100);

        int auxIni = estadoInicial;
        //genera filas con todos los estados
        if(ui->tableWidget_datos->rowCount() == 0){
            for(int i = 0; i < numeroEstado;i++){
                str = std::to_string(auxIni);
                ui->tableWidget_datos->insertRow(ui->tableWidget_datos->rowCount());
                ui->tableWidget_datos->setItem(ui->tableWidget_datos->rowCount()-1,0,new QTableWidgetItem(QString::fromStdString(str)));
                auxIni++;
            }
        }
        //identifica la columna donde tiene que agregarse el dato
        int cont = 0;
        while(simboloQ != leng[cont]){
            cont++;
        }
        //convierte a todos los estados a una cadena
        QString stringEstado = "";
        for(int i = estadoInicial ; i <= estadoFinal; i++){
            str = std::to_string(i);
            numEstString = QString::fromStdString(str);
            stringEstado += numEstString;
        }
        //identifica en que fila se ingresara el dato
        int cont2 = 0;
        while (estadoQ != stringEstado[cont2]) {
            cont2++;
        }
        QString transi = "( "+estadoP+" , "+simboloP+" , "+direccion+" )";
        ui->tableWidget_datos->setItem(cont2,cont+1,new QTableWidgetItem(transi));
    }else{
        ui->label_Asterisco3->setVisible(true);
        estadoInicial = 0;
        estadoFinal = 0;
    }
}
