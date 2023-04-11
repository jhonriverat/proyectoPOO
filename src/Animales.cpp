#include "Animales.h"
// constructor de clase animales
Animales::Animales(string _nombreAnimal, int _edadAnimal,int _temperatura, string _habitat, string _especie, string _claseDeAlimentacion, int _horasMinimasDormir, bool _yaJugo) {
    this->nombreAnimal = _nombreAnimal;
    this->edadAnimal = _edadAnimal;
    this->temperaturaMinima = _temperatura;
    this->habitat = _habitat;
    this->especie = _especie;
    this->claseDeAlimentacion = _claseDeAlimentacion;
    this->horasMinimasDormir = _horasMinimasDormir;
    this->yaJugo = _yaJugo;
}

void Animales::mostrarInfoAnimales() {
    cout<<endl<<"Hola, mi nombre es "<<nombreAnimal<<" ,tengo "<<edadAnimal<<" años."<<endl;
    cout<<"Estoy en el habitad de "<<habitat<<" y soy un "<<especie<<endl;
    cout<<"Mi tipo de alimentacion es "<<claseDeAlimentacion<<" y mi temperatura minima es "<<temperaturaMinima<<endl;
    cout<<"Necesito dormir "<<horasMinimasDormir<<" horas minimas diariamente."<<endl;
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

int Animales::getHorasMinimasDormir() {
    return horasMinimasDormir;
}

bool Animales::getYaJugo() {
    return yaJugo;
}

void Animales::setYaJugo(bool yaJugo) {
    this->yaJugo = yaJugo;
}
