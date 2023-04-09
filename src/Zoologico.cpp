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
    int verificar = 0;
    list<habitat*>::iterator habitas;
    for(habitas =listHabitat.begin(); habitas != listHabitat.end(); ++habitas){
        if ((*habitas)->getNombreHabitat()==nombreHabitat){
            verificar++;
        }
    }
    if (verificar == 0){
        if(nombreHabitat == "polar" || nombreHabitat == "desertico" || nombreHabitat == "selvatico" || nombreHabitat == "acuatico"){
            habitat * ptempHabitat = new habitat(nombreHabitat);
            listHabitat.push_back(ptempHabitat);
        }else{
            cout<<"Lo sentimos, este habitat no esta definida en nuestra base de datos."<<endl;
        }
    }else{
        cout << "Lo sentimos, este habitat ya esta registrado en nuestro zoologico." << endl;
    }
}
void Zoologico::agregarAnimal() {
    string nombreAnimal,habitat,especie,claseDeAlimentacion;
    int edadAnimal;
    int limiteCaracteres = 15;

    cout<<endl<<"Ingrese en nombre del animal: ";
    //cin>>nombreAnimal;
    cin.ignore();
    getline(cin,nombreAnimal);


    if(nombreAnimal.length() > limiteCaracteres){
        throw out_of_range("El nombre excedio el limite de caracteres");
    }
    cout<<"nombre animal: "<<nombreAnimal<<endl;

    cout<<endl;

    //obtener especie del animal.
    cout<<endl<<"Ingrese la especie del animal:";
    cin>>especie;
    getline(cin, especie);
    if(especie.length() > limiteCaracteres){
        throw out_of_range("La especie excedio el limite de caracteres");
    }


    //Mostrar habitas recomendadas
    mostrarHabitas();
    cout<<endl<<"Escriba el habitat exactamente del animal: ";
    cin.ignore();
    getline(cin,habitat);
    cout<<"habitat : "<<habitat<<endl;
    if(habitat.length() > limiteCaracteres){
        throw out_of_range("El habitat excedio el limite de caracteres");
    }
    habitat = palabraMinuscula(habitat);
    if (verificarExistenciaHabitat(habitat)== 1){
        cout<<endl<<"||El habitat que ingresaste es correcto||"<<endl;
    }else{
        cout<<"||El habitat que ingresaste no es correcto e iras al menu nuevamente||"<<endl;
        //menu();
    }
    cout<<"La palabra minimizada es: "<<habitat<<endl;

    //Obtener la clase alimentacion
    cout<<endl<<"||Tipos de alimentacion||"<<endl<<"1. carnivoros"<<endl<<"2. herbivoros"<<endl<<"3. omnivoros"<<"Ingrese exactamente el tipo de alimento: ";
    cin.ignore();
    getline(cin,claseDeAlimentacion);

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
        cout<<"Este habitat no esta definida"<<endl;
        return 0;
    }else{
        return 1;
    }
}

void Zoologico::mostrarAnimales() {
    cout<<"||Animales||"<<endl;
    list<Animales*>::iterator animales;
    for(animales = listAnimales.begin(); animales != listAnimales.end(); ++animales){
        (*animales)->mostrarInfoAnimales();
    }
}

void Zoologico::animalesDePrueba() {

    Animales * a = new Animales("Tiger", 32, "invierno", "tigre blanco","carnivoro");
    agregarListaAnimales(a);
    Animales * b = new Animales("Tatiana", 32, "calor", "conejo","herbivoro");
    agregarListaAnimales(b);
    Animales * c = new Animales("Mauricio", 32, "calor", "Tilapia","omnivoro");
    agregarListaAnimales(c);
    Animales * d = new Animales("Rogelio", 32, "invierno", "canguro","carnivoro");
    agregarListaAnimales(d);

    //Pruebas

    Trabajador trabajador1("Stiven",123,"masajista",5.3);
    Personas persona1("Johan", 12342);
    trabajador1.mostrarTrabajador();
    persona1.mostrarPersonas();
    //habitat
    Alimentos * alimentos1 = new Alimentos("aves""insectos""pescado""gusanos","carnivoro",23);
    Alimentos * alimentos2 = new Alimentos("hojas""corteza""flores""frutos","herbivoro",14);
    Alimentos * alimentos3 = new Alimentos("pescado""hojas""aves""frutos","omnivoro",10);
    agregarListaAlimentos(alimentos1);
    agregarListaAlimentos(alimentos2);
    agregarListaAlimentos(alimentos3);

    habitat * habitat1 = new habitat("desertico");
    agregarListaHabitat(habitat1);
    habitat * habitat2 = new habitat("selvatico");
    agregarListaHabitat(habitat2);
    habitat * habitat3 = new habitat("polar");
    agregarListaHabitat(habitat3);
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


