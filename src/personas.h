#ifndef PROYECTOPOO_PERSONAS_H
#define PROYECTOPOO_PERSONAS_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Personas {
private: //Atributos
    string nombre;
    int id;
public: //Metodos
    Personas(string, int); //constructor
    void mostrarPersonas();
    //getters
    string getNombre();
};

class Trabajador : public Personas{
private://atributos
    string cargo;
    int calificacion;
public://metodos
    Trabajador(string,int,string,float);
    void mostrarTrabajador();
    //getters
    float getCalificacion();
    //set
    void setCalificacion(float calificacion);
};


#endif //PROYECTOPOO_PERSONAS_H
