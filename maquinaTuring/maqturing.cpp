#include "maqturing.h"
#include <qstring.h>
#include <iostream>
#include <cstdlib>



bool MaqTuring::validaEstado(QString estado){
    int largoEst = estado.length();
    const char *pal = estado.toStdString().c_str();
    bool estValido = true;
    int i = 0;
    int p;
    while(estValido){
        if(largoEst == 0){
            std::cout<<"no escribiste nada"<<std::endl;
            estValido = false;
            return false;
        }else {
            while (i < largoEst && estValido) {
                p = int(pal[i]);
                if(p < 48 || p > 57){
                    std::cout<<"no es numero lo que se ingreso!"<<std::endl;
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

