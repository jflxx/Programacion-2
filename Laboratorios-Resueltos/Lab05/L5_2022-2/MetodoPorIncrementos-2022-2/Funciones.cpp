#include "MetodoPorIncrementos.h"
#define INCREMENTO 5

void aperturaDeArchivoParaLeer(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch.is_open()){
        cout << "El archivo "<< nombArch << " no se pudo abrir correctamente" << endl;
        exit(1);
    }
}

void aperturaDeArchivoParaEscribir(ofstream &arch,const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch.is_open()){
        cout << "El archivo "<< nombArch << " no se pudo abrir correctamente" << endl;
        exit(1);
    }
}

char *leeCadena(ifstream &arch,int max,char lim){
    char cadena[200],*cad;
    
    arch.getline(cadena,max,lim);
    cad = new char [strlen(cadena)+1];
    strcpy(cad,cadena);

    return cad;
}
void imprimirLinea(ofstream &arch,char car,int lim){
    for(int i=0; i<lim ; i++)
        arch << car;
    arch << endl;
}

/////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////Pregunta 1///////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
void cargarCitas (const char *nombArch,char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,double ***&citaTiempoYPago){
    ifstream arch;
    aperturaDeArchivoParaLeer(arch,nombArch);
    int numDatos=0,cap=0;
    char *codigoPac,*nombrePac,*nombMedico,*codMedico;
    double tarifaMed;
    int idMedico,cantPacientes;
    inicializarArreglos(medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,
            citaTiempoYPago,numDatos);
    while(true){
        leerDatosPaciente(arch,codigoPac,nombrePac);
        if(arch.eof()) break;
        leeDatosMedico(arch,codMedico,nombMedico,tarifaMed);
        idMedico = buscarMed(medicoDatos,medicoTarifaHora,
                citaPaciente,citaCantidad,citaTiempoYPago,codMedico,
                nombMedico,tarifaMed,numDatos,cap);//buscar o agregar medico y devolver su indice
        agregarPaciente(arch,citaPaciente[idMedico],citaCantidad[idMedico],
                citaTiempoYPago[idMedico],codigoPac,nombrePac,medicoTarifaHora[idMedico]);
        arch.get();
    }
    cout << numDatos;
}
void agregarPaciente(ifstream &arch,char ***&citaPaciente,int *&citaCantidad,
                double **&citaTiempoYPago,char *codigoPac,char *nombrePac,
        double tarifaMed){
    verificarEspacioSuficiente(citaPaciente,citaCantidad,citaTiempoYPago);
    int indicePaciente=0,numPacientes=0;
    cout << *citaPaciente[0];
    for(numPacientes;*citaPaciente[numPacientes]!=nullptr;numPacientes++)//cantidad de pacientes
        if(strcmp(paciente(citaPaciente[numPacientes]),codigoPac)!=0){
            indicePaciente = numPacientes;
            break;
        }else
            indicePaciente = numPacientes;
    agregarPac(citaPaciente[indicePaciente],citaCantidad[indicePaciente],
            citaTiempoYPago[indicePaciente],codigoPac,nombrePac);        
    calcularTiempoYPago(arch,citaTiempoYPago[indicePaciente],tarifaMed);
}
void calcularTiempoYPago(ifstream &arch,double *&citaTiempoYPago,double tarifaMed){
    char *fecha = leeCadena(arch,20,',');
    double horaIni,horaFin;
    leeHora(arch,horaIni);
    arch.get();
    leeHora(arch,horaFin);
    citaTiempoYPago[0]+=(horaFin-horaIni);
    citaTiempoYPago[1]+=((horaFin-horaIni)*tarifaMed);
}
void leeHora(ifstream &arch,double &hora){
    double hh,mm,ss;
    char c;
    arch >> hh >> c >> mm >> c >> ss;
    hora = hh + mm/60 + ss/3600;
}

