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

//Dandole los procesos a las funciones
void todos_los_estudiantes()
{
    ifstream archivo("c://Prueba//Datos_Estudiantes.csv", ios::in);
    if (!archivo)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;

        while (getline(archivo, linea))
        {
            int numestudiantes = 0;

            getline(archivo, nombre, ';');
            getline(archivo, apellido, ';');
            getline(archivo, email, ';');
            getline(archivo, genero, ';');
            getline(archivo, matematicas, ';');
            getline(archivo, sociales, ';');
            getline(archivo, biologia, ';');
            getline(archivo, fisica, ';');
            getline(archivo, educ_fisica, ';');
            getline(archivo, artes, '\n');

            cout << "Nombre: " << nombre << ", "
                 << "Apellido: " << apellido << ", ";
            float promedio;
            promedio = (stof(matematicas) + stof(sociales) + stof(biologia) + stof(fisica) + stof(educ_fisica) + stof(artes)) / 6;

            cout << "Promedio: " << promedio << endl;

            numestudiantes++;
        }
    }
    archivo.close();
}

int main()
{

    int opcion;

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
            todos_los_estudiantes();
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