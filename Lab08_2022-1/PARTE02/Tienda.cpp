/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Tienda.cpp
 * Author: Afedo
 * 
 * Created on 30 de mayo de 2024, 18:23
 */

#include "Tienda.h"

Tienda::Tienda() {
//    for(int i=0;i<200;i++)
//        lpedidos[i].SetCodigo(0);
//    for(int i=0;i<30;i++)
//        lclientes[i].SetDni(0);
}

Tienda::Tienda(const Tienda& orig) {
}

Tienda::~Tienda() {
}
//pedido: codigo,cantidad solicitada, dni del cliente, Fecha del pedido
void Tienda::carga(){
    ifstream arch;
    aperturaDeArchivoParaLeer(arch,"pedidos3.csv");
    int nP=0,nC=0;
    while(true){
        lpedidos[nP].leer(arch);
        if(arch.eof()) break;;
        nP++;
    }
    lpedidos[nP].SetCodigo(0);
    ifstream archCliente;
    aperturaDeArchivoParaLeer(archCliente,"clientes2.csv");
    while(true){
        lclientes[nC].leer(archCliente);
        if(archCliente.eof()) break;;
        nC++;
    }
    lclientes[nC].SetDni(0);
    
    
}

void Tienda::muestra(){
    ofstream arch;
    aperturaDeArchivoParaEscribir(arch,"PruebaFinal.txt");
    
    arch.precision(2);
    arch << fixed;
    arch << left 
            << setw(10) << "Fecha" 
            << setw(10) << "Codigo"
            << setw(60) << "Descripcion del Prod."
            << setw(10) << "Cant." 
            << setw(10) << "Precio" 
            << setw (10) << "Total"
            << setw (30) << "Observaciones" << endl;
    int nP=0;
    while(lpedidos[nP].GetCodigo()!=0){
        lpedidos[nP].imprimir(arch);
        nP++;
    }
}

void Tienda::actualiza(int parametro){
    char tipo;
    for(int i=0; lpedidos[i].GetCodigo()!=0 ;i++){
        tipo = encontrarTipoCliente(lpedidos[i].GetDni());
        if(4==lpedidos[i].GetCodigo()/100000 && lpedidos[i].GetStock()>=parametro){
            lpedidos[i].actualiza(tipo);
        }
//        cout << tipo << endl;
    }
}

char Tienda::encontrarTipoCliente(int ID){
    for(int i=0; lclientes[i].GetDni()!=0 ;i++){
        if(lclientes[i].GetDni()==ID)
            return lclientes[i].GetCategoria();
    }
    return '0';
}

