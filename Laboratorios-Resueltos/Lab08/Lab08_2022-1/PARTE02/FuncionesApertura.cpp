#include "FuncionesApertura.h"


void aperturaDeArchivoParaLeer(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo "<<nombArch;
        exit(1);
    }
}

void aperturaDeArchivoParaEscribir(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo "<<nombArch;
        exit(1);
    }
}
