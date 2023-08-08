#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void estudiante_y_profesor(){
    cout << "Ingrese el ID del estudiante que desea buscar: ";
    int id_buscar;
    cin >> id_buscar;

    ifstream infile;
    infile.open("datos_estudiantes(2).csv");
    if(!infile){
        cout << "Error" << endl;
        exit(1);
    }

    string linea, id, nombre, apellido, genero, email, seccion, matematicas, sociales, biologia, ef, artes;
    string nombre_est, apellido_est, seccion_est;
    int id_est;
    string secciones[7] = {"A", "B", "C", "D", "E", "F"};
    string seccion_estudiante;
    bool existe = false;

    getline(infile, linea);
    while(getline(infile, linea)){
        stringstream token(linea);
        getline(token, id, ',');
        getline(token, nombre, ',');
        getline(token, apellido, ',');
        getline(token, genero, ',');
        getline(token, email, ',');
        getline(token, seccion, ',');
        getline(token, matematicas, ',');
        getline(token, sociales, ',');
        getline(token, biologia, ',');
        getline(token, ef, ',');
        getline(token, artes, ',');

        if(stoi(id) == id_buscar){
            existe = true;
            for(int i=0; i<6; i++){
                if(seccion == secciones[i]){
                    seccion_estudiante = secciones[i];
                    nombre_est = nombre;
                    apellido_est = apellido,
                    id_est = stoi(id);
                    seccion_est = seccion;
                }
            }
        }
    }

    if(!existe){
        cout << "No hay un estudiante con el ID: " << id_buscar << " en el sistema" << endl;
        exit (1);
    }
        
    infile.close();

    if(existe){
        ifstream infile;
        infile.open("datos_profesores.csv");
        if(!infile){
            cout << "Error" << endl;
            exit(1);
        }
        cout << endl << "Estudiante encontrado" << endl;
        cout << "ID: " << id_est << endl;
        cout << "Nombre: " << nombre_est << " " << apellido_est << endl;
        cout << "Seccion: " << seccion_est << endl << endl;

        cout << "Buscar su profesor de:" << endl;
        cout << "1. Matematicas" << endl;
        cout << "2. Sociales" << endl;
        cout << "3. Biologia" << endl;
        cout << "4. Educacion fisica" << endl;
        cout << "5. Artes" << endl;
        cout <<": ";

        int opcion;
        cin >> opcion;
        if(opcion < 1 && opcion > 5){
            cout << "Opcion invalida" << endl;
            exit(1);
        }
        
            string linea, id, id_materia, nombre, apellido, seccion, genero;
            string nombre_prof, apellido_prof, seccion_prof, materia_prof;
            int id_prof;
            bool hay_profesor = false;

            getline(infile, linea);

            while(getline(infile, linea)){
                stringstream token(linea);
                getline(token, id, ',');
                getline(token, nombre, ',');
                getline(token, apellido, ',');
                getline(token, genero, ',');
                getline(token, email, ',');
                getline(token, seccion, ',');
                getline(token, id_materia, ',');

                if(opcion == 1){
                if(stoi(id_materia) == 1001 && seccion == seccion_estudiante){
                    hay_profesor = true;
                    nombre_prof = nombre;
                    apellido_prof = apellido;
                    seccion_prof = seccion;
                    materia_prof = "Matematica";
                    id_prof = stoi(id);
                }
            }
                if(opcion ==2){
                if(stoi(id_materia) == 1002 && seccion == seccion_estudiante){
                    hay_profesor = true;
                    nombre_prof = nombre;
                    apellido_prof = apellido;
                    seccion_prof = seccion;
                    materia_prof = "Sociales";
                    id_prof = stoi(id);
                }
            }
                if(opcion == 3){
                if(stoi(id_materia) == 1003 && seccion == seccion_estudiante){
                    hay_profesor = true;
                    nombre_prof = nombre;
                    apellido_prof = apellido;
                    seccion_prof = seccion;
                    materia_prof = "Biologia";
                    id_prof = stoi(id);
                }
            }
                if(opcion == 4){
                if(stoi(id_materia) == 1004 && seccion == seccion_estudiante){
                    hay_profesor = true;
                    nombre_prof = nombre;
                    apellido_prof = apellido;
                    seccion_prof = seccion;
                    materia_prof = "Educacion fisica";
                    id_prof = stoi(id);
                }
            }
                if(opcion == 5){
                if(stoi(id_materia) == 1005 && seccion == seccion_estudiante){
                    hay_profesor = true;
                    nombre_prof = nombre;
                    apellido_prof = apellido;
                    seccion_prof = seccion;
                    materia_prof = "Artes";
                    id_prof = stoi(id);
                }
            }
        }
            if(!hay_profesor){
                cout << endl << "El estudiante esta a la espera de un nuevo profesor" << endl;
                exit(1);
            }

            cout << endl << "Informacion del profesor: " << endl;
            cout << "ID: " << id_prof << endl;
            cout << "Nombre: " << nombre_prof << endl;
            cout << "Apellido: " << apellido_prof << endl;
            cout << "Seccion: " << seccion_prof << endl;
            cout << "Materia: " << materia_prof << endl;
    }
}