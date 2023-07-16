#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Estudiantes
{
    string nombre;
    string apellido;
    string email;
    string genero;
    int notas_matematica;
    int notas_sociales;
    int notas_biologia;
    int notas_fisica;
    int notas_educ_fisica;
    int notas_artes;
};

Estudiantes estudiante[1500];

//Funciones que se van a usar:
void todos_los_estudiantes();
void mostrar_estudiante();
void materias();
void frecuencia();
void editar_estudiante();
void anadir_estudiante();
void promedio_por_materia();
void top_estudiantes_por_materia();
void boletas();

//Algoritmos de ordenamiento
void partition_mate();
void quickSort_mate();
void partition_soc();
void quickSort_soc();
void partition_bio();
void quickSort_bio();
void partiyion_fis();
void quickSort_fis();
void partition_ef();
void quickSort_ef();
void partition_art();
void quickSort_art();

//Dandole los procesos a las funciones
void todos_los_estudiantes()
{
    ifstream infile;
    infile.open("Datos_Estudiantes.csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

            float promedio;
            promedio = (stof(matematicas) + stof(sociales) + stof(biologia) + stof(fisica) + stof(educ_fisica) + stof(artes)) / 6;

            cout << endl 
                 << "Nombre: " << nombre << endl
                 << "Apellido: " << apellido << endl
                 << "Promedio: " << promedio << endl << endl;
        }
    }
    infile.close();
}

void mostrar_estudiante()
{
    ifstream infile;
    infile.open("Datos_Estudiantes.csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, nombre_buscar, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;

        cout << endl << "Ingrese el nombre del estudiante a buscar: ";
        cin >> nombre_buscar;

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

            float promedio;
            promedio = (stof(matematicas) + stof(sociales) + stof(biologia) + stof(fisica) + stof(educ_fisica) + stof(artes)) / 6;

            if(nombre_buscar == nombre)
            {
                cout << endl 
                     << "Estudiante encontrado" << endl
                     << "Nombre: " << nombre << endl
                     << "Apellido: " << apellido << endl
                     << "Promedio: " << promedio << endl << endl;
            }
        }
    }
    infile.close();
}

void materias()
{
    ifstream infile;
    infile.open("Datos_Estudiantes.csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, nombre_buscar, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        int pasados_mate = 0, nopasados_mate = 0, pasados_sociales = 0, nopasados_sociales = 0, pasados_biologia = 0, nopasados_biologia = 0;
        int pasados_fisica = 0, nopasados_fisica = 0, pasados_ef = 0, nopasados_ef = 0, pasados_artes = 0, nopasados_artes = 0, total = 0;

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

            total++;
            
            if(stof(matematicas) >= 10)
            {
                pasados_mate++;
            }else{
                nopasados_mate++;
            }

            if(stof(sociales) >= 10)
            {
                pasados_sociales++;
            }else{
                nopasados_sociales++;
            }

            if(stof(biologia) >= 10)
            {
                pasados_biologia++;
            }else{
                nopasados_biologia++;
            }
                    
            if(stof(fisica) >= 10)
            {
                pasados_fisica++;
            }else{
                nopasados_fisica++;
            }
                    
            if(stof(educ_fisica) >= 10)
            {
                pasados_ef++;
            }else{
                nopasados_ef++;
            }
                    
            if(stof(artes) >= 10)
            {
                pasados_artes++;
            }else{
                nopasados_artes++;
            }
        }
                cout << endl << "-- Matematicas --" << endl
                     << "Estudiantes pasados: " << pasados_mate << endl
                     << "Estudiantes aplazados: " << nopasados_mate << endl
                     << endl ;

                cout << "-- Sociales --" << endl
                     << "Estudiantes pasados: " << pasados_sociales << endl
                     << "Estudiantes aplazados: " << nopasados_sociales << endl
                     << endl ;

                cout << "-- Biologia --" << endl
                     << "Estudiantes pasados: " << pasados_biologia << endl
                     << "Estudiantes aplazados: " << nopasados_biologia << endl
                     << endl ;
        
                cout << "-- Fisica --" << endl
                     << "Estudiantes pasados: " << pasados_fisica << endl
                     << "Estudiantes aplazados: " << nopasados_fisica << endl
                     << endl ;

                cout << "-- Educacion fisica --" << endl
                     << "Estudiantes pasados: " << pasados_ef << endl
                     << "Estudiantes aplazados: " << nopasados_ef << endl
                     << endl ;

                cout << "-- Artes --" << endl
                     << "Estudiantes pasados: " << pasados_artes << endl
                     << "Estudiantes aplazados: " << nopasados_artes << endl
                     << endl ;
                
                cout << "Total de estudiantes :" << total << endl;
    }
    infile.close();
}

