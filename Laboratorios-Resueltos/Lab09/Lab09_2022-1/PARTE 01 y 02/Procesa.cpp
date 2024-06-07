/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Procesa.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 12:45
 */

#include "Procesa.h"
#include "FuncionesApertura.h"

void Procesa::carga(){
    //CARGA PEDIDOS
    ifstream arch;
    aperturaDeArchivoParaLeer(arch,"pedidos4.csv");
    int nP=0;
    int cod;
    while(true){
        arch >> cod;
        if(arch.eof()) break;
        lpedidos[nP].leerPed(arch,cod);
        nP++;
    }
    lpedidos[nP].setCodigo(0);
    //CARGA PEDIDOS
    ifstream arch2;
    aperturaDeArchivoParaLeer(arch2,"clientes3.csv");
    int nC=0;
    char cat;
    while(true){
        arch2 >> cat;
        if(arch2.eof()) break;
        ldeudor[nC].asignarCate(cat);
        ldeudor[nC].leerC(arch2);
        nC++;
    }
}

void Procesa::muestra(){
    ofstream arch;
    aperturaDeArchivoParaEscribir(arch,"ReporteDeDeudas.txt");
    arch.precision(3);
    arch << fixed;
    
    arch << "REPORTE DE DEUDAS" <<endl;
    imprimirLinea(arch,80,'=');
    for(int i=0; ldeudor[i].hayDato() ;i++){
        ldeudor[i].imprime(arch);
        arch << endl;
    }
}

void Procesa::actualiza(){
    int indiceCli;
    double tot;
    
    for(int i=0; lpedidos[i].hayDato() ;i++){
        indiceCli = buscarIndiceCli(lpedidos[i].getDni());
        if(indiceCli != -1)
            ldeudor[indiceCli].actualiza(lpedidos[i].getTotal());
    }
    
}

int Procesa::buscarIndiceCli(int dni){
    for(int i=0; ldeudor[i].hayDato() ;i++){
        if(ldeudor[i].devolverDni()==dni) return i;
    }
    return -1;
}

void Procesa::imprimirLinea(ofstream &arch,int lim, char c){
    for(int i=0; i<lim ;i++)
        arch << c;
    arch << endl;
}