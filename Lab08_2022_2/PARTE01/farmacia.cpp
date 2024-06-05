/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   farmacia.cpp
 * Author: Afedo
 * 
 * Created on 28 de mayo de 2024, 18:14
 */

#include "farmacia.h"

farmacia::farmacia() {
}

farmacia::farmacia(const farmacia& orig) {
}

farmacia::~farmacia() {
}

void aperturaDeArchivosParaLeer(ifstream &arch,const char*nomb){
    arch.open(nomb,ios::in);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo ";
        exit(1);
    }
}

void farmacia::carmamedico(){
    ifstream arch;
    aperturaDeArchivosParaLeer(arch,"medicos.csv");
    int i=0;
    while(true){
        lmedico[i].leerDatos(arch);
        if(arch.eof()) break;
        i++;
    }
    lmedico[i].SetCodigo(0);
}

void farmacia::leerecetas(){
    ifstream arch;
    aperturaDeArchivosParaLeer(arch,"recetas.csv");
    int d,m,a,DNI,codMed,medicam,cantmedi,fecha,nC=0,nS=0;
    char nombre[60],c,espec[60];
    while(true){
        arch >> d >> c >> m >> c >> a >> c;
        if(arch.eof()) break;
        fecha = a*10000 + m*100 + d;
        arch >> DNI >> c;
        arch.getline(nombre,60,',');
        arch >> codMed;
        while(arch.peek()!='\n'){
            arch.get();
            arch >> medicam >> c >> cantmedi;
            if((medicam/10000)%2==0){ //necesita receta
                buscarMedico(codMed,espec);
                lconreceta[nC].colocar(codMed,cantmedi,fecha,medicam,espec);
                nC++;
            }else{
                lsinreceta[nS].colocar(DNI,cantmedi,fecha,medicam,nombre);
                nS++;
            }
        }
    }
    lconreceta[nC].SetCodmed(0);
    lsinreceta[nS].SetDni(0);
}

void farmacia::buscarMedico(int codMed,char *espec){
    for(int i=0; lmedico[i].GetCodigo()!=0 ;i++){
        if(codMed == lmedico[i].GetCodigo()){
            if(espec!=nullptr) delete []espec;
            lmedico[i].GetEspecialidad(espec);
        }
    }
}

void farmacia::imprimirrecetas(){
    ofstream arch("prueba.txt",ios::out);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo ";
        exit(1);
    }
    arch.precision(2);
    arch << fixed;
    
    for(int i=0; lsinreceta[i].GetCodigo()!=0 ;i++){ //sin receta
        lsinreceta[i].imprimir(arch);
    }
    
    for(int i=0; lconreceta[i].GetCodigo()!=0 ;i++){ //sin receta
        lconreceta[i].imprimir(arch);
    }
}