void agregarPac(char **&citaPaciente,int &citaCantidad,
                double *&citaTiempoYPago,char *codigoPac,char *nombrePac){
    citaPaciente[0] = codigoPac;
    citaPaciente[1] = nombrePac;
    citaCantidad++;
}
char *paciente(char **citaPaciente){
    return citaPaciente[0];
}
void verificarEspacioSuficiente(char ***&citaPaciente,int *&citaCantidad,
                double **&citaTiempoYPago){
    int cantPaciente=0;
    if(citaPaciente==nullptr){
        citaPaciente = new char **[INCREMENTO]{};
        citaCantidad = new int [INCREMENTO]{};
        citaTiempoYPago = new double *[INCREMENTO]{};
        for(int i=0;i<INCREMENTO;i++){
            citaPaciente[i] = new char *[2]{};
            citaTiempoYPago[i] = new double [2]{};
        }
    }else{
        for(cantPaciente;citaPaciente[cantPaciente]!=nullptr;cantPaciente++); // ver la cantidad de pacientes
        if((cantPaciente+1)%INCREMENTO==0)
            agregarEspacios(citaPaciente,citaCantidad,citaTiempoYPago,
                    cantPaciente+1+INCREMENTO,cantPaciente);
    }
}
void agregarEspacios(char ***&citaPaciente,int *&citaCantidad,double **&citaTiempoYPago,
                    int cap,int cantPacientes){
    char ***auxCitaPaciente;
    int *auxCitaCantidad;
    double **auxCitaTiempoYPago;
    auxCitaPaciente = new char **[cap]{};
    auxCitaCantidad = new int [cap]{};
    auxCitaTiempoYPago = new double *[cap]{};
    for(int i=cantPacientes;i<cap;i++){
            citaPaciente[i] = new char *[2]{};
            citaTiempoYPago[i] = new double [2]{};
    }
    for(int i=0;i<cantPacientes;i++){
        auxCitaCantidad[i] = citaCantidad[i];
        auxCitaPaciente[i] = citaPaciente[i];
        auxCitaTiempoYPago[i] = citaTiempoYPago[i];
    }
    delete citaCantidad;
    delete citaPaciente;
    delete citaTiempoYPago;
    citaCantidad = auxCitaCantidad;
    citaPaciente = auxCitaPaciente;
    citaTiempoYPago = auxCitaTiempoYPago;
}
int buscarMed(char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,double ***&citaTiempoYPago,
        char *codMedico,char *nombMedico,double tarifaMed,
        int &numDatos,int &cap){
    if(numDatos == cap){
        agregarEspacios(medicoDatos,medicoTarifaHora,citaPaciente,citaCantidad,
                citaTiempoYPago,numDatos,cap);
        iniciarEspaciosDatosMedico(medicoDatos,numDatos,cap,citaPaciente);
    }
    int i;
    for(i=0;i<numDatos;i++)
        if(codIguales(medicoDatos[i],codMedico))return i;
    //si no encuentra, agregar
    agregarMedico(medicoDatos[i],codMedico,nombMedico);
    medicoTarifaHora[i] = tarifaMed;
    numDatos++;
    return i;
}
void agregarMedico(char **&medicoDatos,char *codMedico,char *nombMedico){
    medicoDatos[0] = codMedico;
    medicoDatos[1] = nombMedico;
}
void iniciarEspaciosDatosMedico(char ***&medicoDatos,int numDatos,int cap,
        char ****&citaPaciente){
    for(int i=numDatos;i<cap;i++){
        medicoDatos[i] = new char *[2]{};
        citaPaciente[i] = nullptr;
    }
}
bool codIguales(char **medicoDatos,char *codMedico){
    char cadena1[7]{},cadena2[7]{};
    strcpy(cadena1,medicoDatos[0]);
    strcpy(cadena2,codMedico);
    if(strcmp(cadena1,cadena2)==0) return true; //ptmreeee
    return false;
}
void agregarEspacios(char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,
                double ***&citaTiempoYPago,int &numDatos,int &cap){
    char ****auxCitaPac,***auxMedDato;
    double *auxTarifa,***auxcitaTiempoYPago;
    int **auxCitaCant;
    cap +=INCREMENTO;
    if(medicoDatos == nullptr){
        medicoDatos = new char **[cap]{};
        medicoTarifaHora = new double [cap]{};
        citaPaciente = new char ***[cap]{};
        citaCantidad = new int *[cap]{};
        citaTiempoYPago = new double **[cap]{};
        numDatos=0;
    }else{
        auxCitaCant = new int *[cap]{};
        auxCitaPac = new char ***[cap]{};
        auxMedDato = new char **[cap]{};
        auxcitaTiempoYPago = new double **[cap]{};
        auxTarifa = new double [cap]{};
        for(int i=0; i<numDatos ;i++){
            auxCitaCant[i] = citaCantidad[i];
            auxCitaPac[i] = citaPaciente[i];
            auxMedDato[i] = medicoDatos[i];
            auxTarifa[i] = medicoTarifaHora[i];
            auxcitaTiempoYPago[i] = citaTiempoYPago[i];
        }
        delete medicoDatos;
        delete medicoTarifaHora;
        delete citaPaciente;
        delete citaCantidad;
        delete citaTiempoYPago;
        medicoDatos = auxMedDato;
        medicoTarifaHora = auxTarifa;
        citaPaciente = auxCitaPac;
        citaCantidad = auxCitaCant;
        citaTiempoYPago = auxcitaTiempoYPago;
    }
    
}
void leerDatosPaciente(ifstream &arch,char *&codigo,char *&nombre){
    codigo = leeCadena(arch,15,',');
    arch.get();
    nombre = leeCadena(arch,60,',');
    
}
void leeDatosMedico(ifstream &arch,char *&codMedico,char *&nombMedico,
        double &tarifaMed){
    codMedico = leeCadena(arch,7,',');
    nombMedico = leeCadena(arch,60,',');
    arch >> tarifaMed;
    arch.get();
}
void inicializarArreglos(char ***&medicoDatos,double *&medicoTarifaHora,
        char ****&citaPaciente,int **&citaCantidad,double ***&citaTiempoYPago,
        int numDatos){
    medicoDatos = nullptr;
    citaPaciente = nullptr;
    medicoTarifaHora = nullptr;
    citaCantidad = nullptr;
    citaTiempoYPago = nullptr;
}

