#include "Alimentos.h"

//Constructor clase Alimentos
Alimentos::Alimentos(string _alimentos,string _claseAlimento, int _temperatura) {
    this->alimentos = _alimentos;
    this->claseAlimento = _claseAlimento;
    this->temperatura = _temperatura;
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