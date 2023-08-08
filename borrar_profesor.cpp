#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void borrar_profesor() {
    ifstream infile("datos_profesores.csv");
    ofstream outfile("datos_profesores_auxiliar.csv");
    if (!infile || !outfile) {
        cout << "Error al abrir el archivo" << endl;
    } else {
        string linea, id, nombre, apellido, genero, email, seccion, id_materia;
        bool existe = false;

        cout << "Ingrese el ID del estudiante que desea borrar: ";
        int id_buscar;
        cin >> id_buscar;

        getline(infile, linea);
        outfile << linea << endl;

        while (getline(infile, linea)) {
            stringstream token(linea);
            getline(token, id, ',');
            getline(token, nombre, ',');
            getline(token, apellido, ',');
            getline(token, genero, ',');
            getline(token, email, ',');
            getline(token, seccion, ',');
            getline(token, id_materia, ',');

            if (!(stoi(id) == id_buscar)) {
                outfile << id << "," << nombre << "," << apellido << "," << genero << "," << email<< "," << seccion << "," 
                    << id_materia << endl;
            }else{
                 cout << "Se ha borrado el profesor del sistema" << endl;
                 existe = true;
            }   
        }

        if (!existe) {
            cout << "El profesor con ID: " << id_buscar << " no se encuentra en el sistema" << endl;
        } 

        infile.close();
        outfile.close();
        }
        remove("datos_profesores.csv");
        rename("datos_profesores_auxiliar.csv", "datos_profesores.csv");
    }