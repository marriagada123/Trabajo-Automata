#include "maqturing.h"
#include <qstring.h>
#include <iostream>
#include <cstdlib>

#include <transiciones.h>
#include <QDebug>

bool MaqTuring::validaEstado(QString estado){
    int largoEst = estado.length();
    const char *pal = estado.toStdString().c_str();
    bool estValido = true;
    int i = 0;
    int p;
    while(estValido){
        if(largoEst == 0){
            //std::cout<<"no escribiste nada"<<std::endl;
            estValido = false;
            return false;
        }else {
            while (i < largoEst && estValido) {
                p = int(pal[i]);
                if(p < 48 || p > 57){
                    //std::cout<<"no es numero lo que se ingreso!"<<std::endl;
                    estValido = false;
                    return false;
                }
                i++;
            }
        }
        estValido = false;
        return true;
    }
}

bool MaqTuring::valEstActSig(QString estIni, QString estFin, QString estActual){
    bool valida_estActual = validaEstado(estActual);
    if(!valida_estActual){
        //std::cout<<"el estado inicial de la transicion no es valido"<<std::endl;
        return false;
    }
    int EI = atoi(estIni.toStdString().c_str());
    int EF = atoi(estFin.toStdString().c_str());
    int EA = atoi(estActual.toStdString().c_str());
    if(EA < EI || EA > EF){
        //std::cout<<"el estado inicial de la transicion no pertenece"<<std::endl;
        return false;
    }
    return true;
}
bool MaqTuring::validaDireccion(QString direc){
    if(direc == "I" || direc == "D" || direc == "d" || direc == "i"){
        //std::cout << "es una direccion valida"<<std::endl;
        return true;
    }else{
        //std::cout << "NO es una direccion valida"<<std::endl;
        return false;
    }
}
bool MaqTuring::validaSimbolo(QString simbolo){
    int largoSim = simbolo.length();
    if(largoSim != 1){
        //std::cout<<"simbolo incorrecto"<<std::endl;
        return false;
    }else{
        //std::cout<<"simbolo correcto"<<std::endl;
        return true;
    }
}

int MaqTuring::calculaNumEst(QString estIni, QString estFin){
    int EI = atoi(estIni.toStdString().c_str());
    int EF = atoi(estFin.toStdString().c_str());
    int numEstados = EF - EI + 1;
    //std::cout<<numEstados<<std::endl;
    return numEstados;
}

bool MaqTuring::ordenEstados(QString estIni, QString estFin){
    int EI = atoi(estIni.toStdString().c_str());
    int EF = atoi(estFin.toStdString().c_str());
    bool estVal = true;
    if(EF <= EI || estIni == ""){
        estVal = false;
        //std::cout<<estVal+ " hh"<<std::endl;
        return estVal;
    }else{
        //std::cout<<estVal+ "gg "<<std::endl;
        return estVal;
    }
}
void MaqTuring::inserta(QString simbolo,QString estIni){
    Nodo1 *nuevo = new Nodo1();
    nuevo->simbolo = simbolo;
    nuevo->siguiente = 0;
    nuevo->anterior = 0;

    Nodo1 *blanco;

    Nodo1* aux =inicio;
    if(inicio == 0){
        blanco= new Nodo1();
        blanco->estado = "";
        blanco->simbolo = "B";
        blanco->anterior = 0;
        blanco->siguiente = 0;
        nuevo->estado = estIni;
        inicio = nuevo;
        nuevo->siguiente = blanco;
        blanco->anterior = nuevo;
    }
    else{
        while(aux->siguiente != 0 && aux->siguiente != blanco){
            aux = aux->siguiente;
        }
        nuevo->estado="";
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
        nuevo->siguiente = blanco;
        blanco->anterior = nuevo;
    }
}

QString MaqTuring::imprimePalabra(void){
    QString datos = "";
    Nodo1* aux=inicio;
    if(aux){
        while (aux) {
            datos+=aux->simbolo+"\n";
            aux = aux->siguiente;
        }
    }
    return datos;
}
bool MaqTuring::verificarPalabra(Transiciones* tran, QString estFinal){
    Nodo2* aux2 = tran->inicio;
    Nodo1* aux1 = inicio;
    QString a = aux1->estado;
    QString b = aux1->simbolo;
    QString c = aux2->estadoQ;
    QString d = aux2->simboloQ;
    QString EF = estFinal;
    std::cout<<EF.toStdString()<<std::endl;
    std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
    while(aux1){
        std::cout<<"2"<<std::endl;
        std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
        aux2 = tran->inicio;
        std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
        if(aux1->estado != estFinal){
            std::cout<<"3"<<std::endl;
            std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;



            while ((aux1->estado != aux2->estadoQ || aux1->simbolo != aux2->simboloQ) && aux2 != 0) {
                std::cout<<"4"<<std::endl;
                std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
                aux2 = aux2->siguiente;
                if(aux2->estadoP != EF){
                    return true;
                    std::cout<<"dddddd"+aux2->estadoP.toStdString()<<std::endl;
                }else{
                    std::cout<<"aaaaa"<<std::endl;
                    return false;
                }
            }



            std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
            if(aux2 == 0){
                return false;
                std::cout<<"5"<<std::endl;
                std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
            }
            std::cout<<"6"<<std::endl;
            std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
            aux1->simbolo = aux2->simboloP;
            std::cout<<"7"<<std::endl;
            std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
            if(aux2->direccion == "D" || aux2->direccion == "d"){
                std::cout<<"8"<<std::endl;
                std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
                aux1 = aux1->siguiente;
            }else{
                std::cout<<"9"<<std::endl;
                std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
                aux1 = aux1->anterior;
            }
            std::cout<<"10"<<std::endl;
            std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
            aux1->estado = aux2->estadoP;


        }else{
            std::cout<<"11"<<std::endl;
            std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
            return true;
        }
        std::cout<<"12"<<std::endl;
        std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
    }
    std::cout<<"13"<<std::endl;
    std::cout<<aux1->estado.toStdString()+","+aux1->simbolo.toStdString()+","+aux2->estadoQ.toStdString()+","+aux2->simboloQ.toStdString()<<std::endl;
}
