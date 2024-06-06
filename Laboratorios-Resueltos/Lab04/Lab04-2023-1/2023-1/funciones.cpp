#include "MetodoDinamicoExacto.h"

void abrirArchivoLectura(ifstream &arch,const char *nombArch){
    arch.open(nombArch,ios::in);
    if(!arch){
        cout << "El archivo "<< nombArch << " no se pudo abrir correctamente"<<endl;
        exit(1);
    }
}

void abrirArchivoEscritura(ofstream &arch, const char *nombArch){
    arch.open(nombArch,ios::out);
    if(!arch){
        cout << "El archivo "<< nombArch << " no se pudo abrir correctamente"<<endl;
        exit(1);
    }
}
void lecturaAlumnos(const char *nombArch,int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                int *&alumno_Porcentaje,int *&alumno_Escala){
    ifstream arch;
    abrirArchivoLectura(arch,nombArch);
    
    int buffCodigo[80]{},buffPorcentaje[80],buffEscala[80];
    char buffModalidad[80]{}, *buffNombre[80]{};
    char c,modalidad;
    int porcentaje,cod,numDatos=0;
    while(true){
        arch >> cod;
        if(arch.eof()) break;
        arch.get();
        buffNombre[numDatos] = leeCadena(arch,60,',');
        porcentaje = 0;
        if(arch.peek() == 'S'){
            arch >> modalidad >> c >>porcentaje >> c;
        }else if(arch.peek() == 'V')
            arch >> modalidad >> c;
        else{
            modalidad = 0;
        }
        arch >> buffEscala[numDatos];
        buffCodigo[numDatos] = cod;
        buffModalidad[numDatos] = modalidad;
        buffPorcentaje[numDatos] = porcentaje;
        numDatos++;
    }
    alumno_Codigo = new int [numDatos+1]{};
    alumno_Modalidad = new char [numDatos+1]{};
    alumno_Porcentaje = new int [numDatos+1]{};
    alumno_Escala = new int [numDatos+1]{};
    alumno_Nombre = new char *[numDatos+1]{};
    for(int i=0;i<numDatos;i++){
        alumno_Codigo[i] = buffCodigo[i];
        alumno_Escala[i] = buffEscala[i];
        alumno_Modalidad[i] = buffModalidad[i];
        alumno_Nombre[i] = buffNombre[i];
        alumno_Porcentaje[i] = buffPorcentaje[i];
    }
}

void pruebaLecturaAlumnos(const char *nombArch,int *&alumno_Codigo,char **&alumno_Nombre,char *&alumno_Modalidad,
                  int *&alumno_Porcentaje,int *&alumno_Escala){
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout << "El archivo "<< nombArch << " no se pudo abrir correctamente"<<endl;
        exit(1);
    }
    
    for(int i=0;alumno_Codigo[i];i++){
        arch << left << setw(6) << alumno_Codigo[i]
                << setw(60) << alumno_Nombre[i]
                << setw(3) << alumno_Modalidad[i]
                << setw(3) << alumno_Porcentaje[i]
                << setw(3) << alumno_Escala[i]
                << endl;
    }    
}

void lecturaCursos (const char *nombArch,int *&alumno_Codigo,int *&alumno_Escala,char **&curso_Nombre,
                double *&curso_Credito,int **&curso_Alumnos){
    ifstream arch;
    abrirArchivoLectura(arch,nombArch);
    int codAlumn, *buffCur_Alumno[100]{},numDatos=0;
    double creditos, buffCreditos[100]{};
    char c, *nombCurso, *buffNombreCur[100];
    buffNombreCur[0] = nullptr;
    while(true){
        arch >> codAlumn;
        if(arch.eof()) break;
        arch.get();
        nombCurso = leeCadena(arch,60,',');
        arch >> creditos;
        
        agregarCurso(nombCurso,creditos,buffNombreCur,buffCreditos,buffCur_Alumno,
                numDatos);
        agregarAlumno(buffNombreCur,nombCurso,codAlumn,alumno_Codigo,alumno_Escala,
                buffCur_Alumno);
    }
    iniciarArreglosCursos(curso_Nombre,curso_Credito,curso_Alumnos,numDatos);
    for(int i=0;i<numDatos;i++){
        curso_Credito[i] = buffCreditos[i];
        curso_Nombre[i]  = buffNombreCur[i];
        
        curso_Alumnos[i] = colocarArregloAlumno_Curso(buffCur_Alumno[i]);
    }
    delete buffCreditos;
    delete buffCur_Alumno;
    delete buffNombreCur;
}
int *colocarArregloAlumno_Curso(int *buffCur_Alumno){
    int j=0;
    while(buffCur_Alumno[j]!=0)j++; // recorre
    
    
    int *puntAux;
    puntAux = new int[j+1]{};
    
    for ( int i=0; i<j ;i++){
        puntAux[i] = buffCur_Alumno[i];
    }
    return puntAux;
}

