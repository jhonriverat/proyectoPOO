#include "Alimentos.h"

//Constructor clase Alimentos
Alimentos::Alimentos(string _alimentos,string _claseAlimento) {
    this->alimentos = _alimentos;
    this->claseAlimento = _claseAlimento;
}

//Metodos de acceso
string Alimentos::getAlimentos() {
    return alimentos;
}

void Alimentos::setAlimentos(string alimentos) {
    this->alimentos = alimentos;
}

string Alimentos::getClaseAlimento() {
    return claseAlimento;
}