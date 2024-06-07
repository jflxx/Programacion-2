
#include "Boleta.h"

Boleta::Boleta() {
    pboleta = nullptr;
}
Boleta::~Boleta() {
    if(pboleta!=nullptr) delete pboleta;
}

void Boleta::asignaMemoria(char tipo){
    switch (tipo){
        case 'P':
            pboleta = new class Presencial;
            break;
        case 'S':
            pboleta = new class Semipresencial;
            break;
        case 'V':
            pboleta = new class Virtual;
            break;
    }
}

void Boleta::leeDatos(ifstream &arch){
    pboleta->lee(arch);
}

bool Boleta::hayDato(){
    return pboleta!=nullptr? true:false;
}

void Boleta::imprimeDatos(ofstream &arch){
    pboleta->imprime(arch);
}
void Boleta::actualizar(double valorC){
    pboleta->actualizatotal(valorC);
}

int Boleta::devolverEscala(){
    return pboleta->GetEscala();
}