void pruebaDeCargaDeCitas (const char *nombArch,char ***medicoDatos,double *medicoTarifaHora,
                char ****citaPaciente,int **citaCantidad,double ***citaTiempoYPago){
    ofstream arch;
    aperturaDeArchivoParaEscribir(arch,nombArch);
    arch.precision(2);
    arch << fixed;
    
    for(int i=0;medicoDatos[i]!=0;i++){
        imprimirDatosMed(arch,medicoDatos[i],medicoTarifaHora[i]);
        imprimirLinea(arch,'-',120);
        arch << "RELACION DE PACIENTES ATENDIDOS:"<<endl;
        imprimirLinea(arch,'-',120);
        arch << left << setw(8) << ""
                << setw(15) << "DNI"
                << setw(50) << "Nombre"
                << setw(25) << "Cantidad de citas"
                << setw(25) << "Tiempo total (hrs)"
                << "Pago total" << endl;
        imprimirLinea(arch,'-',120);
        imprimirPacientes(arch,citaPaciente[i],citaCantidad[i],citaTiempoYPago[i]);
    }
}
void imprimirPacientes(ofstream &arch,char ***citaPaciente,int *citaCantidad,
        double **citaTiempoYPago){
    for(int i=0;citaPaciente[i]!=0;i++){
        
        arch << left << right << setw(3) << i+1  
                    << setw(5) << "";
        imprimirDatosPac(arch,citaPaciente[i]);
                
        arch << right << setw(11) << citaCantidad[i]
                    << setw(22) << citaTiempoYPago[0]
                    << setw(10) << citaCantidad[1] << endl;
    }
}
void imprimirDatosPac(ofstream &arch,char **citaPaciente){
    arch << left
                << setw(15) << citaPaciente[0]
                << setw(50) << citaPaciente[1];
}
void imprimirDatosMed(ofstream &arch,char **medicoDatos,double medicoTarifaHora){
    arch << left
            << setw(20) << "CODIGO"
            << setw(50) << "Nombre"
            << setw(30) << "TARIFA POR HORA DE CONSULTA " << right
            << setw(7)  << medicoTarifaHora <<endl;
    arch << left 
            << setw(20) << medicoDatos[0]
            << setw(50) << medicoDatos[1]
            <<endl;
}