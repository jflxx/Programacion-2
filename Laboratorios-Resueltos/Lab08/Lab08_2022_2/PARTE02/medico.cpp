#include "medico.h"

medico::medico() {
    nombre = nullptr;
    especialidad = nullptr;
}

medico::medico(const medico& orig) {
}

medico::~medico() {
    if(nombre != nullptr) delete []nombre;
    if(especialidad!=nullptr) delete []especialidad;
}

void medico::SetEspecialidad(char* espec) {
    if(especialidad!=nullptr)delete []especialidad;
    especialidad = new char [strlen(espec)+1];
    strcpy(especialidad,espec);
}

char medico::GetEspecialidad(char* espec) const {
    strcpy(espec,especialidad);
}

void medico::SetNombre(char* nomb) {
    if(nombre!=nullptr)delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char medico::GetNombre(char* nomb) const {
    strcpy(nomb,nombre);
}

void medico::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medico::GetCodigo() const {
    return codigo;
}

void medico::leerDatos(ifstream &arch){
    int cod;
    char nomb[60],especia[60];
    
    arch >> cod;
    if(arch.eof()) return;
    arch.get();
    arch.getline(nomb,60,',');
    arch.getline(especia,60,'\n');
    SetCodigo(cod);
    SetEspecialidad(especia);
    SetNombre(nomb);
}

