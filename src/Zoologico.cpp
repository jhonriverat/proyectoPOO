#include "Zoologico.h"


void Zoologico::menu() {
    int opcion;
    do{
        cout<<" "<<endl;
        cout<<"| Bienvenido al Zoologico J&S  |"<<endl;
        cout<<"| 1. Agregar habitat           |"<<endl;
        cout<<"| 2. Agregar Animal            |"<<endl;
        cout<<"| 3. Ver animales del Zoologico|"<<endl;
        cout<<"Respuesta: "<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                agregarHabitat();
                break;
            case 2:
                agregarAnimal();
                break;
            case 3:
                mostrarAnimales();
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }

    }while(opcion != 0);
}

void Zoologico::agregarHabitat() {
    string nombreHabitat;
    mostrarHabitas();
    cout<<"Ingrese el nombre del nuevo habitat: "<<endl;
    cin >> nombreHabitat;
    for(int i = 0; i < nombreHabitat.length(); i++){
        //cambiar cada letra a minuscula para asegurar el condicional siguiente
        nombreHabitat[i] = ::tolower(nombreHabitat[i]);
    }
    //cout<<"habitat en minuscula: "<<nombreHabitat<<endl;
    verificarHabitas(nombreHabitat);
}

void Zoologico::verificarHabitas(string nombreHabitat) {
    int tempMin,tempMax;
    int verificar = 0;
    list<habitat*>::iterator habitas;
    for(habitas =listHabitat.begin(); habitas != listHabitat.end(); ++habitas){
        if ((*habitas)->getNombreHabitat()==nombreHabitat){
            verificar++;
        }
    }
    if (verificar == 0){
        if(nombreHabitat == "polar" || nombreHabitat == "desertico" || nombreHabitat == "selvatico" || nombreHabitat == "acuatico"){
            cout<<endl<<"Ingrese la temperatura minima del habitat: ";
            cin>>tempMin;
            cout<<endl<<"Ingrese la temperatura maxima del habitat: ";
            cin>>tempMax;
            habitat * ptempHabitat = new habitat(nombreHabitat,tempMin, tempMax);
            listHabitat.push_back(ptempHabitat);
        }else{
            cout<<"Lo sentimos, este habitat no esta definida en nuestra base de datos."<<endl;
        }
    }else{
        cout << "Lo sentimos, este habitat ya esta registrado en nuestro zoologico." << endl;
    }
}
void Zoologico::agregarAnimal() {
    string nombreAnimal, habitat, especie, claseDeAlimentacion;
    int edadAnimal, temperaturaAnimal;
    int limiteCaracteres = 15;
    int limiteEdad = 25;

    cout << endl << "Ingrese en nombre del animal: ";
    //cin>>nombreAnimal;
    cin.ignore();
    getline(cin, nombreAnimal);


    if (nombreAnimal.length() > limiteCaracteres) {
        throw out_of_range("El nombre excedio el limite de caracteres");
    }
    cout << "nombre animal: " << nombreAnimal << endl;

    cout << endl;

    //obtener especie del animal.
    cout << endl << "Ingrese la especie del animal:";
    cin.ignore();
    getline(cin, especie);
    if (especie.length() > limiteCaracteres) {
        throw out_of_range("La especie excedio el limite de caracteres");
    }

    //Mostrar habitas recomendadas
    cout << endl << "Ingrese la temperatura minima que el animal pueda soportar: ";
    cin >> temperaturaAnimal;

    do {

        recomendarHabitat(temperaturaAnimal);
        cout << endl << "Escriba el habitat exactamente del animal: ";
        cin >> habitat;
        if (habitat.length() > limiteCaracteres) {
            throw out_of_range("El habitat excedio el limite de caracteres");
        }
        habitat = palabraMinuscula(habitat);
        if (verificarExistenciaHabitat(habitat) == 1) {
            cout << endl << "||El habitat que ingresaste es correcto||" << endl;
        } else {
            cout << "||El habitat que ingresaste no es correcto, ingresa los datos nuevamente||" << endl;
        }
    }while(verificarExistenciaHabitat(habitat) == 0);

    //cout<<"La palabra minimizada es: "<<habitat<<endl;

    do {
        //Obtener la clase alimentacion
        cout << endl << "||Tipos de alimentacion||" << endl << "1. carnivoro" << endl << "2. herbivoro" << endl
             << "3. omnivoro" << endl << "Ingrese exactamente el tipo de alimento: ";
        cin >> claseDeAlimentacion;
        if (claseDeAlimentacion.length() > limiteCaracteres) {
            throw out_of_range("El habitat excedio el limite de caracteres");
        }
        claseDeAlimentacion = palabraMinuscula(claseDeAlimentacion);
        if (verificarExistenciaClaseAlimentos(claseDeAlimentacion) == 1) {
            cout << "||La clase existe||" << endl;
        } else {
            cout << endl << "||La clase no existe, ingresa los datos de nuevo||" << endl;
        }
    }while(verificarExistenciaClaseAlimentos(claseDeAlimentacion) == 0);

    do {
        //obtener edad del animal
        cout << "||NOTA: la edad tiene que ser menor a 26 años||";
        cout << endl << "Ingrese la edad del animal: ";
        cin >> edadAnimal;
        if (edadAnimal > limiteEdad) {
            cout << "Lo sentimos, este animal no lo podremos aceptar debido a su edad" << endl;
        } else {
            Animales *ptempAnimal = new Animales(nombreAnimal, edadAnimal, temperaturaAnimal, habitat, especie,
                                                 claseDeAlimentacion);
            listAnimales.push_back(ptempAnimal);
            cout << "||Se registro con exito " << nombreAnimal << "||" << endl;
        }
    }while(edadAnimal > limiteEdad);

}