void iniciarArreglosCursos(char **&curso_Nombre, double *&curso_Credito,int **&curso_Alumnos,int numDatos){
    curso_Nombre = new char *[numDatos+1]{};
    curso_Credito = new double [numDatos+1]{};
    curso_Alumnos = new int *[numDatos+1]{};
}

void pruebaDeLecturaCursos (const char *nombArch,char **&curso_Nombre,double *&curso_Credito,int **&curso_Alumnos){
    ofstream arch;
    abrirArchivoEscritura(arch,nombArch);
    arch.precision(2);
    arch << fixed;
    int j=0;
    for(int i=0;curso_Credito[i]!=0;i++){
        arch << left << setw(60) << curso_Nombre[i]
                << right << setw(5) << curso_Credito[i]<<endl;
        j=0;
        while((curso_Alumnos[i])[j]!=0){
            arch << right << setw(60) << " " << (curso_Alumnos[i])[j]
                    << setw(4) << (curso_Alumnos[i])[j+1] << endl;
                    j+=2;
        }
    }
    
}
void agregarCurso(char *nombCurso,double creditos,char **buffNombreCur,
        double *buffCreditos,int **buffCur_Alumno,int &numDatos){
    int i;
    for(i=0;buffCreditos[i]!=0;i++)//comprobar que el curso exita
        if(strcmp(buffNombreCur[i],nombCurso)==0) return;
    //si no existe
    buffNombreCur[i] = nombCurso;
    buffCreditos[i] = creditos;
    buffCur_Alumno[i] = new int [50]{};
    numDatos++;
}
void agregarAlumno(char **buffNombreCur,char *nombCurso,int codAlumn,
        const int *alumno_Codigo,const int *alumno_Escala,int **buffCur_Alumno){
    int i=0,j=0;
    while(strcmp(buffNombreCur[i],nombCurso)!=0) i++; //posicion curso
    while(alumno_Codigo[j]!=codAlumn) j++;  //posicion alumno
    
    colocarAlumnosBuffer(buffCur_Alumno[i],alumno_Codigo[j],alumno_Escala[j]);
}
void colocarAlumnosBuffer(int *buffCur_Alumno,int alumno_Codigo,int alumno_Escala){
    int k=0;
    while(buffCur_Alumno[k]!=0)k++;
    
    buffCur_Alumno[k] = alumno_Codigo;
    buffCur_Alumno[k+1] = alumno_Escala;
    buffCur_Alumno[k+2] = 0;
}

char *leeCadena(ifstream &arch,int lim,char car){
    char cadena[lim],*cad;
    arch.getline(cadena,lim,car);
    
    cad = new char [lim + 1];
    strcpy(cad,cadena);
    return cad;
}

