
#include "BibGenerica.h"

void crearcola(void *&cola,const char *nombArch,
            void *(*leer)(ifstream &arch),int (*prioridad)(void*)){
    void **auxcola,*reg;
    ifstream arch(nombArch,ios::in);
    
    auxcola = new void*[5]{};
    auxcola[0] = nullptr;
    auxcola[1] = nullptr;
    auxcola[2] = nullptr;
    auxcola[3] = nullptr;
    auxcola[4] = nullptr;
    cola = auxcola;
    
    while(true){
        reg = leer(arch);
        if(arch.eof()) return;
        encolar(cola,reg,prioridad);
    }
}

void encolar(void *&cola,void *dato,int (*obtieneprioridad)(void*)){
    void **aux = (void**)cola,**sig;
    void **nuevo,**rec;
    int p1;
    nuevo = new void*[2]{};
    nuevo[0] = dato;
    nuevo[1] = nullptr;
    
    p1 = obtieneprioridad(dato);
    
    
    if(colaVacia(cola)){
        aux[0] = nuevo;
        aux[p1] = nuevo; 
        aux[4] = nuevo;
        return;
    }
    
    if(p1==1){
        if(aux[p1] == nullptr){
            rec = (void**)(aux[0]);
            nuevo[1] = rec;
            aux[0] = nuevo;
            aux[1] = nuevo;
        }else{
            rec = (void**)(aux[1]);
            if(rec[1] == nullptr){
                aux[4] = nuevo;
            }else{
                sig = (void**)(rec[1]);
                nuevo[1] = sig;
            }
            rec[1] = nuevo;
            aux[1] = nuevo;
        }
    }
    if(p1==2){
        if(aux[2] == nullptr){
            if(aux[1] == aux[4]){
                rec = (void**)(aux[4]);
                rec[1] = nuevo;
                aux[4] = nuevo;
                aux[2] = nuevo;
            }else if(aux[3]==aux[4]){
                if(aux[1]==nullptr){
                    rec = (void**)(aux[0]);
                    nuevo[1] = rec;
                    aux[p1] = nuevo;
                    aux[0] = nuevo;
                }else{
                    rec = (void**)(aux[1]);
                    nuevo[1] = rec[1];
                    rec[1] = nuevo;
                    aux[p1] = nuevo;
                }
            }
        }else{
            rec = (void**)(aux[2]);
            if(aux[p1] == aux[4]){ // seria la nueva cola
                rec[1] = nuevo;
                aux[4] = nuevo;
            }else{
                sig = (void**)(rec[1]);
                rec[1] = nuevo;
                nuevo[1] = sig;
            }
            aux[p1] = nuevo;
        }
        
    }
    if(p1==3){
        rec = (void**)(aux[4]);
        rec[1] = nuevo;
        aux[4] = nuevo;
        aux[p1] = nuevo;
    }
}

int colaVacia(void *cola){
    void **aux = (void**)cola;
    return aux[0] == nullptr;
}

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


void *desencola(void *cola){
    
    if(colaVacia(cola)) return nullptr;
    
    void **aux = (void**)cola;
    void **colaini = (void**)aux[0];
    void **penultimo;
    if(aux[0] == aux[4]){
        aux[0] = nullptr;
        aux[4] = nullptr;
    }else{
        penultimo = (void**)colaini[1];
        aux[0] = penultimo;
        colaini[1] == nullptr;
    }
    void *dato = colaini[0];
    
    delete colaini;
    return dato;
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
