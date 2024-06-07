#include "FuncionesApertura.h"

void aperturaDeArchivoParaEscribir(ofstream& arch, const char* nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "El archivo no se pudo abrir correctamente: "<<nombArch;
        exit(1);
    }
}

void aperturaDeArchivoParaLeer(ifstream& arch, const char* nombArch){
    arch.open(nombArch,ios::in);
    if(!arch.is_open()){
        cout << "El archivo no se pudo abrir correctamente: "<<nombArch;
        exit(1);
    }
}

