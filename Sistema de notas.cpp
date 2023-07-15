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
        cout << "Error al abrir el infile" << endl;
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
                 << "apellido: " << apellido << endl
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
                     << "apellido: " << apellido << endl
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
            
            if(stoi(matematicas) >= 10)
            {
                pasados_mate++;
            }else{
                nopasados_mate++;
            }

            if(stoi(sociales) >= 10)
            {
                pasados_sociales++;
            }else{
                nopasados_sociales++;
            }

            if(stoi(biologia) >= 10)
            {
                pasados_biologia++;
            }else{
                nopasados_biologia++;
            }
                    
            if(stoi(fisica) >= 10)
            {
                pasados_fisica++;
            }else{
                nopasados_fisica++;
            }
                    
            if(stoi(educ_fisica) >= 10)
            {
                pasados_ef++;
            }else{
                nopasados_ef++;
            }
                    
            if(stoi(artes) >= 10)
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
        string nombre_nuevo, apellido_nuevo, email_nuevo, genero_nuevo, matematicas_nuevo, sociales_nuevo, biologia_nuevo, fisica_nuevo, ef_nuevo, artes_nuevo;
        bool existe = false;

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
                bool repetido = false;
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
                    cout << endl << "Nuevo genero: ";
                    cin >> genero_nuevo;
                    outfile << nombre << ";" << apellido << ";" << genero_nuevo << ";" << genero_nuevo << ";" <<  matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 5:
                    cout << endl << "Nueva nota de matematicas: ";
                    cin >> matematicas_nuevo;
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas_nuevo << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 6:
                    cout << endl << "Nueva nota de sociales: ";
                    cin >> sociales_nuevo;
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales_nuevo << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 7:
                    cout << endl << "Nueva nota de biologia: ";
                    cin >> biologia_nuevo;
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia_nuevo << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 8:
                    cout << endl << "Nueva nota de fisica: ";
                    cin >> fisica_nuevo;
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica_nuevo
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 9:
                    cout << endl << "Nueva nota de educacion fisica: ";
                    cin >> ef_nuevo;
                    outfile << nombre << ";" << apellido << ";" << email << ";" <<genero <<";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica
                             << ";" << ef_nuevo << ";" << artes << endl;
                    break;

                    case 10:
                    cout << endl << "Nueva nota de artes: ";
                    cin >> artes_nuevo;
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes_nuevo << endl;
                        break;

                    case 11:
                    cout << endl << "Nuevo nombre: ";
                    cin >> nombre_nuevo; 
                    cout << endl << "Nuevo apellido: ";
                    cin >> apellido_nuevo;
                    cout << endl << "Nuevo email: ";
                    cin >> email_nuevo;
                    cout << endl << "Nuevo genero: ";
                    cin >> genero_nuevo;
                    cout << endl << "Nueva nota en matematicas: ";
                    cin >> matematicas_nuevo;
                    cout << endl << "Nueva nota en sociales: "; 
                    cin >> sociales_nuevo;
                    cout << endl << "Nueva nota en biologia: ";
                    cin >> biologia_nuevo;
                    cout << endl << "Nueva nota en fisica: ";
                    cin >> fisica_nuevo;
                    cout << endl << "Nueva nota en educacion fisica: ";
                    cin >> ef_nuevo;
                    cout << endl << "Nueva nota en artes: ";
                    cin >> artes_nuevo;

                    outfile << nombre_nuevo << ";" << apellido_nuevo << ";" << email_nuevo << ";" << genero_nuevo << ";" << matematicas_nuevo << ";" << sociales_nuevo << ";" 
                            << biologia_nuevo << ";" << fisica_nuevo << ";" << ef_nuevo << ";" << artes_nuevo << endl;
                    break;
                }
                if(repetido = false)
                {
                cout << endl << "Se ha modificado el estudiante correctamente" << endl;
                }
            }
        else
        {
            outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica << ";"
                    << educ_fisica << ";" << artes << endl; 
        }
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
            cout << "Ingrese el genero del estudiante: ";
            cin >> genero;
            cout << "Ingrese la nota en matematicas del estudiante: ";
            cin >> matematicas;
            cout << "Ingrese la nota en sociales del estudiante: ";
            cin >> sociales;
            cout << "Ingrese la nota en biologia del estudiante: ";
            cin >> biologia;
            cout << "Ingrese la nota en fisica del estudiante: ";
            cin >> fisica;
            cout << "Ingrese la nota en educacion fisica del estudiante: ";
            cin >> educ_fisica;
            cout << "Ingrese la nota en artes del estudiante: ";
            cin >> artes;

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
        cout << "Error al abrir el infile" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        float suma_mate = 0, suma_sociales = 0, suma_biologia = 0, suma_fisica = 0, suma_ef = 0, suma_artes = 0, numestudiantes = 0;
        float promedio_mate = 0, promedio_sociales = 0, promedio_biologia = 0, promedio_fisica = 0, promedio_ef = 0, promedio_artes = 0;
        int nota = 0;

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
            nota = stoi(matematicas);
            suma_mate += nota;
            nota = stoi(sociales);
            suma_sociales += nota;
            nota = stoi(biologia);
            suma_biologia += nota;
            nota = stoi(fisica);
            suma_fisica += nota;
            nota = stoi(educ_fisica);
            suma_ef += nota;
            nota = stoi(artes);
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
        cout << "Error al abrir el infile" << endl;
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
            estudiante[numestudiantes].notas_matematica = stoi(matematicas);
            estudiante[numestudiantes].notas_sociales = stoi(sociales);
            estudiante[numestudiantes].notas_biologia = stoi(biologia);
            estudiante[numestudiantes].notas_fisica = stoi(fisica);
            estudiante[numestudiantes].notas_educ_fisica = stoi(educ_fisica);
            estudiante[numestudiantes].notas_artes = stoi(artes);
            numestudiantes++;
        }
    
            cout << "-- 10 mejores estudiantes --" << endl
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
                cout << endl << "10 Mejores estudiantes en mate: " << endl << endl;
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
             << "8. Proporcion de generos por materia (aprobados y reprobados) " << endl
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

            break;
        
        case 8:

            break;
        
        case 0:

            return 0;

        default:
            cout << "Opcion incorrecta";
            return 0;
        }

    } while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6 || opcion == 7 || opcion == 8);
}