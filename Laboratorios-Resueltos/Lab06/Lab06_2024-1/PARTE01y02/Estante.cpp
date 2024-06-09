/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Estante.cpp
 * Author: Afedo
 * 
 * Created on 8 de junio de 2024, 23:13
 */

#include "Estante.h"

Estante::Estante() {
    cantidad_libros = 0;
    codigo = nullptr;
}
Estante::~Estante() {
    if(codigo!=nullptr) delete []codigo;
}

void Estante::SetCantidad_libros(int cantidad_libros) {
    this->cantidad_libros = cantidad_libros;
}

int Estante::GetCantidad_libros() const {
    return cantidad_libros;
}

void Estante::SetAltura(int altura) {
    this->altura = altura;
}

int Estante::GetAltura() const {
    return altura;
}

void Estante::SetAnchura(int anchura) {
    this->anchura = anchura;
}

int Estante::GetAnchura() const {
    return anchura;
}

void Estante::SetCodigo(char* cod) {
    if(codigo!=nullptr) delete []codigo;
    codigo = new char [strlen(cod)+1];
    strcpy(codigo,cod);
}

void Estante::GetCodigo(char* cod) const {
    if(codigo!=nullptr) strcpy(cod,codigo);;
}

void operator >>(ifstream &arch,class Estante &estante){
    char codigo[4];
    int anchura,altura;
    
    arch.getline(codigo,4,',');
    if(arch.eof()) return;
    arch >> altura;
    arch.get();
    arch >> anchura;
    arch.get();
    
    estante.SetAltura(altura);
    estante.SetAnchura(anchura);
    estante.SetCodigo(codigo);
}


bool Estante::operator +=(class Libro &libro){
    if(hayEspacio(libro)){
        actualizarEspacios(libro);
        libro.SetColocado(true);
        libros[cantidad_libros] = libro;
        cantidad_libros++;
        return true;
    }
    return false;
}

bool Estante::hayEspacio(class Libro &libro){
    int anchoOcupado=0;
    if(libro.GetAlto()<=altura){ // entra en por lo menos en altura
        for(int i=0;i<cantidad_libros;i++){
            anchoOcupado+=libros[i].GetAncho();
        }
        if(anchura-anchoOcupado>=libro.GetAncho()){
            return true;
        }
    }
    return false;
}

void Estante::actualizarEspacios(class Libro &libro){
    int n=0;
    for(int i=0; i<altura*anchura ;i+=altura){ //buscar pos libre
        if(espacios[i].GetContenido()==' '){
            n = i;
            break;
        }
    }
    int cont;
    for(int i=0; i<libro.GetAncho() ;i++){
        cont=0;
        for(int j=0;j<altura;j++){
            if(cont<libro.GetAlto()){
                espacios[n].SetContenido('*');
            }
            n++;
            cont++;
        }
    }
}

void operator <<(ofstream &arch,class Estante &estante){
    char cod[4];
    estante.GetCodigo(cod);
    arch << left << setw(17) << "Codigo Estante: " << setw(7) << cod
            << setw(20) << "Cantidad de Libros: " << estante.GetCantidad_libros()<<endl;
    arch << setw(17) << "Anchura del Estante: " << setw(7) << estante.GetAnchura()
            << setw(20) << "Altura del Estante: " << setw(7) << estante.GetAltura()<<endl;
    estante.imprimeLinea(arch,50,'-');
    
    estante.imprimirEstante(arch);
    arch << endl;
    
     arch << left << setw(10) << "CODIGO"
            << setw(25) << "NOMBRE" 
            << right
            << setw(7) << "ANCHO"
            << setw(8) << "ALTO" << endl;
    estante.imprimeLinea(arch,50,'.');
    estante.imprimirLibros(arch);
    estante.imprimeLinea(arch,50,'-');
}

void Estante::imprimirEstante(ofstream &arch){
    for(int i=altura; i>0 ;i--){
        for(int j=i-1; j<altura*anchura ;j+=altura){
            arch << espacios[j];
        }
        arch << endl;
    }
}

void Estante::imprimeLinea(ofstream &arch,int lim,char c){
    for(int i=0; i<lim ;i++)
        arch << c;
    arch << endl;
}

void Estante::imprimirLibros(ofstream &arch){
    for(int i=0; i<cantidad_libros ;i++)
        arch << libros[i];
}