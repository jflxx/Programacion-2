#include "PilaConEnteros.h"

int cmpnumero(const void *a,const void *b){
    void **ai = (void**)a,**bi = (void**)b;
    int  *num1 = (int*)(*ai), *num2 = (int *)(*bi);
    return *num2-*num1;
}

void *leenumero(ifstream &arch){
    int dato,*ptrdato;
    arch >> dato;
    if(arch.eof()) return nullptr;
    ptrdato = new int;
    *ptrdato = dato;
    return ptrdato;
}

void imprimenumero(ofstream &arch,void *a){
    int *num = (int*)(a);
    arch << *num << endl;
}