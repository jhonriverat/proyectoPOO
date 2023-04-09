#include "personas.h"

//constructor clase personas (Clase padre)
Personas::Personas(string _nombre, int _id) {
    this->nombre = _nombre;
    this->id = _id;
}
//Muestra informacion de las personas turista
void Personas::mostrarPersonas(){
    cout<<"Hola, soy el turista: "<<nombre<<endl;
    cout<<"Id: "<<id<<endl;
}
//Constructuror de la clase trabajador que es hija de la clase personas
Trabajador::Trabajador(string _nombre, int _id, string _cargo, float _calificacion) : Personas(_nombre,_id) {
    this->cargo = _cargo;
    this->calificacion = _calificacion;


}
//Muestra informacion del trabajador
void Trabajador::mostrarTrabajador() {
    cout<<"Hola, mi nombre es: "<<getNombre()<<endl;
    cout<<"Cargo: "<<cargo<<endl;
    cout<<"Calificacion de recorrido:  "<<getCalificacion()<<endl;
}

string Personas::getNombre(){
    return nombre;
}
float Trabajador::getCalificacion(){
    return calificacion;
}
void Trabajador::setCalificacion(float calificacion){
    this->calificacion = calificacion;
}