#ifndef PROYECTOPOO_ANIMALES_H
#define PROYECTOPOO_ANIMALES_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Animales {
private:
    string nombreAnimal;
    int edadAnimal;
    string habitat;
    string especie;
    string claseDeAlimentacion;
public:
    Animales();
    Animales(string,int,string,string,string);//constructor
    void mostrarInfoAnimales();

};


#endif //PROYECTOPOO_ANIMALES_H
