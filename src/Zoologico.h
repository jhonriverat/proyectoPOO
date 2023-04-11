#ifndef PROYECTOPOO_ZOOLOGICO_H
#define PROYECTOPOO_ZOOLOGICO_H

#include "habitat.h"
#include "Alimentos.h"
#include "Animales.h"
#include "personas.h"
#include <list>


class Zoologico {
private:
    list<habitat*> listHabitat;
    list<Alimentos*> listAlimentos;
    list<Animales*> listAnimales;


    void mostrarAnimales();

public:
    Zoologico()=default;
    void menu();
    void agregarHabitat();
    void agregarListaAnimales(Animales * n);
    void agregarListaAlimentos(Alimentos * p);
    void agregarListaHabitat(habitat * h);
    void mostrarAlimentos(string claseDeAlimento);
    void mostrarHabitas();
    void verificarHabitas(string nombreHabitat);
    int verificarExistenciaHabitat(string nombreHabitat);
    string palabraMinuscula(string palabra);
    int recomendarHabitat(int temperatura);
    int verificarExistenciaClaseAlimentos(string claseAlimento);
    void agregarAnimal();
    void menuAcciones();
    void obtenerAnimal(string nombreAnimal, string accion);
    void realizarAcciones(string nombreAnimal, string accion, string claseDeAlimento, bool yaJugo, int horasDormir);
    int verificarAnimal(string nombreAnimal);
    void comer(string nombreAnimal, string claseDeAlimento);
    void dormir(string nombreAnimal, int horasDormir);
    void dormir(int horasDormir, int horasUsuario);
    void jugar(string nombreAnimal, bool yaJugo);
    void jugar(string nombreAnimal);
    void editarListaAlimentos();
    void editarListaAlimentos(string alimento, string claseDeAlimento);
    //Pruebas
    void animalesDePrueba();
};


#endif //PROYECTOPOO_ZOOLOGICO_H
