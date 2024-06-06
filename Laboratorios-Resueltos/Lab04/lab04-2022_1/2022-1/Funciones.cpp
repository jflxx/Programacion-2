#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "MetodoExacto.h"


void CargaDeClientes (int *&cli_DNI,char **&cli_Nombre,char *&cli_Categoria){
    ifstream arch("Clientes.csv",ios::in);
    if(not arch.is_open()){
        cout << "El archivo Clientes.csv no se pudo abrir correctamente"<<endl;
        exit(1);
    }
    int numDatos=0,buffCli_DNI[20],dni,telefono;
    char *buffCli_Nombre[20]{},buffCli_Categoria[20]{},categoria;
    while(true){
        arch >> dni;
        if(arch.eof()) break;
        arch.get();
        buffCli_Nombre[numDatos] = leerNombre(arch,categoria);
        arch >> telefono;
        buffCli_Categoria[numDatos] = categoria;
        buffCli_DNI[numDatos] = dni;
        numDatos ++;
    }
    
    cli_DNI = new int [numDatos+1]{};
    cli_Nombre = new char *[numDatos+1]{};
    cli_Categoria = new char [numDatos+1]{};
    
    for(int i=0;i<numDatos;i++){
        cli_Categoria[i] = buffCli_Categoria[i];
        cli_DNI[i] = buffCli_DNI[i];
        cli_Nombre[i] = buffCli_Nombre[i];
    }
    
}

char *leerNombre(ifstream &arch,char &categoria){
    char nombreYcategoria[60],*nombre;
    int longitud;
    arch.getline(nombreYcategoria,60,',');
    longitud = strlen(nombreYcategoria);
    if(nombreYcategoria[longitud-2] == ' '){
        nombre = new char[longitud-1];
        for(int i=0;i<longitud-2;i++)
            nombre[i] = nombreYcategoria[i];
        categoria = nombreYcategoria[longitud-1];
        nombre[longitud-2] = 0;
        return nombre;
    }
    nombre = new char[longitud+1];
    strcpy(nombre,nombreYcategoria);
    categoria = ' ';
    return nombre;
}

void ReporteDeClientes (int *cli_DNI,char **cli_Nombre,char *cli_Categoria){
    ofstream arch("ReporteDeClientes.csv",ios::out);
    if(not arch.is_open()){
        cout << "El archivo Clientes.csv no se pudo abrir correctamente"<<endl;
        exit(1);
    }
    int i=0;
    while(cli_DNI[i]!=0){
        arch <<left<<setw(10)<<cli_DNI[i]<<setw(50)<<cli_Nombre[i]<<cli_Categoria[i]<<endl;
        i++;
    }
}

void CargaDePedidosYProductos(int *&cli_DNI,int *&pro_Codigo,char **&pro_Descripcion,
                double *&pro_Descuento,double *&pro_Precio,int **&cli_CodigoProFechaPedido,double **&cli_CantidadPedido){
    ifstream arch("Pedidos.csv",ios::in);
    if(not arch.is_open()){
        cout << "El archivo Pedidos.csv no se pudo abrir correctamente"<<endl;
        exit(1);
    }
    
    int buffPro_Codigo[150]{},*buffCli_CodigoProFechaPedido[150]{},numDatos=0,fecha;
    double buffPro_Descuento[150]{},buffPro_Precio[150],*buffCli_CantidadPedido[150];
    char *buffPro_Descripcion[150];
    
    int cod,indice_buffCod,indice_buffDNI,dni;
    char descripcion[60]; 
    double porcentajeDesc,cantidad,precio;
    while(true){
        arch >> cod;
        if(arch.eof()) break;
        
        leerDatos(cod,arch,descripcion,porcentajeDesc,cantidad,precio,dni,fecha);
        indice_buffCod = buscarCod_Pro_Agregar(buffPro_Codigo,cod,descripcion,porcentajeDesc,precio,buffPro_Descripcion,
                buffPro_Descuento,buffPro_Precio,numDatos);
        
        agregarPedido(cantidad,fecha,cod,cli_DNI,buffCli_CodigoProFechaPedido, 
                buffCli_CantidadPedido,dni);
                
    }
    
}
void leerDatos(int cod,ifstream &arch,char *descripcion,double &porcentajeDesc,double &cantidad,
            double &precio,int &telefono,int &fecha){
    int dd,mm,aa;
    char c;
    arch.get();
    arch.getline(descripcion,60,',');
    porcentajeDesc = 0;
    if(arch.peek()=='%'){
        arch.get();
        arch >> porcentajeDesc;
        arch.get();
    }
    arch >> cantidad;
    arch.get();
    arch >> precio;
    arch.get();
    arch >> telefono;
    arch.get();
    arch >> dd >> c >> mm >> c >> aa;
    fecha = aa*10000 + mm*100 + dd;
}
int buscarCod_Pro_Agregar(int *buffPro_Codigo,int cod,char *descripcion,
        double porcentajeDesc,double precio,char **buffPro_Descripcion,
        double *buffPro_Descuento,double *buffPro_Precio,int &numDatos){
    int i=0;
    char *descrip;
    while(true){
        if(buffPro_Codigo[i] == cod)
            return i;
        if(buffPro_Codigo[i]==0)
            break;
        i++;
    }
    buffPro_Codigo[i] = cod;
    buffPro_Descuento[i] = porcentajeDesc;
    buffPro_Precio[i] = precio;
    descrip = new char [strlen(descripcion)+1];
    strcpy(descrip,descripcion);
    descrip[strlen(descripcion)] = 0;
    buffPro_Descripcion[i] = descrip;
    numDatos++;
    return i;
}

void agregarPedido(double cantidad,int fecha,int cod,int *&cli_DNI,int **buffCli_CodigoProFechaPedido,
        double **buffCli_CantidadPedido,int dni){
    int i,j;
    for(i=0;cli_DNI[i];i++){
        if(cli_DNI[i]==dni) break;
    }
    if(cli_DNI[i]==0) return;
    
    for(j=0; buffCli_CantidadPedido[j] ;j++);
    
    agregar(buffCli_CantidadPedido[i],buffCli_CodigoProFechaPedido[i],fecha,cod,j,cantidad);
}

void agregar(double *buffCli_CantidadPedido,int *buffCli_CodigoProFechaPedido,
                    int fecha,double cod, int j,double cantidad){
//    buffCli_CodigoProFechaPedido[0] = fecha; 
//    buffCli_CantidadPedido[1] = cantidad;
}