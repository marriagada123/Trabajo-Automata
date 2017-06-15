#include "transiciones.h"
#include <iostream>

/*
 * metodo para insertar nodos a la lista
 */
void Transiciones::inserta(QString estQ, QString simQ, QString estP, QString simP, QString direc){
    Nodo2 *nuevo = new Nodo2();
    nuevo->estadoQ = estQ;
    nuevo->simboloQ = simQ;
    nuevo->estadoP = estP;
    nuevo->simboloP = simP;
    nuevo->direccion = direc;

    nuevo->siguiente = 0;

    Nodo2* aux = inicio;
    if(inicio == 0){
        inicio = nuevo;
    }
    else{
        while (aux->siguiente != 0) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevo;
    }
}
/*imprime los datos de un nodo*/
QString Transiciones::imprimeTrans(void){
    QString datos = "";
    Nodo2* aux = inicio;
    if(aux){
        while (aux) {
            datos += aux->estadoQ+" , ";
            datos += aux->simboloQ+" , ";
            datos += aux->estadoP+" , ";
            datos += aux->simboloP+" , ";
            datos += aux->direccion+"\n";
            aux = aux->siguiente;
        }
    }
    return datos;
}
/*
 * verifica que las transiciones no esten repetidas*/
bool Transiciones::verificaIngresoTran(QString estQ, QString simQ){
    Nodo2* aux = inicio;
    while (aux) {
        if(aux->estadoQ == estQ && aux->simboloQ == simQ ) break;
        else aux = aux->siguiente;
    }
    if(aux){
        //std::cout << "esta transicion ya esta definida" << std::endl;
        return false;
    }else{
        return true;
    }
}
/*
 * metodo usado para que identificar el lenguaje de la cinta
 * se usa para crear la cabecera de la tabla
 **/
QString Transiciones::lenguaje(void){
    Nodo2* aux = inicio;
    Nodo2* aux2 = aux->siguiente;
    QString datos1 = "";
    int c = 0;
    if(aux){
        while (aux) {
            datos1 += aux->simboloQ;
            aux = aux->siguiente;
        }
    }
    QString str = datos1;
    QChar J, I;
    int i, j;
    i = j = 0;
    J = I = ' ';
    while (i < str.length() - 1){
        j = i + 1;
        while (j < str.length()){
            J = str[j];
            I = str[i];
            if (J == I)
                str = str.remove(j,1);
            else
                j++;
        }
        i++;
    }
    return str;
}
