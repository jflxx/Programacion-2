#include "FuncionesPila.h"
#include <stdlib.h>

//void imprimirArreglo(void *arr){
//    void **arreglo = (void**)arr;
//    
//    for(int i=0; arreglo[i] ;i++)
//        cout << *(int*)(arreglo[i]) << endl;
//}

void hanoi(int n,void *&pilaini,void *&pilafin,void *&aux){
    if(n==0) return;
    hanoi(n-1,pilaini,aux,pilafin);
    push(pilafin,pop(pilaini));
    hanoi(n-1,aux,pilafin,pilaini);
}

void cargaarreglo(void *&arr,int (*cmp)(const void*,const void*),
        void *(*lee)(ifstream &arch),const char *nombArch){
    ifstream arch(nombArch,ios::in);
    void **auxArreglo = new void*[200]{}, *reg;
    int nd=0;
    while(true){
        reg = lee(arch);
        if(arch.eof()) break;
        auxArreglo[nd] = reg;
        nd++;
    }
    
    void **aux = new void*[nd+1]{};
    for(int i=0; i<nd ;i++){
        aux[i] = auxArreglo[i];
    }
    delete auxArreglo;
    arr = aux;
    qsort(arr,nd,sizeof(void *),cmp);
}

void cargapila(void *&pila,void *&arr){
    void **auxPila,*dato,**arreglo = (void**)arr;
    int *ptrnum = new int;
    *ptrnum = 0;
    auxPila = new void *[2]{};
    auxPila[0] = nullptr;
    auxPila[1] = ptrnum;
    pila = auxPila;
    
    
    for(int i=0;arreglo[i];i++){
        dato = arreglo[i];
        push(pila,dato);
    }
}

void push(void *&pila,void *dato){
    void **aux = (void**)pila;
    void **nuevo,**rec;
    int *ptrnum = (int*)(aux[1]);
    nuevo = new void*[2]{};
    nuevo[0] = nullptr;
    nuevo[1] = dato;
     
    if(pilavacia(pila)){
        aux[0] = nuevo;
        (*ptrnum)++;
        return;
    }
    rec = (void**)(aux[0]);
    nuevo[0] = rec;
    aux[0] = nuevo;
    (*ptrnum)++;
}

bool pilavacia(void *pila){
    void **auxPila = (void**)pila;
    if(auxPila[0]==nullptr) return true;
    return false;
}

void imprimepila(void *pilaIni,void (*imprimenumero)(ofstream &arch,void*),const char*nombArch){
    ofstream arch(nombArch,ios::out);
    arch.precision(0);
    arch.fixed;
    void **pila = (void**)pilaIni;
    void **nuevo =(void**)(pila[0]);
    int n=  (*(int*)(pila[1]));
    for(int i=0; i<n ;i++){
        imprimenumero(arch,nuevo[1]);
        nuevo = (void**)(nuevo[0]);
    }
}

void *pop(void *&pila){
    void **auxPila = (void**)pila;
    void **rec = (void**)(auxPila[0]);
    auxPila[0] = rec[0];
    int *ptrnum = (int*)(auxPila[1]);
    (*ptrnum)--;
    return rec[1];
}

void muevepila(void *&pilaini,void *&pilafin){
    void **orig =(void**)pilaini;
    void *auxiliar,**fin;
    void **aux = (void**)auxiliar;
    int n = *(int*)(orig[1]),*ptrnum=new int;
    *ptrnum = 0;
    
    aux = new void*[2]{};
    aux[0] = nullptr;
    aux[1] = ptrnum;
    auxiliar = aux;
    fin = new void*[2]{};
    fin[0] = nullptr;
    fin[1] = ptrnum;
    pilafin = fin;
    hanoi(n, pilaini,pilafin,auxiliar);
    
    
}


