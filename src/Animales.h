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
    int horasMinimasDormir;
    bool yaJugo;
public:
    Animales();
    Animales(string,int,int,string,string,string,int,bool);//constructor
    void mostrarInfoAnimales();

    //metodos de acceso
    string getHabitatAnimal();
    int getTemperaturaMinima();
    string getNombreAnimal();
    string getClaseAlimentacion();
    int getHorasMinimasDormir();
    bool getYaJugo();

    void setYaJugo(bool yaJugo);


};


#endif //PROYECTOPOO_ANIMALES_H
