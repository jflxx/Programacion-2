/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   conreceta.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 15:18
 */

#ifndef CONRECETA_H
#define CONRECETA_H

#include "medicamento.h"

class conreceta:public medicamento{
public:
    conreceta();
    virtual ~conreceta();
    void SetEspecialidad(char* espe);
    void GetEspecialidad(char* espe) const;
    void SetCodmed(int codmed);
    int GetCodmed() const;
    void leemedicamento(ifstream &arch);
    void imprimemedicamento(ofstream &arch);
    void aplicadescuento();
private:
    int codmed;
    char *especialidad;
};

#endif /* CONRECETA_H */

