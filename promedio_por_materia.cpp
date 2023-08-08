#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void promedio_por_materia()
{
    ifstream infile;
    infile.open("datos_estudiantes(1).csv");
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
