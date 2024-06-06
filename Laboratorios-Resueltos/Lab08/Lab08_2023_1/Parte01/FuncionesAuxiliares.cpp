#include"FuncionesAuxiliares.h"


void aperturaDeArchivosParaLeer(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch.is_open()){
        cout << "no se pudo abrir el archivo: "<<nombArch;
        exit(1);
    }
}
void aperturaDeArchivosParaEscribir(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "no se pudo abrir el archivo: "<<nombArch;
        exit(1);
    }
}

