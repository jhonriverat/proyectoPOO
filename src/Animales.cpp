#include "Animales.h"
// constructor de clase animales
Animales::Animales(string _nombreAnimal, int _edadAnimal,int _temperatura, string _habitat, string _especie, string _claseDeAlimentacion) {
    this->nombreAnimal = _nombreAnimal;
    this->edadAnimal = _edadAnimal;
    this->temperaturaMinima = _temperatura;
    this->habitat = _habitat;
    this->especie = _especie;
    this->claseDeAlimentacion = _claseDeAlimentacion;

}

void Animales::mostrarInfoAnimales() {
    cout<<endl<<"Hola, mi nombre es "<<nombreAnimal<<endl;
    cout<<"Estoy en el habitad de "<<habitat<<" y soy un "<<especie<<endl;
    cout<<endl;

}

string Animales::getNombreAnimal() {
    return nombreAnimal;
}

string Animales::getClaseAlimentacion() {
    return claseDeAlimentacion;
}
string Animales::getHabitatAnimal() {
    return habitat;
}

int Animales::getTemperaturaMinima() {
    return temperaturaMinima;
}
