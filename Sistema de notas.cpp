#include <iostream>
#include <fstream>
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

//Funciones que se van a usar:
void todos_los_estudiantes();
void mostrar_estudiante();

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

        while (!infile.eof())
        {
            getline(infile, nombre, ';');
            getline(infile, apellido, ';');
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

            cout << "Nombre: " << nombre << endl
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

        cout << "Ingrese el nombre del estudiante a buscar: ";
        cin >> nombre_buscar;

        getline(infile, linea);

        while (!infile.eof())
        {
            getline(infile, nombre, ';');
            getline(infile, apellido, ';');
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
                cout << "Estudiante encontrado" << endl
                     << "Nombre: " << nombre << endl
                     << "Apellido: " << apellido << endl
                     << "Promedio: " << promedio << endl << endl;
            }
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
             << "2. Mostrar materias y la cantidad de alumnos (total, pasados y no pasados)  " << endl
             << "3. Editar información de estudiantes" << endl
             << "4. Agregar estudiante nuevo" << endl
             << "5. Sacar promedio de notas por materia " << endl
             << "6. Realizar compra" << endl
             << "7. Top 10 estudiantes por materia" << endl
             << "8. Crear boleta/s" << endl
             << "9. Proporción de géneros por materia aprobada y reprobada " << endl
             << "0. Cerrar programa " << endl
             << "*************************************************************" << endl
             << " : ";

        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "1. Mostrar todos los estudiantes" << endl
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

        default:

            return 0;
        }

    } while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6 || opcion == 7);
}