#include "farmacia.h"

int main(int argc, char** argv) {
    farmacia ofarma;
    
    ofarma.carmamedico("medicos.csv");
    ofarma.leerecetas("recetas.csv");
    ofarma.imprimirrecetas("ReporteFinal.txt");
    return 0;
}