void reporteDeRecaudacionPorModalidad (const char *nombArch,int *alumno_Codigo,char *alumno_Modalidad,
                    int *alumno_Porcentaje,char **alumno_Nombre,char **curso_Nombre,double *curso_Credito,int **curso_Alumnos){
    ofstream arch;
    abrirArchivoEscritura(arch,nombArch);
    arch.precision(2);
    arch << fixed;
    imprimirEncabezado(arch);
    int i =0;
    double recPres=0,recSemi=0,recVirt=0;
    while(curso_Credito[i]!=0){
        imprimirDatosCurso(arch,curso_Credito[i],curso_Nombre[i],i);
        imprimirAlumnosMatriculados(arch,curso_Alumnos[i],alumno_Nombre,
                alumno_Modalidad,alumno_Porcentaje,alumno_Codigo,
                curso_Credito[i],recPres,recSemi,recVirt);
        
        i++;
    }
    
}
void imprimirDatosCurso(ofstream &arch,double curso_Credito,char *curso_Nombre,
        int i){
    arch << right << setfill('0')
            << setw(2) << i << ')' << setfill(' ')
            << setw(10) << "Curso:"
            << left << "  "
            << setw(50) << curso_Nombre
            << setw(12) << "Creditos:"
            << right << setw(5) << curso_Credito << endl;
    arch << "ALUMNOS MATRICULADOS" << endl;
    imprimirLinea(arch,'-',120);
}
void imprimirAlumnosMatriculados(ofstream &arch,int *curso_Alumnos,char **alumno_Nombre,
                char *alumno_Modalidad,int *alumno_Porcentaje,int *alumno_Codigo,
                double curso_Credito,double &recPres,double &recSemi,double &recVirt){
    imprimirEncabezadoAlumno(arch);
    int i=0,indiceAlumno=0;
    double costoCredito,escalas[4],recaudadoAlumno;
    agregarEscalas(escalas);
    while(curso_Alumnos[i]!=0){
        indiceAlumno = buscarAlumno(curso_Alumnos[i],alumno_Codigo);
        recaudadoAlumno = escalas[curso_Alumnos[i+1]] *curso_Credito;
        arch << right << setfill('0')
            << setw(2) << i << ')' << setfill(' ')
                << right << setw(7) << alumno_Codigo[indiceAlumno]
                << "   " << left << setw(50) << alumno_Nombre[indiceAlumno]
                << right << setw(5) << curso_Alumnos[i+1];                
        imprimirRecuadado(arch,alumno_Modalidad[indiceAlumno],recaudadoAlumno);
        if(alumno_Modalidad[indiceAlumno]=='S'){
            recSemi+=recaudadoAlumno;
        }else if(alumno_Modalidad[indiceAlumno]=='V')
            recVirt+=recaudadoAlumno;
        else 
            recPres+=recaudadoAlumno;
        i+=2;
    }
    imprimirLinea(arch,'=',120);
        arch << left << setw(70) <<"RECAUDACION POR MODALIDAD DE ESTUDIO"
                << right << setw(15) << recPres
                << setw(15) << recSemi
                << setw(15) << recVirt <<endl;
        arch << left << setw(110) << "TOTAL RECAUDADO:"
                << right << setw(5) << recPres+recSemi+recVirt<<endl;
        imprimirLinea(arch,'=',120);
}
void imprimirRecuadado(ofstream &arch,char alumno_Modalidad,double recaudadoAlumno){
    arch <<right;
    if(alumno_Modalidad == 'S'){
        arch << setw(26) << recaudadoAlumno << endl;
    }else if(alumno_Modalidad == 'V'){
        arch << setw(43) << recaudadoAlumno << endl;
    }else
        arch << setw(10) << recaudadoAlumno << endl;
}
int buscarAlumno(int codigo,int *alumno_Codigo){
    for(int i=0;alumno_Codigo[i]!=0;i++)
        if(alumno_Codigo[i]==codigo) return i;
}
void imprimirEncabezadoAlumno(ofstream &arch){
    arch << right 
            << setw(9) << "CODIGO"
            << setw(3) << "" << left 
            << setw(52) << "NOMBRE"
            << setw(10) << "ESCALA"
            << setw(15) << "PRESENCIAL"
            << setw(20) << "SEMI PRESENCIAL"
            << "VIRTUAL" << endl;
}
void agregarEscalas(double *escalas){
    ifstream arch;
    abrirArchivoLectura(arch,"escalas.csv");
    int i;
    char c;
    double costo;
    while(true){
        arch >> c >> i;
        if(arch.eof()) break;
        arch.get();
        arch >> costo;
        arch.get();
        escalas[i-1] = costo;
    }
    arch.close();
}

void imprimirEncabezado(ofstream &arch){
    arch << right << setw(80) << "ENTIDAD EDUCATIVA LP1" << endl;
    arch << setw(78) << "LISTADOS DE CLASE " << endl;
    imprimirLinea(arch,'=',120);
}
void imprimirLinea(ofstream &arch,char c,int num){
    for(int i=0;i<num;i++)
        arch << c;
    arch << endl;
}