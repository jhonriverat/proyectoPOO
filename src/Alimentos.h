#ifndef PROYECTOPOO_ALIMENTOS_H
#define PROYECTOPOO_ALIMENTOS_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Alimentos {
private:
    string alimentos;
    string claseAlimento;
    int temperatura;
public:
    Alimentos();
    Alimentos(string,string ,int);
    //Metodos de acceso
    string getAlimentos();
    string getClaseAlimento();
    void setAlimentos(string alimentos);


};


#endif //PROYECTOPOO_ALIMENTOS_H
