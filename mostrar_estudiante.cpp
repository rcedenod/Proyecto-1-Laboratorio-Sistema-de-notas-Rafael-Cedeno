#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void mostrar_estudiante()
{
    ifstream infile;
    infile.open("datos_estudiantes(1).csv");
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
                 << "Nombre: " << nombre << endl
                 << "Apellido: " << apellido << endl
                 << "Email: " << email << endl
                 << "Genero: " << genero << endl
                 << "Nota en matematicas: " << matematicas << endl
                 << "Nota en sociales: " << sociales << endl
                 << "Nota en biologia: " << biologia << endl
                 << "Nota en fisica: " << fisica << endl
                 << "Nota en educacion fisica: " << educ_fisica << endl
                 << "Nota en artes: " << artes << endl
                 << "Promedio: " << promedio << endl << endl;
            }
        }
    }
    infile.close();
}