string Zoologico::palabraMinuscula(string palabra) {
    for(int i = 0; i < palabra.length(); i++){
        //cambiar cada letra a minuscula para asegurar el condicional siguiente
        palabra[i] = ::tolower(palabra[i]);
    }
    return palabra;
}
int Zoologico::verificarExistenciaHabitat(string nombreHabitat) {

    int verificar = 0;
    list<habitat*>::iterator habitas;
    for(habitas =listHabitat.begin(); habitas != listHabitat.end(); ++habitas){
        if ((*habitas)->getNombreHabitat()==nombreHabitat){
            verificar++;
        }
    }
    if (verificar == 0){
        return 0;
    }else{
        return 1;
    }
}

int Zoologico::verificarExistenciaClaseAlimentos(string claseAlimento) {
    int verificador = 0;
    list<Alimentos*>::iterator alimentos;
    for(alimentos = listAlimentos.begin(); alimentos != listAlimentos.end(); alimentos++){
        if((*alimentos)->getClaseAlimento() == claseAlimento){
            verificador++;
        }
    }
    if (verificador == 0){
        return 0;
    }else{
        return 1;
    }

}

void Zoologico::mostrarAnimales() {
    cout<<"||Animales||"<<endl;
    list<Animales*>::iterator animales;
    list<habitat*>::iterator habitas;
    for(habitas = listHabitat.begin(); habitas != listHabitat.end(); ++habitas) {
        cout<<"||Animales habitat "<<(*habitas)->getNombreHabitat()<<"||"<<endl;
        for (animales = listAnimales.begin(); animales != listAnimales.end(); ++animales) {
            if((*animales)->getHabitatAnimal() == (*habitas)->getNombreHabitat()){
                (*animales)->mostrarInfoAnimales();
            }
        }
    }
}

void Zoologico::animalesDePrueba() {

    Animales * a = new Animales("Tiger", 32, 20,"polar", "tigre blanco","carnivoro");
    agregarListaAnimales(a);
    Animales * b = new Animales("Tatiana", 32,15, "desertico", "conejo","herbivoro");
    agregarListaAnimales(b);
    Animales * c = new Animales("Mauricio", 32,18, "selvatico", "Tilapia","omnivoro");
    agregarListaAnimales(c);
    Animales * d = new Animales("Rogelio", 32,-12,"selvatico", "canguro","carnivoro");
    agregarListaAnimales(d);

    //Pruebas
    Trabajador trabajador1("Stiven",123,"masajista",5.3);
    Personas persona1("Johan", 12342);
    trabajador1.mostrarTrabajador();
    persona1.mostrarPersonas();
    //habitat
    Alimentos * alimentos1 = new Alimentos("aves""insectos""pescado""gusanos","carnivoro");
    Alimentos * alimentos2 = new Alimentos("hojas""corteza""flores""frutos","herbivoro");
    Alimentos * alimentos3 = new Alimentos("pescado""hojas""aves""frutos","omnivoro");
    agregarListaAlimentos(alimentos1);
    agregarListaAlimentos(alimentos2);
    agregarListaAlimentos(alimentos3);

    habitat * habitat1 = new habitat("desertico",20,30);
    agregarListaHabitat(habitat1);
    habitat * habitat2 = new habitat("selvatico",15,35);
    agregarListaHabitat(habitat2);
    habitat * habitat3 = new habitat("polar",-20,10);
    agregarListaHabitat(habitat3);
}

int Zoologico::recomendarHabitat(int temperatura) {
    list<habitat*>::iterator habitas;
    cout<<"||Recomendaciones de habitas||"<<endl;
    for(habitas =listHabitat.begin(); habitas != listHabitat.end(); ++habitas){
        if (temperatura >= (*habitas)->getTemperaturaMinimaHabitat() && temperatura <= (*habitas)->getTemperaturaMaximaHabitat()){
            cout<<endl<<"Habitat "<<(*habitas)->getNombreHabitat()<<" con temperatura minima de "<<(*habitas)->getTemperaturaMinimaHabitat()<<" y maxima de "<<(*habitas)->getTemperaturaMaximaHabitat()<<endl;
        }
    }
}

void Zoologico::mostrarAlimentos(){
    cout<<"||Clases de Alimentos||"<<endl;
    list<Alimentos*>::iterator alimentos;
    int contador =0;
    for(alimentos = listAlimentos.begin(); alimentos != listAlimentos.end();++alimentos){
        contador++;
        cout<<contador<<". "<<((*alimentos)->getAlimentos())<<" clase: "<<endl;

    }
}

void Zoologico::mostrarHabitas() {
    cout<<"||Habitas||"<<endl;
    cout<<"Estos son los habitas que hay actualmente:"<<endl;
    list<habitat*>::iterator habitas;
    for(habitas = listHabitat.begin(); habitas != listHabitat.end(); ++habitas){
        (*habitas)->mostrarInfoHabitat();
    }
}

void Zoologico::agregarListaAnimales(Animales * n) {
    this->listAnimales.push_back(n);
}

void Zoologico::agregarListaAlimentos(Alimentos *p) {
    this->listAlimentos.push_back(p);
}

void Zoologico::agregarListaHabitat(habitat *h) {
    this->listHabitat.push_back(h);
}


