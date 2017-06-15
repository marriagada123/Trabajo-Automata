#ifndef TRANSICIONES_H
#define TRANSICIONES_H

#include <QString>
class Transiciones
{
protected:
public:
    class Nodo2{
        public:
            QString estadoQ;
            QString simboloQ;
            QString estadoP;
            QString simboloP;
            QString direccion;

            Nodo2* siguiente;
    };
    Nodo2* inicio;

    Transiciones(){inicio=0;}
    void inserta(QString estQ, QString simQ, QString estP, QString simP, QString direc);
    QString imprimeTrans(void);
    bool verificaIngresoTran(QString estQ, QString simQ);
    QString lenguaje(void);
};

#endif // TRANSICIONES_H
