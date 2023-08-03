#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int frecuencia(string email_ingresado)
{
    int contador = 0;
    ifstream infile;
    infile.open("datos_estudiantes(1).csv");

    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
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
