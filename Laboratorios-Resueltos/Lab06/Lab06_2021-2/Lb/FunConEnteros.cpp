
#include "FunConEnteros.h"

void *leenumero(ifstream &arch){
    int dato,*ptrdato;
    arch >> dato;
    if(arch.eof()) return nullptr;
    ptrdato = new int;
    *ptrdato = dato;
    return ptrdato;
}

int prioridadNumero(void *dato){
    int *prioridad;
    prioridad = (int*)dato;
    if(*prioridad<50) return 3;
    if(*prioridad>=50 && *prioridad<=100) return 2;
    if(*prioridad>100) return 1;
}

void imprimirnum(void *cola, const char *nomarch){
    int *num, i = 0; 
    void *dato, **rec;
    void **aux = (void **)cola;
    
    num = new int; 
    ofstream arch(nomarch, ios::out); 
    
    rec = (void **)(aux[0]);
    while(rec){
        dato = rec[0];
        num = (int*) dato; 
        arch << *num << endl; 
        rec = (void **)(rec[1]); 
    }
    
    while(i<3){
        rec = (void **)(aux[i+1]); 
        dato = rec[0];
        num = (int*) dato; 
        arch << "Prioridad " << i + 1 << ": " << *num << endl;  
        i++; 
    }
    
    delete num; 
}