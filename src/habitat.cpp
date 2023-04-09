#include "habitat.h"
//constructor clase habitat
habitat::habitat(string _nombreHabitat, int _temperaturaMinimaHabitat, int _temperaturaMaximaHabitat) {
    this->nombreHabitat = _nombreHabitat;
    this->temperaturaMinimaHabitat = _temperaturaMinimaHabitat;
    this->temperaturaMaximaHabitat = _temperaturaMaximaHabitat;
}
void habitat::mostrarInfoHabitat() {
    cout<<"habitat "<<getNombreHabitat()<<endl;
}

//metodos de acceso
string habitat::getNombreHabitat() {
    return nombreHabitat;
}

int habitat::getTemperaturaMinimaHabitat() {
    return temperaturaMinimaHabitat;
}

int habitat::getTemperaturaMaximaHabitat() {
    return temperaturaMaximaHabitat;
}

void habitat::setNombreHabitat(string nombreHabitat) {
    this-> nombreHabitat = nombreHabitat;
}

