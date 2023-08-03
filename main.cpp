#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "quicksort.cpp"
#include "frecuencia.cpp"
#include "todos_los_estudiantes.cpp"
#include "mostrar_estudiante.cpp"
#include "materias.cpp"
#include "editar_estudiante.cpp"
#include "anadir_estudiante.cpp"
#include "promedio_por_materia.cpp"
#include "top_estudiantes_x_materia.cpp"
#include "boletas.cpp"

using namespace std;

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
            top_estudiantes_x_materia();
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