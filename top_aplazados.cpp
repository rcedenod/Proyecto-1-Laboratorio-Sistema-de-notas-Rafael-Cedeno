#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Aplazados {
    string nombre;
    string apellido;
    string seccion;
    int id;
    int materias_aplazadas;
};

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, Aplazados** alumnos, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) { 
            i++;
            swap(&arr[i], &arr[j]);
            swap(alumnos[i], alumnos[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    swap(alumnos[i + 1], alumnos[high]);
    return i + 1;
}

void quickSort(int* arr, Aplazados** alumnos, int low, int high) {
    if (low < high) {
        int pi = partition(arr, alumnos, low, high);

        quickSort(arr, alumnos, low, pi - 1);
        quickSort(arr, alumnos, pi + 1, high);
    }
}

void top_aplazados() {
    ifstream infile;
    infile.open("datos_estudiantes(2).csv");
    if (!infile) {
        cout << "Error al abrir el archivo" << endl;
        exit(1);
    }

    string linea, id, nombre, apellido, genero, email, seccion, matematicas, sociales, biologia, ef, artes;
    int tamano = 10;
    int* materias_aplazadas = new int[tamano](); 
    int contador_estudiantes = 0;

    getline(infile, linea); 
    while (getline(infile, linea)) {
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

        int materias_aplazadas_estudiante = 0;
        if (stof(matematicas) < 10) {
            materias_aplazadas_estudiante++;
        }
        if (stof(sociales) < 10) {
            materias_aplazadas_estudiante++;
        }
        if (stof(biologia) < 10) {
            materias_aplazadas_estudiante++;
        }
        if (stof(ef) < 10) {
            materias_aplazadas_estudiante++;
        }
        if (stof(artes) < 10) {
            materias_aplazadas_estudiante++;
        }

        if (contador_estudiantes >= tamano) {
            int nuevo_tamano = tamano * 2;
            int* temp = materias_aplazadas;
            materias_aplazadas = new int[nuevo_tamano]();
            for (int i = 0; i < tamano; i++) {
                materias_aplazadas[i] = temp[i];
            }
            delete[] temp;
            tamano = nuevo_tamano;
        }

        materias_aplazadas[contador_estudiantes] = materias_aplazadas_estudiante;
        contador_estudiantes++;
    }

    Aplazados** aplazados = new Aplazados*[contador_estudiantes];

    infile.clear(); 
    infile.seekg(0, ios::beg); 

    getline(infile, linea); 
    contador_estudiantes = 0;
    while (getline(infile, linea)) {
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

        aplazados[contador_estudiantes] = new Aplazados;
        aplazados[contador_estudiantes]->nombre = nombre;
        aplazados[contador_estudiantes]->apellido = apellido;
        aplazados[contador_estudiantes]->id = stoi(id);
        aplazados[contador_estudiantes]->seccion = seccion;
        aplazados[contador_estudiantes]->materias_aplazadas = materias_aplazadas[contador_estudiantes];
        contador_estudiantes++;
    }

    quickSort(materias_aplazadas, aplazados, 0, contador_estudiantes - 1);

    for (int i = 0; i < min(10, contador_estudiantes); i++) {
        cout << "#" << i + 1 << ". " << aplazados[i]->nombre << " " << aplazados[i]->apellido << endl
            << "ID: " << aplazados[i]->id << endl
            << "Seccion: " << aplazados[i]->seccion << endl
            << "Materias aplazadas: " << materias_aplazadas[i] << endl << endl;
    }

    for (int i = 0; i < contador_estudiantes; i++) {
        delete aplazados[i];
    }
    delete[] aplazados;
    delete[] materias_aplazadas;
}