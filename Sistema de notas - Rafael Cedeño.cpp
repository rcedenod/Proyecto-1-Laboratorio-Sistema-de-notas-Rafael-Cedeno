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

        case 8:
            
            break;
            
        case 9:
            
            break;

        case 0:

            return 0;

         default:
             
            cout << "Opcion incorrecta" ;
            return 0;
        }

    } while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5 || opcion == 6 || opcion == 7);
}
