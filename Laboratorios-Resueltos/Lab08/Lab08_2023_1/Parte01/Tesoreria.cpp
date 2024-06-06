#include "Tesoreria.h"

Tesoreria::Tesoreria() {
}

Tesoreria::Tesoreria(const Tesoreria& orig) {
}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas(){
    ifstream arch;
    aperturaDeArchivosParaLeer(arch,"escalas.csv");
    int escala;
    double cred;
    while(true){
        arch >> escala;
        if(arch.eof()) break;
        arch.get();
        arch >> cred;
        lescala[escala-1].SetCodigo(escala);
        lescala[escala-1].SetPrecio(cred);
    }
}
void Tesoreria::cargaalumnos(){
    ifstream arch;
    aperturaDeArchivosParaLeer(arch,"Alumnos.csv");
    int nP=0,nS=0,nV=0;
    char T;
    while(true){
        arch >> T;
        if(arch.eof()) break;
        arch.get();
        switch (T){
            case 'P':
                lpresencial[nP].leerDatos(arch);
                nP++;
                break;
            case 'S':
                lsemipresencial[nS].leerDatos(arch);
                nS++;
                break;
            case 'V':
                lvirtual[nV].leerDatos(arch);
                nV++;
                break;
        }
        arch.get();
    }
    lpresencial[nP].SetCodigo(0);
    lvirtual[nV].SetCodigo(0);
    lsemipresencial[nS].SetCodigo(0);
}

void Tesoreria::actualiza(int cred){
    int esc;
    double precioEsc;
    for(int i=0; lpresencial[i].GetCodigo() ;i++){ //presencial
        esc = lpresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lpresencial[i].actualiza(cred*precioEsc);
    }
    
    for(int i=0; lsemipresencial[i].GetCodigo() ;i++){ //semipresencial
        esc = lsemipresencial[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lsemipresencial[i].actualiza(cred*precioEsc);
    }
    
    for(int i=0; lvirtual[i].GetCodigo() ;i++){ //virtual
        esc = lvirtual[i].GetEscala();
        precioEsc = lescala[esc-1].GetPrecio();
        lvirtual[i].actualiza(cred*precioEsc);
    }
}


void Tesoreria::imprime(){
    ofstream arch;
    aperturaDeArchivosParaEscribir(arch,"Prueba.txt");
    arch.precision(2);
    arch << fixed;
    
    for(int i=0; lpresencial[i].GetCodigo() ;i++){ //presencial
        lpresencial[i].imprime(arch);
    }
    
    for(int i=0; lsemipresencial[i].GetCodigo() ;i++){ //semipresencial
        lsemipresencial[i].imprime(arch);
    }
    
    for(int i=0; lvirtual[i].GetCodigo() ;i++){ //virtual
        lvirtual[i].imprime(arch);
    }
    
}