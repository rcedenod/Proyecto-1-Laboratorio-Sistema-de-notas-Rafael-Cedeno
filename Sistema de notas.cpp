#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Estudiantes
{
    string nombre;
    string apellnombreo;
    string email;
    string genero;
    int notas_matematica;
    int notas_sociales;
    int notas_biologia;
    int notas_fisica;
    int notas_educ_fisica;
    int notas_artes;
};

//Funciones que se van a usar:
void todos_los_estudiantes();
void mostrar_estudiante();
void materias();
void editar_estudiante();

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
        string linea, nombre, apellnombreo, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;

        getline(infile, linea);

        while (!infile.eof())
        {
            getline(infile, nombre, ';');
            getline(infile, apellnombreo, ';');
            getline(infile, email, ';');
            getline(infile, genero, ';');
            getline(infile, matematicas, ';');
            getline(infile, sociales, ';');
            getline(infile, biologia, ';');
            getline(infile, fisica, ';');
            getline(infile, educ_fisica, ';');
            getline(infile, artes, '\n');

            if(nombre.empty())
                {
                    break;
                }

            float promedio;
            promedio = (stof(matematicas) + stof(sociales) + stof(biologia) + stof(fisica) + stof(educ_fisica) + stof(artes)) / 6;

            cout << endl 
                 << "Nombre: " << nombre << endl
                 << "Apellnombreo: " << apellnombreo << endl
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
        string linea, nombre, nombre_buscar, apellnombreo, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;

        cout << endl << "Ingrese el nombre del estudiante a buscar: ";
        cin >> nombre_buscar;

        getline(infile, linea);

        while (!infile.eof())
        {
            getline(infile, nombre, ';');
            getline(infile, apellnombreo, ';');
            getline(infile, email, ';');
            getline(infile, genero, ';');
            getline(infile, matematicas, ';');
            getline(infile, sociales, ';');
            getline(infile, biologia, ';');
            getline(infile, fisica, ';');
            getline(infile, educ_fisica, ';');
            getline(infile, artes, '\n');

            if(nombre.empty())
                {
                    break;
                }

            float promedio;
            promedio = (stof(matematicas) + stof(sociales) + stof(biologia) + stof(fisica) + stof(educ_fisica) + stof(artes)) / 6;

            if(nombre_buscar == nombre)
            {
                cout << endl 
                     << "Estudiante encontrado" << endl
                     << "Nombre: " << nombre << endl
                     << "Apellnombreo: " << apellnombreo << endl
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
        string linea, nombre, nombre_buscar, apellnombreo, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        int pasados_mate = 0, nopasados_mate = 0, pasados_sociales = 0, nopasados_sociales = 0, pasados_biologia = 0, nopasados_biologia = 0;
        int pasados_fisica = 0, nopasados_fisica = 0, pasados_ef = 0, nopasados_ef = 0, pasados_artes = 0, nopasados_artes = 0, total = 0;

        getline(infile, linea);

        while (!infile.eof())
        {
            getline(infile, nombre, ';');
            getline(infile, apellnombreo, ';');
            getline(infile, email, ';');
            getline(infile, genero, ';');
            getline(infile, matematicas, ';');
            getline(infile, sociales, ';');
            getline(infile, biologia, ';');
            getline(infile, fisica, ';');
            getline(infile, educ_fisica, ';');
            getline(infile, artes, '\n');

            if(nombre.empty())
                {
                    break;
                }
            
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
             << "2. Mostrar materias y la cantnombread de alumnos (total, pasados y no pasados)  " << endl
             << "3. Editar informacion de estudiantes" << endl
             << "4. Agregar estudiante nuevo" << endl
             << "5. Sacar promedio de notas por materia " << endl
             << "6. Top 10 estudiantes por materia" << endl
             << "7. Crear boleta/s" << endl
             << "8. Proporcion de generos por materia aprobada y reprobada " << endl
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

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

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

    } while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6 || opcion == 7);
}