/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   PedidoEspecial.h
 * Author: Afedo
 *
 * Created on 6 de junio de 2024, 22:54
 */

#ifndef PEDIDOESPECIAL_H
#define PEDIDOESPECIAL_H

#include "Pedido.h"


class PedidoEspecial: public Pedido{
public: 
    void lee(ifstream &arch);
    void imprime(ofstream &arch) const;
    void actualiza();
private:
    double descuento;
};

#endif /* PEDIDOESPECIAL_H */

