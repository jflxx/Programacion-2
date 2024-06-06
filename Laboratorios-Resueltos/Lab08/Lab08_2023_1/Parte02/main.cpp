#include <iostream>

using namespace std;
#include "Tesoreria.h"

int main(int argc, char** argv) {
    Tesoreria caja;
    
    caja.cargaescalas();
    caja.cargaalumnos();
    caja.actualiza(20);
    caja.imprime();
    
    return 0;
}

