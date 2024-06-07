/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   oferta.h
 * Author: Afedo
 *
 * Created on 5 de junio de 2024, 15:35
 */

#ifndef OFERTA_H
#define OFERTA_H
#include "medicamento.h"
#include "conreceta.h"
#include "sinreceta.h"
class oferta {
public:
    oferta();
    virtual ~oferta();
    void iniciarMedicamento(int cod_medi);
    void Leer(int codMedicamento,ifstream &arch);
    bool hayDato();
    void imprime(ofstream &arch);
    void actualiza();
private:
    class medicamento *poferta;
};

#endif /* OFERTA_H */

