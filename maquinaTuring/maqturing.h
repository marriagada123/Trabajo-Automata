#ifndef MAQTURING_H
#define MAQTURING_H

#include <QString.h>
#include <transiciones.h>

class MaqTuring:public Transiciones
{
protected:
public:
    class Nodo1{
        public:
            QString simbolo;
            QString estado;

            Nodo1* siguiente;
            Nodo1* anterior;
    };
    Nodo1* inicio;

    MaqTuring(){inicio=0;}
    bool validaEstado(QString estado);
    int calculaNumEst(QString estIni, QString estFin);
    bool ordenEstados(QString estIni, QString estFin);
    bool valEstActSig(QString estIni, QString estFin, QString estActual);
    bool validaDireccion(QString direc);
    bool validaSimbolo(QString simbolo);
    void inserta(QString simbolo, QString estIni);
    QString imprimePalabra(void);
    bool verificarPalabra(Transiciones* tran, QString estFinal);
};

#endif // MAQTURING_H
