#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void rendimiento_profesor(){
    ifstream infile;
    infile.open("datos_estudiantes(2).csv");
    if(!infile){
        cout << "Error" << endl;
        exit(1);
    }
    
    string linea, id, nombre, apellido, genero, email, seccion, matematicas, sociales, biologia, ef, artes;
    string secciones[6] = {"A", "B", "C", "D", "E", "F"};
    float contador_seccion[6] = {0,0,0,0,0,0};

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

        if(seccion == secciones[0]){
            contador_seccion[0]++;
        }
        if(seccion == secciones[1]){
            contador_seccion[1]++;
        } 
        if(seccion == secciones[2]){
            contador_seccion[2]++;
        } 
        if(seccion == secciones[3]){
            contador_seccion[3]++;
        } 
        if(seccion == secciones[4]){
            contador_seccion[4]++;
        } 
        if(seccion == secciones[5]){
            contador_seccion[5]++;
        }  
    }

    infile.clear();
    infile.seekg(0, ios::beg);

    float pasados_mate[6] = {0,0,0,0,0,0} , pasados_soc[6] = {0,0,0,0,0,0} , pasados_bio[6] = {0,0,0,0,0,0};
    float pasados_ef[6] = {0,0,0,0,0,0} , pasados_art[6] = {0,0,0,0,0,0};

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

        for(int i=0; i<6; i++){
            if(seccion == secciones[i] && stof(matematicas)>=10){
                pasados_mate[i]++;
            }
        }
        for(int i=0; i<6; i++){
            if(seccion == secciones[i] && stof(sociales)>=10){
                pasados_soc[i]++;
            }
        }
        for(int i=0; i<6; i++){
            if(seccion == secciones[i] && stof(biologia)>=10){
                pasados_bio[i]++;
            }
        }
        for(int i=0; i<6; i++){
            if(seccion == secciones[i] && stof(ef)>=10){
                pasados_ef[i]++;
            }
        }
        for(int i=0; i<6; i++){
            if(seccion == secciones[i] && stof(artes)>=10){
                pasados_art[i]++;
            }
        }
    }

    infile.close();

    ifstream profesores;
    profesores.open("datos_profesores.csv");
    if(!profesores){
        cout << "Error" << endl;
    }

    cout << "Ingrese el ID del profesor para ver su rendimiento: ";
    int id_buscar;
    cin >> id_buscar;

    string id_materia, nombre_prof, apellido_prof, materia_prof, seccion_prof;
    float medidor = 0;
    bool existe = false;

    getline(profesores, linea);
    while(getline(profesores, linea)){
        stringstream token(linea);
        getline(token, id, ',');
        getline(token, nombre, ',');
        getline(token, apellido, ',');
        getline(token, genero, ',');
        getline(token, email, ',');
        getline(token, seccion, ',');
        getline(token, id_materia, ',');

        if(stoi(id) == id_buscar){
            existe = true;
            nombre_prof = nombre;
            apellido_prof = apellido;
            


            if(stoi(id_materia) == 1001){
                materia_prof = "Matematica";
                for(int i=0; i<6; i++){
                if(seccion == secciones[i]){
                    seccion_prof = secciones[i];
                    medidor = (pasados_mate[i] * 100)/contador_seccion[i];
                    }
                }
            }
            if(stoi(id_materia) == 1002){
                materia_prof = "Sociales";
                for(int i=0; i<6; i++){
                if(seccion == secciones[i]){
                    seccion_prof = secciones[i];
                    medidor = (pasados_soc[i] * 100)/contador_seccion[i];
                    }
                }
            }
            if(stoi(id_materia) == 1003){
                materia_prof = "Biologia";
                for(int i=0; i<6; i++){
                if(seccion == secciones[i]){
                    seccion_prof = secciones[i];
                    medidor = (pasados_bio[i] * 100)/contador_seccion[i];
                    }
                }
            }
            if(stoi(id_materia) == 1004){
                materia_prof = "Educacion fisica";
                for(int i=0; i<6; i++){
                if(seccion == secciones[i]){
                    seccion_prof = secciones[i];
                    medidor = (pasados_ef[i] * 100)/contador_seccion[i];
                    }
                }
            }
            if(stoi(id_materia) == 1005){
                materia_prof = "Artes";
                for(int i=0; i<6; i++){
                if(seccion == secciones[i]){
                    seccion_prof = secciones[i];
                    medidor = (pasados_art[i] * 100)/contador_seccion[i];
                    }
                }
            }
        }
    }
    if(!existe){
        cout << "No se encontro el profesor con el ID: " << id_buscar << endl;
        exit(1);
    }
    if(medidor < 30 && medidor >= 0){
        cout << "Profeso/ar: " << nombre_prof << " " << apellido_prof << endl
             << "Materia: " << materia_prof << endl
             << "Seccion: " << seccion_prof << endl 
             << "Porcentaje de alumnos pasados: " << medidor << " %" << endl
             << "Rendimiento: Malo" << endl;
    }
    if(medidor >= 30 && medidor < 60){
        cout << "Profesor/a: " << nombre_prof << " " << apellido_prof << endl
             << "Materia: " << materia_prof << endl
             << "Seccion: " << seccion_prof << endl 
             << "Porcentaje de alumnos pasados: " << medidor << " %" << endl
             << "Rendimiento: Aceptable" << endl;
    }
    if(medidor >= 60 && medidor <= 100){
        cout << "Profesor/a: " << nombre_prof << " " << apellido_prof << endl
             << "Materia: " << materia_prof << endl
             << "Seccion: " << seccion_prof << endl 
             << "Porcentaje de alumnos pasados: " << medidor << " %" << endl
             << "Rendimiento: Bueno" << endl;
    }
    profesores.close();
}
