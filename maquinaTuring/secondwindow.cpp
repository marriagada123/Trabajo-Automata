#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <maqturing.h>

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
    ui->textBrowser_Mostrar->setText(estadoIni+"\n"+estadoFin+"\n"+transiciones);

    // VALIDACIONES
    bool validaIni = maq->validaEstado(estadoIni);
    bool validaFin = maq->validaEstado(estadoFin);
    //bool validaTrans = maq->validaEstado(transiciones);
    if(!validaIni){
        ui->label_Asterisco1->setVisible(true);
    }else{
        ui->label_Asterisco1->setVisible(false);
    }
    if(!validaFin){
        ui->label_Asterisco2->setVisible(true);
    }else{
        ui->label_Asterisco2->setVisible(false);
    }
    if(transiciones == ""){
        ui->label_Asterisco3->setVisible(true);
    }else{
        ui->label_Asterisco3->setVisible(false);
    }

}
