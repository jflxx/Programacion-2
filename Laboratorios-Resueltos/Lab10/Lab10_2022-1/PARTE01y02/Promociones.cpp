/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Promociones.cpp
 * Author: Afedo
 * 
 * Created on 6 de junio de 2024, 23:08
 */

#include "Promociones.h"
#include "FuncionesApertura.h"

void Promociones::leepedidos(){
    ifstream arch;
    aperturaDeArchivosParaLeer(arch,"pedidos5.csv");
    
    class Pedido *ped;
    while(true){
        ped = leePedido(arch);
        if(arch.eof()) break;
        Lpedidos.insertar(ped);
    }
}

void Promociones::imprimepedidos(){
    ofstream arch;
    aperturaDeArchivosParaEscribir(arch,"prueba.txt");
    arch.precision(2);
    arch << fixed;
    Lpedidos.imprimeLista(arch);
}

// cod,desc y/o flete, nombre, cantidad, monto del ped, dni del cli, fecha del ped,
Pedido *Promociones::leePedido(ifstream &arch){
    class Pedido *ped;
    int cod;
    arch >> cod;
    arch.get();
    if(arch.eof()) return nullptr;
    if(cod < 400000){
        ped = new class PedidoEspecial;
    }else if(400000 <= cod && cod < 600000){
        ped = new class PedidoUsual;
    }else
        ped = new class PedidoEventual;
    ped->SetCodigo(cod);
    ped->lee(arch);
}

void Promociones::actualizapedidos(){
    ifstream arch;
    
    Lpedidos.actualiza(arch);
}