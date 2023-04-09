#ifndef PROYECTOPOO_ANIMALES_H
#define PROYECTOPOO_ANIMALES_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Animales {
private:
    string nombreAnimal;
    int edadAnimal;
    int temperaturaMinima;
    string habitat;
    string especie;
    string claseDeAlimentacion;
public:
    Animales();
    Animales(string,int,int,string,string,string);//constructor
    void mostrarInfoAnimales();

    //metodos de acceso
    string getHabitatAnimal();
    int getTemperaturaMinima();
    string getNombreAnimal();
    string getClaseAlimentacion();


};


#endif //PROYECTOPOO_ANIMALES_H
