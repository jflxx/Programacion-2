#include "MetodoPorIncrementos.h"

#define INCREMENTO 5
void aperturaDeArchivoParaLectura(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch.is_open()){
        cout << "El archivo " << nombArch << " no se pudo abrir correctamente" << endl;
        exit(1);
    }
    
}
void aperturaDeArchivoParaEscritura(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "El archivo " << nombArch << " no se pudo abrir correctamente" << endl;
        exit(1);
    }
    
}
char *leeCadena(ifstream &arch,int lim,char car){
    char cadena[400],*cad;
    arch.getline(cadena,lim,car);
    cad = new char [strlen(cadena)+1];
    strcpy(cad,cadena);
    return cad;
}
void CargaDePedidosYProductos(int **&cli_DniTelefono,char ***&pro_CodigoDescripcion,
            double **&pro_PrecioDescuento,char ***&ped_Codigo,int ***&ped_FechaCantidad,const char *nombArch){
    ifstream arch;
    aperturaDeArchivoParaLectura(arch,nombArch);
    char *codigoProd,*nombreProd;
    double precioProd,descuentoProd;
    int numDatosProd=0,capProd=0,cantPedido,dniCliente,fecha;
    pro_CodigoDescripcion = nullptr;
    pro_PrecioDescuento = nullptr;
    while(true){
        leerDatosProducto(arch,codigoProd,nombreProd,precioProd,cantPedido,descuentoProd);
        if(arch.eof()) break;
        if(numDatosProd==capProd)
            aumentarEspacios(pro_CodigoDescripcion,pro_PrecioDescuento,numDatosProd,capProd);
        leerDatosPedido(arch,dniCliente,fecha);
        
        if(!productoEncontrado(pro_CodigoDescripcion,codigoProd,numDatosProd))
            agregarProducto(pro_CodigoDescripcion[numDatosProd-1],pro_PrecioDescuento[numDatosProd-1],
                    codigoProd,nombreProd,precioProd,numDatosProd,descuentoProd);
        
    }
    
    for(int i=0;i<numDatosProd-1;i++){
            cout << (pro_CodigoDescripcion[i])[0] <<endl;
    }
    
}
void agregarProducto(char **&pro_CodigoDescripcion,double *&pro_PrecioDescuento,
        char *codigoProd,char *nombreProd,double precioProd,int &numDatosProd,double descuentoProd){
    pro_CodigoDescripcion = new char *[2]{};
    pro_PrecioDescuento = new double [2]{};
    pro_CodigoDescripcion[0] = codigoProd;
    pro_CodigoDescripcion[1] = nombreProd;
    pro_PrecioDescuento[0] = precioProd;
    pro_PrecioDescuento[1] = descuentoProd;
    numDatosProd++;
    
}
bool productoEncontrado(char ***pro_CodigoDescripcion,char *codigoProd,int numDatosProd){
    for(int i=0;i<numDatosProd-1;i++){
        if(compararCodigos(pro_CodigoDescripcion[i],codigoProd))
            return true;
    }
    return false;
}
bool compararCodigos(char **pro_CodigoDescripcion,char *codigoProd){
    char cadena1[7],cadena2[7];
    strcpy(cadena2,codigoProd);
    strcpy(cadena1,pro_CodigoDescripcion[0]);
    if(strcmp(cadena1,cadena2)==0)
        return true;
    return false;
}
void aumentarEspacios(char ***&pro_CodigoDescripcion,double **&pro_PrecioDescuento,int &numDatosProd,int &capProd){
    char ***auxPro_CodigoDescripcion;
    double **auxPro_PrecioDescuento;
    capProd+=INCREMENTO;
    if(pro_CodigoDescripcion==nullptr){
        pro_CodigoDescripcion = new char **[capProd]{};
        pro_PrecioDescuento = new double *[capProd]{};
//        for(int i=0;i<capProd;i++){
//            pro_CodigoDescripcion[i] = new char *[2]{};
//            pro_PrecioDescuento[i] = new double [2]{};
//        }
        numDatosProd=1;
    }else{
        auxPro_CodigoDescripcion = new char **[capProd]{};
        auxPro_PrecioDescuento = new double *[capProd]{};
        for(int i=0;i<numDatosProd;i++){
            auxPro_CodigoDescripcion[i] = pro_CodigoDescripcion[i];
            auxPro_PrecioDescuento[i] = pro_PrecioDescuento[i];
        }
        delete pro_CodigoDescripcion;
        delete pro_PrecioDescuento;
        pro_CodigoDescripcion = auxPro_CodigoDescripcion;
        pro_PrecioDescuento = auxPro_PrecioDescuento;
    }
}
void leerDatosProducto(ifstream &arch,char *&codigoProd,char *&nombreProd,double &precioProd,int &cantPedido,double &descuentoProd){
    codigoProd = leeCadena(arch,7,',');
    nombreProd = leeCadena(arch,60,',');
    if(arch.peek()=='%'){
        arch.get();
        arch >> descuentoProd;
        arch.get();
    }else
        descuentoProd = 0;
    arch >> cantPedido;
    arch.get();
    arch >> precioProd;
    arch.get();
}

void leerDatosPedido(ifstream &arch,int &dniCliente,int &fecha){
    int dd,mm,aa;
    char c;
    arch >> dniCliente;
    arch >> c >> dd >> c >> mm >> c >> aa;
    fecha = aa*10000 + mm*100 + dd;
    arch.get();
}