#include "Alimentos.h"

//Constructor clase Alimentos
Alimentos::Alimentos(string _alimento1,string _alimento2,string _alimento3,string _claseAlimento) {
    this->alimento1 = _alimento1;
    this->alimento2 = _alimento2;
    this->alimento3 = _alimento3;
    this->claseAlimento = _claseAlimento;
}

//Metodos de acceso
string Alimentos::getAlimento1() {
    return alimento1;
}

void Alimentos::setAlimento1(string alimento1) {
    this->alimento1 = alimento1;
}

string Alimentos::getClaseAlimento() {
    return claseAlimento;
}

string Alimentos::getAlimento2()  {
    return alimento2;
}

void Alimentos::setAlimento2(string alimento2) {
    Alimentos::alimento2 = alimento2;
}

string Alimentos::getAlimento3() {
    return alimento3;
}

void Alimentos::setAlimento3(string alimento3) {
    Alimentos::alimento3 = alimento3;
}
