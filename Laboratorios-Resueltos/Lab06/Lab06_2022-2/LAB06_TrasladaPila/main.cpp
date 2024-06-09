
#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>
using namespace std;
#include "BibliotecaPilaGenerica.h"
#include "PilaConEnteros.h"
#include "FuncionesRegistro.h"

int main(int argc, char** argv) {
    void *arreglo,*pilaini,*pilafin;
     
//    cargaarreglo(arreglo,cmpnumero,leenumero,"numeros.txt");
//    cargapila(pilaini,arreglo);
//    muevepila(pilaini,pilafin);
//    imprimepila(pilafin,imprimenumero,"repnumeros.txt");   
    
    
    cargaarreglo(arreglo,cmpregistro,leeregistro,"medicinas.csv");
    cargapila(pilaini,arreglo);
    muevepila(pilaini,pilafin);
    imprimepila2(pilafin,imprimeregistro,"repmedicinas.txt");
    
    
    
    
    return 0;
}

