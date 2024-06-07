/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   sinreceta.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 15:19
 */

#ifndef SINRECETA_H
#define SINRECETA_H

#include "medicamento.h"


class sinreceta:public medicamento{
public:
    sinreceta();
    virtual ~sinreceta();
    void SetNombre(char* nomb);
    void GetNombre(char* nomb) const;
    void SetDni(int dni);
    int GetDni() const;
    void leemedicamento(ifstream &arch);
    void imprimemedicamento(ofstream &arch);
    void aplicadescuento();
private:
    int dni;
    char *nombre;
};

#endif /* SINRECETA_H */

