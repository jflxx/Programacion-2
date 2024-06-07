/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   medicamento.cpp
 * Author: Afedo
 * 
 * Created on 5 de junio de 2024, 15:14
 */

#include "medicamento.h"
#include "FuncionesApertira.h"

medicamento::medicamento() {
    total = 0;
    nombre = nullptr;
}
medicamento::~medicamento() {
    if(nombre != nullptr) delete []nombre;
}

void medicamento::SetTotal(double total) {
    this->total = total;
}

double medicamento::GetTotal() const {
    return total;
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
    if(nombre != nullptr) delete []nombre;
    nombre = new char [strlen(nomb)+1];
    strcpy(nombre,nomb);
}

void medicamento::GetNombre(char* nomb) const {
    if(nombre != nullptr) strcpy(nomb,nombre);
}

void medicamento::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::GetCodigo() const {
    return codigo;
}

void medicamento::leemedicamento(ifstream &arch){
    int d,m,a;
    char c;
    arch >> cantidad;
    arch >> c >> d >> c >> m >> c >> a >> c;
    SetFecha(a*10000 + m*100 + d);
    leerArchivoMedi();
}

void medicamento::leerArchivoMedi(){
    ifstream arch;
    aperturaDeArchivosParaLeer(arch,"medicamentos.csv");
    int codVerf,codi = GetCodigo();
    char nomb[50];
    double prec;
    while(true){
        arch >> codVerf;
        if(codVerf==codi)
            break;
        else 
            while(arch.get()!='\n');
    }
    arch.get();
    arch.getline(nomb,50,',');
    arch >> prec;
    SetNombre(nomb);
    SetPrecio(prec);
}

void medicamento::imprimemedicamento(ofstream &arch){
    char nombM[50];
    GetNombre(nombM);
    arch << left << setw(15) << GetFecha()
            << setw(10) << GetCodigo()
            << setw(50) << nombM
            << setw(5) << GetCantidad()
            << right << setw(9) << GetTotal();
}
void medicamento::aplicadescuento(){
    total = cantidad*precio*(0.9);
}