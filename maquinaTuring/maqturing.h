#ifndef MAQTURING_H
#define MAQTURING_H

#include <QString.h>

class MaqTuring
{
protected:
    class Nodo{
        public:
            QString estadoIni;
            QString estadoFin;
            QString transicion;
    };
    Nodo* inicio;
public:
    MaqTuring(){inicio=0;}
    bool validaEstado(QString estado);
    int calculaNumEst(QString estIni, QString estFin);
    bool ordenEstados(QString estIni, QString estFin);
};

#endif // MAQTURING_H
