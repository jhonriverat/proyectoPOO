#include "habitat.h"
//constructor clase habitat
habitat::habitat(string _nombreHabitat) {
    this->nombreHabitat = _nombreHabitat;
}
void habitat::mostrarInfoHabitat() {
    cout<<"habitat "<<getNombreHabitat()<<endl;
}

//metodos de acceso
string habitat::getNombreHabitat() {
    return nombreHabitat;
}

void habitat::setNombreHabitat(string nombreHabitat) {
    this-> nombreHabitat = nombreHabitat;
}

