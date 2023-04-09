#ifndef PROYECTOPOO_ZOOLOGICO_H
#define PROYECTOPOO_ZOOLOGICO_H

#include "habitat.h"
#include "Alimentos.h"
#include "Animales.h"
#include "personas.h"
#include <list>

class Zoologico {
private:
    list<Animales*> listAnimales;
    list<habitat*> listHabitat;
    list<Alimentos*> listAlimentos;

    void mostrarAnimales();

public:
    Zoologico()=default;
    void menu();
    void agregarHabitat();
    void agregarListaAnimales(Animales * n);
    void agregarListaAlimentos(Alimentos * p);
    void agregarListaHabitat(habitat * h);
    void mostrarAlimentos();
    void mostrarHabitas();
    void verificarHabitas(string nombreHabitat);
    int verificarExistenciaHabitat(string nombreHabitat);
    string palabraMinuscula(string palabra);
    void agregarAnimal();

    //Pruebas
    void animalesDePrueba();
};


#endif //PROYECTOPOO_ZOOLOGICO_H
