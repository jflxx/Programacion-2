#include "FuncionesRegistro.h"
#include "BibliotecaPilaGenerica.h"

char *leeCadena(ifstream &arch,int lim, char c){
    char cadena[500],*cad;
    arch.getline(cadena,lim,c);
    cad = new char [strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}
void imprimirLinea(ofstream &arch,char c,int lim){
    for(int i=0; i<lim ;i++)
        arch << c;
    arch << endl;
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

int cmpregistro(const void*a,const void*b){
    void **ai = (void**)a,**bi = (void**)b;
    void **regA = (void**)(*ai),**regB = (void**)(*bi);
    double *peso1 = (double*)(regA[2]), *peso2 = (double*)(regB[2]);
    return  *peso2-*peso1;
}

void *leeregistro(ifstream &arch){
    void **registro;
    int cod,*ptrcod=new int;
    char *nombre;
    double prec,*ptrprec = new double;
    registro = new void *[3]{};
    arch >> cod;
    arch.get();
    nombre = leeCadena(arch,60,',');
    arch >> prec;
    *ptrcod = cod;
    *ptrprec = prec;
    registro[0] = ptrcod;
    registro[1] = nombre;
    registro[2] = ptrprec;
    return registro;
}

void imprimepila2(void *pilafin,void (*imprime)(ofstream &arch,void*),const char *nombArch){
    ofstream arch(nombArch,ios::out);
    void *rec, **auxPila = (void**)pilafin;
    arch.precision(2);
    arch << fixed;
    int n = (*(int*)(auxPila[1]));
    arch << left 
            << setw(15) << "Codigo"
            << setw(60) << "Descripcion del producto"
            << "Peso Caja" << endl;
    imprimirLinea(arch,'=',120);
    for(int i=0; i<n ;i++){
        rec = pop(pilafin);
        imprime(arch,rec);
    }
}

void imprimeregistro(ofstream &arch,void *reg){
    void **registro = (void**)reg;
    
    arch << left 
            << setw(15) << *(int*)(registro[0])
            << setw(60) << (char*)(registro[1])
            << *(double*)(registro[2]) << endl;
}