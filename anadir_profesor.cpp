#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void anadir_profesor()
{
    int id_automatico = 1;
    
    ifstream infile;
    infile.open("datos_profesores.csv", ios::in);
    if(!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, id, nombre, apellido, genero, email, seccion, id_materia;
        getline(infile, linea);
        while(getline(infile, linea))
        {
            stringstream token(linea);
            getline(token, id, ',');
            getline(token, nombre, ',');
            getline(token, apellido, ',');
            getline(token, genero, ',');
            getline(token, email, ',');
            getline(token, seccion, ',');
            getline(token,id_materia, ',');
            id_automatico++;
        }
        infile.close();
    }

    ofstream outfile;
    outfile.open("datos_profesores.csv", ios::app);
    if (!outfile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string nombre, apellido, genero, email, seccion;
        int id_materia = 0;
        fflush(stdin);

            cout << endl;
            cout << "Ingrese el email de profesor:  ";
            cin >> email;
            if(frecuencia_profesores(email) == 0){
            cout << "Ingrese el nombre del profesor: ";
            cin >> nombre;
            cout << "Ingrese el apellido del profesor: ";
            cin >> apellido;
            cout << "Ingrese el genero del profesor: ";
            cin >> genero;
            cout << "Ingrese la seccion de profesor (A - F): ";
            cin >> seccion;
            cout << "Ingrese el id de materia del profesor (1001 - 1005): ";
            cin >> id_materia;

            outfile << "\n" << id_automatico << "," << nombre << "," << apellido << "," << genero << "," << email<< "," << seccion << "," 
                    << id_materia;

            outfile.close();
            
            cout << endl
                << "Se ingreso con exito el profesor" << endl
                << endl; 
            }else{
                cout << "El profesor con el email: " << email << " ya se encuentra en el sistema" << endl;
                outfile.close();
                exit(1);
            }
    }
}