int frecuencia(string email_ingresado)
{
    int contador = 0;
    ifstream infile;
    infile.open("Datos_Estudiantes.csv");

    if (!infile)
    {
        cout<< "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

            if(email_ingresado.compare(email) == 0)
            {
                contador++;
            }
        }
        infile.close();
    }
    return contador;
}


void editar_estudiante()
{
ifstream infile;
infile.open("Datos_Estudiantes.csv");
ofstream outfile;
outfile.open("Datos_Estudiantes_aux.csv");
    if (!infile||!outfile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, email_buscar, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        string nombre_nuevo, apellido_nuevo, email_nuevo, genero_nuevo;
        float matematicas_nuevo, sociales_nuevo, biologia_nuevo, fisica_nuevo, ef_nuevo, artes_nuevo;
        bool existe = false, repetido = false;

        cout << endl << "Ingrese el email del alumno: ";
        cin >> email_buscar;

        getline(infile, linea);
        outfile << linea << endl;

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');
 
                if(email == email_buscar)
                {
                existe = true;
                
                cout<< endl << "Se ha encontrado el alumno" << endl
                    << "1. Modificar nombre" << endl
                    << "2. Modificar apellido" << endl
                    << "3. Modificar email" << endl
                    << "4. Modificar genero" << endl
                    << "5. Modificar notas de matematicas" << endl
                    << "6. Modificar notas de sociales" << endl
                    << "7. Modificar notas de biologia" << endl
                    << "8. Modificar notas de fisica" << endl
                    << "9. Modificar notas de educacion fisica" << endl
                    << "10. Modificar notas de arte" << endl
                    << "11. Modificar todo" << endl
                    << ": ";

                int opcion;
                cin >> opcion;

                switch(opcion)
                {
                    case 1:
                    cout << endl << "Nuevo nombre: ";
                    cin >> nombre_nuevo;
                    outfile << nombre_nuevo << ";" << apellido << ";" << email << ";" << genero << ";" <<  matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 2:
                    cout << endl << "Nuevo apellido: ";
                    cin >> apellido_nuevo;
                    outfile << nombre << ";" << apellido_nuevo << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 3: 
                    cout << endl << "Nuevo email: ";
                    cin >> email_nuevo;
                    if(frecuencia(email_nuevo) == 0)
                    {
                    outfile << nombre << ";" << apellido << ";" << email_nuevo << ";" << genero << ";" <<  matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    }else{
                        cout << "Un estudiante con este correo ya se encuentra en el sistema"<< endl;
                        repetido = true;
                        
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica << ";"
                            << educ_fisica << ";" << artes << endl; 
                    }
                    break;

                    case 4:
                    cout << endl << "Nuevo genero (Male, Female, ...): ";
                    cin >> genero_nuevo;
                    outfile << nombre << ";" << apellido << ";" << genero_nuevo << ";" << genero_nuevo << ";" <<  matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 5:
                    cout << endl << "Nueva nota de matematicas: ";
                    cin >> matematicas_nuevo;
                    if(matematicas_nuevo > 20){matematicas_nuevo = 20;}
                    if (matematicas_nuevo < 0){matematicas_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas_nuevo << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 6:
                    cout << endl << "Nueva nota de sociales: ";
                    cin >> sociales_nuevo;
                    if(sociales_nuevo > 20){sociales_nuevo = 20;}
                    if(sociales_nuevo < 0){sociales_nuevo = 0;}
                        
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales_nuevo << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 7:
                    cout << endl << "Nueva nota de biologia: ";
                    cin >> biologia_nuevo;
                    if(biologia_nuevo > 20){biologia_nuevo = 20;}
                    if (biologia_nuevo < 0){biologia_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia_nuevo << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 8:
                    cout << endl << "Nueva nota de fisica: ";
                    cin >> fisica_nuevo;
                    if(fisica_nuevo > 20){fisica_nuevo = 20;}
                    if (fisica_nuevo < 0){fisica_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica_nuevo
                             << ";" << educ_fisica << ";" << artes << endl;
                        break;

                    case 9:
                    cout << endl << "Nueva nota de educacion fisica: ";
                    cin >> ef_nuevo;
                    if(ef_nuevo > 20){ef_nuevo = 20;}
                    if (ef_nuevo < 0){ef_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" <<genero <<";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica
                             << ";" << ef_nuevo << ";" << artes << endl;
                        break;

                    case 10:
                    cout << endl << "Nueva nota de artes: ";
                    cin >> artes_nuevo;
                    if(artes_nuevo > 20){artes_nuevo = 20;}
                    if (artes_nuevo < 0){artes_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes_nuevo << endl;
                        break;

                    case 11:

                    cout << endl << "Nuevo email: ";
                    cin >> email_nuevo;
                    if(!(frecuencia(email_nuevo) == 0))
                    {
                        cout << endl << "Un estudiante con este correo ya se encuentra en el sistema"<< endl;
                        repetido = true;
                        
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica << ";"
                            << educ_fisica << ";" << artes << endl; 
                        
                        break;
                    }

                    cout << endl << "Nuevo nombre: ";
                    cin >> nombre_nuevo; 

                    cout << endl << "Nuevo apellido: ";
                    cin >> apellido_nuevo;

                    cout << endl << "Nuevo genero (Male, Female, ...): ";
                    cin >> genero_nuevo;

                    cout << endl << "Nueva nota en matematicas: ";
                    cin >> matematicas_nuevo;
                    if(matematicas_nuevo > 20){matematicas_nuevo = 20;}
                    if (matematicas_nuevo < 0){matematicas_nuevo = 0;}

                    cout << endl << "Nueva nota en sociales: "; 
                    cin >> sociales_nuevo;
                    if(sociales_nuevo > 20){ sociales_nuevo = 20;}
                    if(sociales_nuevo < 0){ sociales_nuevo = 0;}

                    cout << endl << "Nueva nota en biologia: ";
                    cin >> biologia_nuevo;
                    if(biologia_nuevo > 20){biologia_nuevo = 20;}
                    if (biologia_nuevo < 0){biologia_nuevo = 0;}

                    cout << endl << "Nueva nota en fisica: ";
                    cin >> fisica_nuevo;
                    if(fisica_nuevo > 20){fisica_nuevo = 20;}
                    if (fisica_nuevo < 0){fisica_nuevo = 0;}
                    cout << endl << "Nueva nota en educacion fisica: ";
                    cin >> ef_nuevo;
                    if(ef_nuevo > 20){ef_nuevo = 20;}
                    if (ef_nuevo < 0){ef_nuevo = 0;}

                    cout << endl << "Nueva nota en artes: ";
                    cin >> artes_nuevo;
                    if(artes_nuevo > 20){artes_nuevo = 20; }
                    if (artes_nuevo < 0){artes_nuevo = 0;}

                    outfile << nombre_nuevo << ";" << apellido_nuevo << ";" << email_nuevo << ";" << genero_nuevo << ";" << matematicas_nuevo << ";" << sociales_nuevo << ";" 
                            << biologia_nuevo << ";" << fisica_nuevo << ";" << ef_nuevo << ";" << artes_nuevo << endl;
                    break;

                    default:

                    cout << endl << "Opcion incorrecta"<< endl;
                    break;
                }
            }
        else
        {
            outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica << ";"
                    << educ_fisica << ";" << artes << endl; 
        }
    }
    if(repetido = false)
    {
        cout << endl << "Se ha modificado el estudiante correctamente" << endl;
    }
    if(existe == false)
    {
        cout << "No se encontro el estudiante con el correo: " << email_buscar << endl;
    }
        infile.close();
        outfile.close();
        remove("Datos_Estudiantes.csv");
        rename("Datos_Estudiantes_aux.csv", "Datos_Estudiantes.csv"); 
    }
}

void anadir_estudiante()
{
    ofstream infile;
    infile.open("Datos_Estudiantes.csv", ios::app);
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string nombre, apellido, email, genero;
        int matematicas, sociales, biologia, fisica, educ_fisica, artes;

        cout << endl << "Ingrese el email del estudiante: ";
        cin >> email;

        if(frecuencia(email) == 0)
        {
            cout << "Ingrese el nombre del estudiante: ";
            cin >> nombre;

            cout << "Ingrese el apellido estudiante: ";
            cin >> apellido;

            cout << "Ingrese el genero del estudiante (Male, Female, ...): ";
            cin >> genero;

            cout << "Ingrese la nota en matematicas del estudiante: ";
            cin >> matematicas;
            if(matematicas > 20){matematicas = 20;}
            if (matematicas < 0){matematicas = 0;}

            cout << "Ingrese la nota en sociales del estudiante: ";
            cin >> sociales;
            if(sociales > 20){sociales = 20;}
            if (sociales < 0){sociales = 0;}

            cout << "Ingrese la nota en biologia del estudiante: ";
            cin >> biologia;
            if(biologia > 20){biologia = 20;}
            if (biologia < 0){biologia = 0;}

            cout << "Ingrese la nota en fisica del estudiante: ";
            cin >> fisica;
            if(fisica > 20){fisica = 20;}
            if (fisica < 0){fisica = 0;}

            cout << "Ingrese la nota en educacion fisica del estudiante: ";
            cin >> educ_fisica;
            if(educ_fisica > 20){educ_fisica = 20;}
            if (educ_fisica < 0){educ_fisica = 0;}

            cout << "Ingrese la nota en artes del estudiante: ";
            cin >> artes;
            if(artes > 20){artes = 20;}
            if (artes < 0){artes = 0;}

            infile  << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                    << ";" << educ_fisica << ";" << artes << endl;

            infile.close();
            cout << endl << "Se ingreso con exito el estudiante" << endl;
        }
        else
        {                        
            cout << "El estudiante ya se encuentra en el sistema"<< endl;
            infile.close();        
        }
    }
}

void promedio_por_materia()
{
    ifstream infile;
    infile.open("Datos_Estudiantes.csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        float suma_mate = 0, suma_sociales = 0, suma_biologia = 0, suma_fisica = 0, suma_ef = 0, suma_artes = 0, numestudiantes = 0;
        float promedio_mate = 0, promedio_sociales = 0, promedio_biologia = 0, promedio_fisica = 0, promedio_ef = 0, promedio_artes = 0;
        float nota = 0;

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

            numestudiantes++;
            nota = stof(matematicas);
            suma_mate += nota;
            nota = stof(sociales);
            suma_sociales += nota;
            nota = stof(biologia);
            suma_biologia += nota;
            nota = stof(fisica);
            suma_fisica += nota;
            nota = stof(educ_fisica);
            suma_ef += nota;
            nota = stof(artes);
            suma_artes += nota;

        }

        promedio_mate = suma_mate / numestudiantes;
        promedio_sociales = suma_sociales / numestudiantes;
        promedio_biologia = suma_biologia / numestudiantes;
        promedio_fisica = suma_fisica / numestudiantes;
        promedio_ef = suma_ef / numestudiantes;
        promedio_artes = suma_artes / numestudiantes;

        cout << endl << "-- Promedios de cada materia --" << endl
             << "Matematicas :" << promedio_mate << endl
             << "Sociales : " << promedio_sociales << endl
             << "Biologia: " << promedio_biologia << endl
             << "Fisica: " << promedio_fisica << endl
             << "Educacion fisica: " << promedio_ef << endl
             << "Artes: " << promedio_artes << endl; 
    }
    infile.close();
}

int partition_mate(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_matematica >= pivot.notas_matematica) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_mate(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_mate(arr, low, high);
  
        quickSort_mate(arr, low, pivotIndex - 1);
        quickSort_mate(arr, pivotIndex + 1, high);
    }
}

int partition_soc(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_sociales >= pivot.notas_sociales) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_soc(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_soc(arr, low, high);
  
        quickSort_soc(arr, low, pivotIndex - 1);
        quickSort_soc(arr, pivotIndex + 1, high);
    }
}

