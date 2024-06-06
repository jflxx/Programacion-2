/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: Afedo
 * 
 * Created on 28 de mayo de 2024, 18:06
 */

#include "medicamento.h"

medicamento::medicamento() {
    nombre = nullptr;
}

medicamento::medicamento(const medicamento& orig) {
}

medicamento::~medicamento() {
    if(nombre!=nullptr) delete []nombre;
}

void medicamento::SetFecha(int fecha) {
    this->fecha = fecha;
}

int medicamento::GetFecha() const {
    return fecha;
}

void medicamento::SetPrecio(double precio) {
    this->precio = precio;
}

double medicamento::GetPrecio() const {
    return precio;
}

void medicamento::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int medicamento::GetCantidad() const {
    return cantidad;
}

void medicamento::SetNombre(char* nomb) {
    if(nombre!=nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

char medicamento::GetNombre(char* nomb) const {
    strcpy(nomb,nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}
void aperturaDeArchivosParaLeer2(ifstream &arch,const char*nomb){
    arch.open(nomb,ios::in);
    if(!arch.is_open()){
        cout << "No se pudo abrir el archivo ";
        exit(1);
    }
}

void medicamento::leerMedicamento(int codMedicam, int cant,int fec){
    ifstream arch;
    aperturaDeArchivosParaLeer2(arch,"medicamentos.csv");
    int cod;
    char nomb[60];
    double prec;
    while(true){
        arch >> cod;
        if(arch.eof()) break;
        arch.get();
        if(cod==codMedicam){
            arch.getline(nomb,60,',');
            arch >> prec;
            SetCantidad(cant);
            SetCodigo(cod);
            SetFecha(fec);
            SetNombre(nomb);
            SetPrecio(prec);
//            cout << "e";
            break;
        }else{
            while(arch.get()!='\n');
        }   
    }
}

void medicamento::imprimir(ofstream &arch){
    char nomb[60];
    GetNombre(nomb);
    arch << left 
            << setw(14) << GetCodigo()
            << setw(40) << nomb
            << setw(5) << GetCantidad()
            << setw(10) << GetPrecio()
            << setw(10) << GetFecha();
}
