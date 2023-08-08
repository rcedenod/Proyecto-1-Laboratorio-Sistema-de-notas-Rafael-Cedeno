#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void anadir_estudiante()
{
    ofstream infile;
    infile.open("datos_estudiantes(1).csv", ios::app);
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