int partition_bio(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_biologia >= pivot.notas_biologia) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_bio(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_bio(arr, low, high);
  
        quickSort_bio(arr, low, pivotIndex - 1);
        quickSort_bio(arr, pivotIndex + 1, high);
    }
}

int partition_fis(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_fisica >= pivot.notas_fisica) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_fis(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_fis(arr, low, high);
  
        quickSort_fis(arr, low, pivotIndex - 1);
        quickSort_fis(arr, pivotIndex + 1, high);
    }
}

int partition_ef(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_educ_fisica >= pivot.notas_educ_fisica) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_ef(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_ef(arr, low, high);
  
        quickSort_ef(arr, low, pivotIndex - 1);
        quickSort_ef(arr, pivotIndex + 1, high);
    }
}

int partition_art(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_artes >= pivot.notas_artes) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort_art(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_art(arr, low, high);
  
        quickSort_art(arr, low, pivotIndex - 1);
        quickSort_art(arr, pivotIndex + 1, high);
    }
}

void top_estudiantes_por_materia()
{
    ifstream infile;
    infile.open("Datos_Estudiantes.csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        int numestudiantes = 0;

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

            estudiante[numestudiantes].nombre = nombre;
            estudiante[numestudiantes].apellido = apellido;
            estudiante[numestudiantes].email = email;
            estudiante[numestudiantes].genero = genero;
            estudiante[numestudiantes].notas_matematica = stof(matematicas);
            estudiante[numestudiantes].notas_sociales = stof(sociales);
            estudiante[numestudiantes].notas_biologia = stof(biologia);
            estudiante[numestudiantes].notas_fisica = stof(fisica);
            estudiante[numestudiantes].notas_educ_fisica = stof(educ_fisica);
            estudiante[numestudiantes].notas_artes = stof(artes);
            numestudiantes++;
        }
    
            cout << endl << "-- 10 mejores estudiantes --" << endl
                 << "1. Matematicas" << endl
                 << "2. Sociales" << endl
                 << "3. Biologia" << endl
                 << "4. Fisica" << endl
                 << "5. Educacion fisica" << endl
                 << "6. Artes" << endl
                 << " : ";

            int opcion;
            cin >> opcion;
            switch(opcion)
            {
                case 1:
                quickSort_mate(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en matematicas: " << endl << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                        
                }
                break;

                case 2:
                quickSort_soc(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en sociales: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 3:
                quickSort_bio(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en biologia: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 4:
                quickSort_fis(estudiante, 0, numestudiantes - 1);
                cout << endl <<"10 Mejores estudiantes en fisica: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 5:
                quickSort_ef(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en educacion fisica: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 6:
                quickSort_art(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en artes: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en artes: " << estudiante[i].notas_artes << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl 
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                default:
                    cout << endl << "Opcion invalida";
                break;
            }
    }
    infile.close();
}

void boletas()
{
    int n;

    cout << endl << "Ingrese el numero de boletas que desea generar: ";
    cin >> n;
    cout << endl;

    string correos[n];
    ifstream infile;
    infile.open("Datos_Estudiantes.csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
        exit;
    }


    for(int i = 0; i < n; i++)
    {
    cout << "Ingrese el correo del estudiante #" << i+1 << ": ";
    cin >> correos[i];
    cout << endl;

        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        bool existe = false;

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

                if(correos[i] == email)
                {
                    existe = true;
                    float promedio = (stof(matematicas) + stof(sociales) + stof(biologia) + stof(fisica) + stof(educ_fisica) + stof(artes)) / 6;
                    cout << "-- Boleta. Universidad Rafael Urdaneta. Periodo 2023A. Estudiante: " << nombre << " " << apellido << " -- " << endl
                         << "Notas de matematicas: " << matematicas << endl
                         << "Notas de sociales: " << sociales << endl
                         << "Notas de biologia: " << biologia << endl
                         << "Notas de fisica: " << fisica << endl
                         << "Notas de educacion fisica: " << educ_fisica << endl
                         << "Notas de artes: " << artes << endl 
                         << "Promedio total: " << promedio << endl << endl;
                    break;   
                }
            }
            if(existe = false)
                    {
                    cout << "No hay ningun estudiante con el correo " << correos[i] << " registrado en el sistema"; 
                    break;   
                    }
    }
    infile.close();
}

void proporcion_genero_x_materia()
{
    float apmat_masc = 0.0, apmat_fem = 0.0, apmat_ot = 0.0, repmat_masc = 0.0, repmat_fem = 0.0, repmat_ot = 0.0;
    float apsoc_masc = 0.0, apsoc_fem = 0.0, apsoc_ot = 0.0, repsoc_masc = 0.0, repsoc_fem = 0.0, repsoc_ot = 0.0;
    float apbio_masc = 0.0, apbio_fem = 0.0, apbio_ot = 0.0, repbio_masc = 0.0, repbio_fem = 0.0, repbio_ot = 0.0;
    float apfis_masc = 0.0, apfis_fem = 0.0, apfis_ot = 0.0, repfis_masc = 0.0, repfis_fem = 0.0, repfis_ot = 0.0;
    float apef_masc = 0.0, apef_fem = 0.0, apef_ot = 0.0, repef_masc = 0.0, repef_fem = 0.0, repef_ot = 0.0;
    float apart_masc = 0.0, apart_fem = 0.0, apart_ot = 0.0, repart_masc = 0.0, repart_fem = 0.0, repart_ot = 0.0;

    float prompas_mat_masc = 0.0, prompas_mat_fem = 0.0, prompas_mat_ot = 0.0;
    float promrep_mat_masc = 0.0, promrep_mat_fem = 0.0, promrep_mat_ot = 0.0; 
    float promrep_soc_masc = 0.0, promrep_soc_fem = 0.0, promrep_soc_ot = 0.0;
    float prompas_soc_masc = 0.0, prompas_soc_fem = 0.0, prompas_soc_ot = 0.0; 
    float prompas_bio_masc = 0.0, prompas_bio_fem = 0.0, prompas_bio_ot = 0.0;
    float promrep_bio_masc = 0.0, promrep_bio_fem = 0.0, promrep_bio_ot = 0.0; 
    float prompas_fis_masc = 0.0, prompas_fis_fem = 0.0, prompas_fis_ot = 0.0; 
    float promrep_fis_masc = 0.0, promrep_fis_fem = 0.0, promrep_fis_ot = 0.0;
    float prompas_ef_masc = 0.0, prompas_ef_fem = 0.0, prompas_ef_ot = 0.0; 
    float promrep_ef_masc = 0.0, promrep_ef_fem = 0.0, promrep_ef_ot = 0.0;
    float prompas_art_masc = 0.0, prompas_art_fem = 0.0, prompas_art_ot = 0.0;
    float promrep_art_masc = 0.0, promrep_art_fem = 0.0, promrep_art_ot = 0.0;

    float masc = 0.0, fem = 0.0, otro = 0.0;

    ifstream infile;
    infile.open("Datos_Estudiantes.csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        string M = "Male";
        string F = "Female";

        getline(infile, linea);

        while (getline(infile, linea))
        {   
            stringstream token(linea);
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, email, ';');
            getline(token, genero, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, fisica, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');
            
                if(genero == M)
                {
                    masc++;

                    if(stof(matematicas) >= 10) {apmat_masc++;} else{repmat_masc++;}
                    if(stof(sociales) >= 10) {apsoc_masc++;} else{repsoc_masc++;}
                    if(stof(biologia) >= 10) {apbio_masc++;} else{repbio_masc++;}
                    if(stof(fisica) >= 10) {apfis_masc++;} else{repfis_masc++;}
                    if(stof(educ_fisica) >= 10) {apef_masc++;} else{repef_masc++;}
                    if(stof(artes) >= 10) {apart_masc++;} else{repart_masc++;}   
                }

                if(genero == F)
                {
                    fem++;

                    if(stof(matematicas) >= 10) {apmat_fem++;} else{repmat_fem++;}
                    if(stof(sociales) >= 10) {apsoc_fem++;} else{repsoc_fem++;}
                    if(stof(biologia) >= 10) {apbio_fem++;} else{repbio_fem++;}
                    if(stof(fisica) >= 10) {apfis_fem++;} else{repfis_fem++;}
                    if(stof(educ_fisica) >= 10) {apef_fem++;} else{repef_fem++;}
                    if(stof(artes) >= 10) {apart_fem++;} else{repart_fem++;}   
                }

                if(!(genero == M) && !(genero == F))
                {
                    otro++;

                    if(stof(matematicas) >= 10) {apmat_ot++;} else{repmat_ot++;}
                    if(stof(sociales) >= 10) {apsoc_ot++;} else{repsoc_ot++;}
                    if(stof(biologia) >= 10) {apbio_ot++;} else{repbio_ot++;}
                    if(stof(fisica) >= 10) {apfis_ot++;} else{repfis_ot++;}
                    if(stof(educ_fisica) >= 10) {apef_ot++;} else{repef_ot++;}
                    if(stof(artes) >= 10) {apart_ot++;} else{repart_ot++;}   
                }
        }

        prompas_mat_masc = (apmat_masc / masc)*100;
        prompas_mat_fem = (apmat_fem / fem)*100;
        prompas_mat_ot = (apmat_ot / otro)*100;
        promrep_mat_masc = (repmat_masc / masc)*100;
        promrep_mat_fem = (repmat_fem / fem)*100;
        promrep_mat_ot = (repmat_ot / otro)*100;

        prompas_soc_masc = (apsoc_masc / masc)*100;
        prompas_soc_fem = (apsoc_fem / fem)*100;
        prompas_soc_ot = (apsoc_ot / otro)*100;
        promrep_soc_masc = (repsoc_masc / masc)*100;
        promrep_soc_fem = (repsoc_fem / fem)*100;
        promrep_soc_ot = (repsoc_ot / otro)*100;

        prompas_bio_masc = (apbio_masc / masc)*100;
        prompas_bio_fem = (apbio_fem / fem)*100;
        prompas_bio_ot = (apbio_ot / otro)*100;
        promrep_bio_masc = (repbio_masc / masc)*100;
        promrep_bio_fem = (repbio_fem / fem)*100;
        promrep_bio_ot = (repbio_ot / otro)*100;

        prompas_fis_masc = (apfis_masc / masc)*100;
        prompas_fis_fem = (apfis_fem / fem)*100;
        prompas_fis_ot = (apfis_ot / otro)*100;
        promrep_fis_masc = (repfis_masc / masc)*100;
        promrep_fis_fem = (repfis_fem / fem)*100;
        promrep_fis_ot = (repfis_ot / otro)*100;
        
        prompas_ef_masc = (apef_masc / masc)*100;
        prompas_ef_fem = (apef_fem / fem)*100;
        prompas_ef_ot = (apef_ot / otro)*100;
        promrep_ef_masc = (repef_masc / masc)*100;
        promrep_ef_fem = (repef_fem / fem)*100;
        promrep_ef_ot = (repef_ot / otro)*100;

        prompas_art_masc = (apart_masc / masc)*100;
        prompas_art_fem = (apart_fem / fem)*100;
        prompas_art_ot = (apart_ot / otro)*100;
        promrep_art_masc = (repart_masc / masc)*100;
        promrep_art_fem = (repart_fem / fem)*100;
        promrep_art_ot = (repart_ot / otro)*100;

        cout << endl << "-- Proporcion de genero en matematicas --" << endl
            << "Femenino: " << prompas_mat_fem << "% " << "pasados, " << promrep_mat_fem << "% no pasados" << endl
            << "Masculino: " << prompas_mat_masc << "% " << "pasados, " << promrep_mat_masc << "% no pasados" << endl
            << "Otros generos: " << prompas_mat_ot << "% " << "pasados, " << promrep_mat_ot << "% no pasados" << endl << endl;

        cout << "-- Proporcion de genero en sociales --" << endl
            << "Femenino: " << prompas_soc_fem << "% " << "pasados, " << promrep_soc_fem << "% no pasados" << endl
            << "Masculino: " << prompas_soc_masc << "% " << "pasados, " << promrep_soc_masc << "% no pasados" << endl
            << "Otros generos: " << prompas_soc_ot << "% " << "pasados, " << promrep_soc_ot << "% no pasados" << endl << endl;
        
        cout << "-- Proporcion de genero en biologia --" << endl
            << "Femenino: " << prompas_bio_fem << "%" << " pasados, " << promrep_bio_fem << "% no pasados" << endl
            << "Masculino: " << prompas_bio_masc << "%" << " pasados, " << promrep_bio_masc << "% no pasados" << endl
            << "Otros generos: " << prompas_bio_ot << "%" << " pasados, " << promrep_bio_ot << "% no pasados" << endl << endl;
        
        cout << "-- Proporcion de genero en fisica --" << endl
            << "Femenino :" << prompas_fis_fem << "% " << " pasados, " << promrep_fis_fem << "% no pasados" << endl
            << "Masculino :" << prompas_fis_masc << "%" << " pasados, " << promrep_fis_masc << "% no pasados" << endl
            << "Otros generos :" << prompas_fis_ot << "%" << " pasados, " << promrep_fis_ot << " % no pasados" << endl << endl;

        cout << "-- Proporcion de genero en educacion fisica --" << endl
            << "Femenino: " << prompas_ef_fem << "% " << " pasados, " << promrep_ef_fem << "% no pasados" << endl
            << "Masculino: " << prompas_ef_masc << "%" << " pasados, " << promrep_ef_masc << "% no pasados" << endl
            << "Otros generos: " << prompas_ef_ot << "%" << " pasados, " << promrep_ef_ot << "% no pasados" << endl << endl;
        
        cout << "-- Proporcion de genero en artes --" << endl
            << "Femenino: " << prompas_art_fem << "% " << "pasados, " << promrep_art_fem << "% no pasados" << endl
            << "Masculino: " << prompas_art_masc << "% " << "pasados, " << promrep_art_masc << "% no pasados" << endl
            << "Otros generos: " << prompas_art_ot << "% " << "pasados, " << promrep_art_ot << "% no pasados" << endl << endl;
    }
    infile.close();
}

int main()
{

    int opcion, opcion2;

    do
    {
        cout << endl
             << "***********************************************************" << endl
             << "           -- Sistema de notas --" << endl
             << endl
             << "1. Mostrar estudiante/s y su nota promedio" << endl
             << "2. Mostrar materias y cantidad de alumnos (pasados, no pasados, total)  " << endl
             << "3. Editar informacion de estudiantes" << endl
             << "4. Agregar estudiante nuevo" << endl
             << "5. Promedio de notas por materia" << endl
             << "6. Mejores 10 estudiantes por materia" << endl
             << "7. Generar boleta/s" << endl
             << "8. Proporcion de generos por materia (aprobados y reprobados)" << endl
             << "0. Cerrar programa " << endl
             << "*************************************************************" << endl
             << " : ";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << endl 

                 << "1. Mostrar todos los estudiantes" << endl
                 << "2. Mostrar un estudiante" << endl
                 << ": ";

            cin >> opcion2;

            switch(opcion2)
            {
            case 1:
                todos_los_estudiantes();
            break;

            case 2:
                mostrar_estudiante();
            break;

            default:
                cout << "Opcion incorrecta" << endl << endl;
                break;
            }

            break;

        case 2:
            materias();
            break;

        case 3:
            editar_estudiante();
            break;

        case 4:
            anadir_estudiante();
            break;

        case 5:
            promedio_por_materia();
            break;
            
        case 6:
            top_estudiantes_por_materia();
            break;

        case 7:
            boletas();
            break;
        
        case 8:
            proporcion_genero_x_materia();
            break;
        
        case 0:

            return 0;

        default:
            cout << "Opcion incorrecta";
            return 0;
        }

    } while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6 || opcion == 7 || opcion == 8);
}