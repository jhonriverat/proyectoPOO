#ifndef PROYECTOPOO_HABITAT_H
#define PROYECTOPOO_HABITAT_H

#include <iostream>
#include <stdlib.h>
#include <list>
#include <vector>
#include "Alimentos.h"
using namespace std;


class habitat {
private:
    string nombreHabitat;
    int temperaturaMinimaHabitat;
    int temperaturaMaximaHabitat;
    /*
    list<habitat*> listHabitat;
    list<Alimentos*> listAlimentos;
     */
public:
    habitat();
    habitat(string, int, int);
    void mostrarInfoHabitat();
    //get
    string getNombreHabitat();
    int getTemperaturaMinimaHabitat();
    int getTemperaturaMaximaHabitat();
    //set
    void setNombreHabitat(string nombreHabitat);

};


#endif //PROYECTOPOO_HABITAT_H
