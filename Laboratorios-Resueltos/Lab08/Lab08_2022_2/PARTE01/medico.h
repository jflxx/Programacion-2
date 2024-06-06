#ifndef MEDICO_H
#define MEDICO_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;


class medico {
public:
    medico();
    medico(const medico& orig);
    virtual ~medico();
    void SetEspecialidad(char* espec);
    char GetEspecialidad(char* espec) const;
    void SetNombre(char* nomb);
    char GetNombre(char* nomb) const;
    void SetCodigo(int codigo);
    int GetCodigo() const;
    void leerDatos(ifstream &arch);
private:
    int codigo;
    char *nombre;
    char *especialidad;
};

#endif /* MEDICO_H */

