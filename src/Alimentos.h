#ifndef PROYECTOPOO_ALIMENTOS_H
#define PROYECTOPOO_ALIMENTOS_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class Alimentos {
private:
    string alimento1, alimento2,alimento3;
    string claseAlimento;
public:
    Alimentos();
    Alimentos(string,string,string,string);
    //Metodos de acceso
    string getAlimento1();
    void setAlimento1(string alimento1);

    string getClaseAlimento();

    string getAlimento2() ;
    void setAlimento2(string alimento2);

    string getAlimento3() ;
    void setAlimento3(string alimento3);


};


#endif //PROYECTOPOO_ALIMENTOS_H
