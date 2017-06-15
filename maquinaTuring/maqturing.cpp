#include "maqturing.h"
#include <qstring.h>
#include <iostream>
#include <cstdlib>

#include <transiciones.h>
#include <QDebug>

/*
 * metodo que valida que lo ingresado como estado solo sean numeros, retornando un valor booleano
 */
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
/*
 * metodo que es utilizado al ingresar las transiciones, para validar que los estados esten dentro del rango que designamos
 */
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
/*
 * metodo que valida la direccion, que solo se pueda ingresar D o I. d o i
 */
bool MaqTuring::validaDireccion(QString direc){
    if(direc == "I" || direc == "D" || direc == "d" || direc == "i"){
        //std::cout << "es una direccion valida"<<std::endl;
        return true;
    }else{
        //std::cout << "NO es una direccion valida"<<std::endl;
        return false;
    }
}
/*
 * este metodo solo valida que los simboloes tengan largo 1
 */
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
/*
 * metodo que calcula el numero total de estado, tomando el estado final e inicial
 */
int MaqTuring::calculaNumEst(QString estIni, QString estFin){
    int EI = atoi(estIni.toStdString().c_str());
    int EF = atoi(estFin.toStdString().c_str());
    int numEstados = EF - EI + 1;
    //std::cout<<numEstados<<std::endl;
    return numEstados;
}

/*
 * metodo que obliga a que el estado inicial ingresado sea menor al estado final
 */
bool MaqTuring::ordenEstados(QString estIni, QString estFin){
    int EI = atoi(estIni.toStdString().c_str());
    int EF = atoi(estFin.toStdString().c_str());
    bool estVal = true;
    if(EF <= EI || estIni == ""){
        estVal = false;
        //std::cout<<estVal<<std::endl;
        return estVal;
    }else{
        //std::cout<<estVal<<std::endl;
        return estVal;
    }
}

/*
 * metodo encargado de crear la lista doblemente enlazada que guardara la palabra de entrada a evaluar
 */
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

/*
 * metodo que imprime las palabra, usado para probar los metodos
 */
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
/*
 * metodo que verifica si la palabra pertenece al lenguaje, moviendo punteros en una lista doblemente enlazada
 * en esta lista se encuentra la palabra, para comparar con las transiciones se usa una lista enlazada simple
 * se comparan ambas listas
 */
bool MaqTuring::verificarPalabra(Transiciones* tran, QString estFinal){
    Nodo2* aux2 = tran->inicio;
    Nodo1* aux1 = inicio;
    QString EF = estFinal;
    while(aux1){
        aux2 = tran->inicio;
        if(aux1->estado != estFinal){
            while (aux1->estado != aux2->estadoQ || aux1->simbolo != aux2->simboloQ) {
                aux2 = aux2->siguiente;
                if(aux2 == 0){
                    return false;
                }
            }
            if(aux2->estadoP == EF){
                return true;
            }
           aux1->simbolo = aux2->simboloP;
            if(aux2->direccion == "D" || aux2->direccion == "d"){
                aux1 = aux1->siguiente;
            }else{
                aux1 = aux1->anterior;
            }
            aux1->estado = aux2->estadoP;


        }else{
            return true;
        }
    }
}
