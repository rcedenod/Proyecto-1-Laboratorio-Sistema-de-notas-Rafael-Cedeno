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
#include "proporcion_genero_x_materia.cpp"
#include "borrar_estudiante.cpp"
#include "top_estudiantes_x_seccion.cpp"
#include "rendimiento_profesor.cpp"
#include "mejores_profesores.cpp"
#include "anadir_profesor.cpp"
#include "editar_profesor.cpp"
#include "borrar_profesor.cpp"
#include "estudiante_y_profesor.cpp"

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
             << "9. Borrar un estudiante" << endl
             << "10. Top 10 por seccion" << endl
             << "11. Rendimiento de un profesor" << endl
             << "12. Mejores profesores (materia / seccion)" << endl
             << "13. Agregar profesor nuevo" << endl
             << "14. Editar informacion de profesor" << endl
             << "15. Borrar un profesor" << endl
             << "16. Buscar estudiante y su profesor de materia" << endl
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
        
        case 9:
            borrar_estudiante();
            break;

        case 10:
            top_estudiantes_x_seccion();
            break;
        
        case 11:
            rendimiento_profesor();
            break;
        
        case 12:
            mejores_profesores();
            break;
        
        case 13:
            anadir_profesor();
            break;
        
        case 14:
            editar_profesor();
            break;
        
        case 15:
            borrar_profesor();
            break;
        
        case 16:
            estudiante_y_profesor();
            break;
        
        case 0:

            return 0;

        default:
            cout << "Opcion incorrecta";
            return 0;
        }

    } while (opcion > 0 && opcion <= 16);
}
