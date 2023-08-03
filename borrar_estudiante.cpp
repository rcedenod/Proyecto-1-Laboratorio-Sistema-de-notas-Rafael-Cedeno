#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void borrar_estudiante()
{
    ifstream infile;
    infile.open("datos_estudiantes(2).csv");
    ofstream outfile;
    outfile.open("datos_estudiantes(2)_auxiliar.csv");
    if(!infile || !outfile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, id, nombre, apellido, genero, email, seccion, matematicas, sociales, biologia, educ_fisica, artes;
        bool existe = false;

        cout << "Ingrese el ID del estudiante que desea borrar: ";
        int id_buscar;
        cin >> id_buscar;

        getline(infile, linea);
        outfile << linea << endl;

        while(getline(infile, linea))
        {
            stringstream token(linea);
            getline(token, id, ';');
            getline(token, nombre, ';');
            getline(token, apellido, ';');
            getline(token, genero, ';');
            getline(token, email, ';');
            getline(token, seccion, ';');
            getline(token, matematicas, ';');
            getline(token, sociales, ';');
            getline(token, biologia, ';');
            getline(token, educ_fisica, ';');
            getline(token, artes, '\n');

            if(!(stoi(id) == id_buscar))
            {
                outfile << id << ";" << nombre << ";" << apellido << ";" << genero << ";" << email << ";" << seccion << ";" <<  matematicas << ";" << sociales << ";" 
                << biologia << ";" << educ_fisica << ";" << artes << endl;
            }else{
                cout << "Se ha borrado el estudiante del sistema" << endl;
                existe = true;
            }
        }
        infile.close();
        if(!existe)
        {
            cout<<"El estudiante con ID: "<< id_buscar <<" no se encuentra en el sistema"<<endl;
        }
        infile.close();
        outfile.close();
    }
    remove("datos_estudiantes(2).csv");
    rename("datos_estudiantes(2)_auxiliar.csv", "datos_estudiantes(2).csv");
}