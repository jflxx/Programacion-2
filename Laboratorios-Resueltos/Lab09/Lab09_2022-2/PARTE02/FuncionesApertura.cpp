#include "FuncionesApertira.h"

void aperturaDeArchivosParaEscribir(ofstream& arch, const char* nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo: ";
        exit(1);
    }
}
void aperturaDeArchivosParaLeer(ifstream& arch, const char* nombArch){
    arch.open(nombArch,ios::in);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo: ";
        exit(1);
    }
}

