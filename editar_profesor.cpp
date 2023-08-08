#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

void editar_profesor()
{
ifstream infile;
infile.open("datos_profesores.csv");
ofstream outfile;
outfile.open("datos_profesores_auxiliar.csv");
    if (!infile||!outfile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, id, nombre, apellido, genero, email, seccion, id_materia;
        string nombre_nuevo, apellido_nuevo, genero_nuevo, email_nuevo, seccion_nuevo, id_materia_nuevo;
        bool existe = false;
        fflush(stdin);

        
        cout << "Ingrese el ID del profesor que desea modificar: ";
        int id_buscar;
        cin >> id_buscar;

        getline(infile, linea);
        outfile << linea << endl;

        while(getline(infile, linea))
        {
            stringstream token(linea);
            getline(token, id, ',');
            getline(token, nombre, ',');
            getline(token, apellido, ',');
            getline(token, genero, ',');
            getline(token, email, ',');
            getline(token, seccion, ',');
            getline(token, id_materia, ',');
                
                if(stoi(id) == id_buscar)
                {
                existe = true;
                
                cout<< "Se ha encontrado el producto" << endl
                    << "1. Modificar nombre" << endl
                    << "2. Modificar apellido" << endl
                    << "3. Modificar genero" << endl
                    << "4. Modificar email" << endl
                    << "5. Modificar seccion" << endl
                    << "6. Modificar ID de materia" << endl
                    << "7. Modificar todo" << endl
                    << ": ";

                int opcion;
                cin >> opcion;

                switch(opcion)
                {
                    case 1:
                    cout << endl << "Nuevo nombre: ";
                    cin >> nombre_nuevo;
                    outfile << id << "," << nombre_nuevo << "," << apellido << "," << genero << "," << email<< "," << seccion << "," 
                            << id_materia << endl;
                    break;

                    case 2:
                    cout << endl << "Nuevo apellido: ";
                    cin >> apellido_nuevo;
                    outfile << id << "," << nombre << "," << apellido_nuevo << "," << genero << "," << email<< "," << seccion << "," 
                            << id_materia << endl;
                    break;

                    case 3: 
                    cout << endl << "Nuevo genero: ";
                    cin >> genero_nuevo;
                    outfile << id << "," << nombre << "," << apellido << "," << genero_nuevo << "," << email<< "," << seccion << "," 
                            << id_materia << endl;
                    break;

                    case 4:
                    cout << endl << "Nuevo email: ";
                    cin >> email_nuevo;
                    if(frecuencia_profesores(email_nuevo) == 0){
                    outfile << id << "," << nombre << "," << apellido << "," << genero << "," << email_nuevo << "," << seccion << "," 
                            << id_materia << endl;
                    }else{
                    outfile << id << "," << nombre << "," << apellido << "," << genero << "," << email<< "," << seccion << "," 
                            << id_materia << endl;
                    cout << "El profesor con el email: " << email_nuevo << " ya se encuentra en el sistema" << endl;
                    }
                    break;

                    case 5:
                    cout << endl << "Nueva seccion (A - F): ";
                    cin >> seccion_nuevo;
                    outfile << id << "," << nombre << "," << apellido << "," << genero << "," << email<< "," << seccion_nuevo << "," 
                            << id_materia << endl;
                    break;

                    case 6:
                    cout << endl << "Nuevo ID de materia (1001 - 1005): ";
                    cin >> id_materia_nuevo;
                    outfile << id << "," << nombre << "," << apellido << "," << genero << "," << email<< "," << seccion << "," 
                            << id_materia_nuevo << endl;
                    break;

                    case 7:
                    cout << endl << "Nuevo email: ";
                    cin >> email_nuevo; 
                    if(frecuencia_profesores(email_nuevo) == 0){
                    cout << endl << "Nuevo nombre: ";
                    cin >> nombre_nuevo;
                    cout << endl << "Nuevo apellido: ";
                    cin >> apellido_nuevo;
                    cout << endl << "Nuevo genero: "; 
                    cin >> genero_nuevo;
                    cout << endl << "Nueva seccion (A - F): ";
                    cin >> seccion_nuevo;
                    cout << endl << "Nuevo ID de materia (1001 - 1005): ";
                    cin >> id_materia_nuevo;

                    outfile << id << "," << nombre_nuevo << "," << apellido_nuevo << "," << genero_nuevo << "," << email_nuevo << "," << seccion_nuevo << "," 
                            << id_materia_nuevo << endl;
                    break;

                    default:
                        cout << "Opcion incorrecta" << endl;
                        exit(1);
                    }else{
                    outfile << id << "," << nombre << "," << apellido << "," << genero << "," << email<< "," << seccion << "," 
                            << id_materia << endl;
                    }
                }
                cout << endl << "Se ha modificado el profesor correctamente" << endl;
                
            }
        else
        {
            outfile << id << "," << nombre << "," << apellido << "," << genero << "," << email<< "," << seccion << "," 
                    << id_materia << endl;
        }
    }

    if(existe == false)
        {
        cout << "No se encontro el profesor con el ID " << id_buscar << endl;
        
        }
        infile.close();
        outfile.close();
    }
    remove("datos_profesores.csv");
    rename("datos_profesores_auxiliar.csv", "datos_profesores.csv");
}