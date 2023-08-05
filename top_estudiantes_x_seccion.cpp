#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void top_estudiantes_x_seccion() {
    ifstream infile;
    infile.open("datos_estudiantes(2).csv");
    if(!infile){
        cout << "Error" << endl;
        exit(1);
    }
    
    string linea, id, nombre, apellido, genero, email, seccion, matematicas, sociales, biologia, ef, artes;
    string secciones[7] = {"A", "B", "C", "D", "E", "F"};
    int contador_a = 0, contador_b = 0, contador_c = 0, contador_d = 0, contador_e = 0, contador_f = 0;

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
            contador_a++;
        }
        if(seccion == secciones[1]){
            contador_b++;
        } 
        if(seccion == secciones[2]){
            contador_c++;
        } 
        if(seccion == secciones[3]){
            contador_d++;
        } 
        if(seccion == secciones[4]){
            contador_e++;
        } 
        if(seccion == secciones[5]){
            contador_f++;
        }  
    }

    infile.clear();
    infile.seekg(0, ios::beg);

    Secciones A[contador_a], B[contador_b], C[contador_c], D[contador_d], E[contador_e], F[contador_f];
    int contador1 = 0, contador2 = 0, contador3 = 0, contador4 = 0,contador5 = 0, contador6 = 0;

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
            A[contador1].id = stoi(id);
            A[contador1].nombre = nombre;
            A[contador1].apellido = apellido;
            A[contador1].seccion = seccion;
            A[contador1].matematica = stof(matematicas);
            A[contador1].sociales = stof(sociales);
            A[contador1].biologia = stof(biologia);
            A[contador1].ef = stof(ef);
            A[contador1].artes = stof(artes);
            A[contador1].promedio = (stof(matematicas)+stof(sociales)+stof(biologia)+stof(ef)+stof(artes))/5;
            contador1++;
        }
        if(seccion == secciones[1]){
            B[contador2].id = stoi(id);
            B[contador2].nombre = nombre;
            B[contador2].apellido = apellido;
            B[contador2].seccion = seccion;
            B[contador2].matematica = stof(matematicas);
            B[contador2].sociales = stof(sociales);
            B[contador2].biologia = stof(biologia);
            B[contador2].ef = stof(ef);
            B[contador2].artes = stof(artes);
            B[contador2].promedio = (stof(matematicas)+stof(sociales)+stof(biologia)+stof(ef)+stof(artes))/5;
            contador2++;
        } 
        if(seccion == secciones[2]){
            C[contador3].id = stoi(id);
            C[contador3].nombre = nombre;
            C[contador3].apellido = apellido;
            C[contador3].seccion = seccion;
            C[contador3].matematica = stof(matematicas);
            C[contador3].sociales = stof(sociales);
            C[contador3].biologia = stof(biologia);
            C[contador3].ef = stof(ef);
            C[contador3].artes = stof(artes);
            C[contador3].promedio = (stof(matematicas)+stof(sociales)+stof(biologia)+stof(ef)+stof(artes))/5;
            contador3++;
        } 
        if(seccion == secciones[3]){
            D[contador4].id = stoi(id);
            D[contador4].nombre = nombre;
            D[contador4].apellido = apellido;
            D[contador4].seccion = seccion;
            D[contador4].matematica = stof(matematicas);
            D[contador4].sociales = stof(sociales);
            D[contador4].biologia = stof(biologia);
            D[contador4].ef = stof(ef);
            D[contador4].artes = stof(artes);
            D[contador4].promedio = (stof(matematicas)+stof(sociales)+stof(biologia)+stof(ef)+stof(artes))/5;
            contador4++;
        } 
        if(seccion == secciones[4]){
            E[contador5].id = stoi(id);
            E[contador5].nombre = nombre;
            E[contador5].apellido = apellido;
            E[contador5].seccion = seccion;
            E[contador5].matematica = stof(matematicas);
            E[contador5].sociales = stof(sociales);
            E[contador5].biologia = stof(biologia);
            E[contador5].ef = stof(ef);
            E[contador5].artes = stof(artes);
            E[contador5].promedio = (stof(matematicas)+stof(sociales)+stof(biologia)+stof(ef)+stof(artes))/5;
            contador5++;
        } 
        if(seccion == secciones[5]){
            F[contador6].id = stoi(id);
            F[contador6].nombre = nombre;
            F[contador6].apellido = apellido;
            F[contador6].seccion = seccion;
            F[contador6].matematica = stof(matematicas);
            F[contador6].sociales = stof(sociales);
            F[contador6].biologia = stof(biologia);
            F[contador6].ef = stof(ef);
            F[contador6].artes = stof(artes);
            F[contador6].promedio = (stof(matematicas)+stof(sociales)+stof(biologia)+stof(ef)+stof(artes))/5;
            contador6++;
        }  
     }

    cout << "-- 10 mejores estudiantes --" << endl
        << "1. Seccion A" << endl
        << "2. Seccion B" << endl
        << "3. Seccion C" << endl
        << "4. Seccion D" << endl
        << "5. Seccion E" << endl
        << "6. Seccion F" << endl
        << " : ";
    
    int opcion;
    cin >> opcion;

    switch(opcion){
        case 1:
        quicksort_secciones(A, 0, contador_a - 1);
        for(int i=0; i < 10; i++){
            cout << "#" << i+1 << ". " << A[i].nombre << " " << A[i].apellido << endl
                         << "ID: " << A[i].id << endl
                         << "Seccion: " <<  A[i].seccion << endl
                         << "Nota en matematicas: " << A[i].matematica << endl
                         << "Nota en sociales: " << A[i].sociales << endl
                         << "Nota en biologia: " << A[i].biologia << endl
                         << "Nota en educacion fisica: " << A[i].ef << endl
                         << "Nota en artes: " << A[i].artes<< endl
                         << "Promedio total: " << A[i].promedio << endl << endl;
        }
        break;

        case 2:
        quicksort_secciones(B, 0, contador_b - 1);
        for(int i=0; i < 10; i++){
            cout << "#" << i+1 << ". " << B[i].nombre << " " << B[i].apellido << endl
                         << "ID: " << B[i].id << endl
                         << "Seccion: " <<  B[i].seccion << endl
                         << "Nota en matematicas: " << B[i].matematica << endl
                         << "Nota en sociales: " << B[i].sociales << endl
                         << "Nota en biologia: " << B[i].biologia << endl
                         << "Nota en educacion fisica: " << B[i].ef << endl
                         << "Nota en artes: " << B[i].artes<< endl
                         << "Promedio total: " << B[i].promedio << endl << endl;
        }
        break;

        case 3:
        quicksort_secciones(C, 0, contador_c - 1);
        for(int i=0; i < 10; i++){
            cout << "#" << i+1 << ". " << C[i].nombre << " " << C[i].apellido << endl
                         << "ID: " << C[i].id << endl
                         << "Seccion: " <<  C[i].seccion << endl
                         << "Nota en matematicas: " << C[i].matematica << endl
                         << "Nota en sociales: " << C[i].sociales << endl
                         << "Nota en biologia: " << C[i].biologia << endl
                         << "Nota en educacion fisica: " << C[i].ef << endl
                         << "Nota en artes: " << C[i].artes<< endl
                         << "Promedio total: " << C[i].promedio << endl << endl;
        }
        break;

        case 4:
        quicksort_secciones(D, 0, contador_d - 1);
        for(int i=0; i < 10; i++){
            cout << "#" << i+1 << ". " << D[i].nombre << " " << D[i].apellido << endl
                         << "ID: " << D[i].id << endl
                         << "Seccion: " <<  D[i].seccion << endl
                         << "Nota en matematicas: " << D[i].matematica << endl
                         << "Nota en sociales: " << D[i].sociales << endl
                         << "Nota en biologia: " << D[i].biologia << endl
                         << "Nota en educacion fisica: " << D[i].ef << endl
                         << "Nota en artes: " << D[i].artes<< endl
                         << "Promedio total: " << D[i].promedio << endl << endl;
        }
        break;

        case 5:
        quicksort_secciones(E, 0, contador_e - 1);
        for(int i=0; i < 10; i++){
            cout << "#" << i+1 << ". " << E[i].nombre << " " << E[i].apellido << endl
                         << "ID: " << E[i].id << endl
                         << "Seccion: " <<  E[i].seccion << endl
                         << "Nota en matematicas: " << E[i].matematica << endl
                         << "Nota en sociales: " << E[i].sociales << endl
                         << "Nota en biologia: " << E[i].biologia << endl
                         << "Nota en educacion fisica: " << E[i].ef << endl
                         << "Nota en artes: " << E[i].artes<< endl
                         << "Promedio total: " << E[i].promedio << endl << endl;
        }
        break;

        case 6:
        quicksort_secciones(F, 0, contador_f - 1);
        for(int i=0; i < 10; i++){
            cout << "#" << i+1 << ". " << F[i].nombre << " " << F[i].apellido << endl
                         << "ID: " << F[i].id << endl
                         << "Seccion: " <<  F[i].seccion << endl
                         << "Nota en matematicas: " << F[i].matematica << endl
                         << "Nota en sociales: " << F[i].sociales << endl
                         << "Nota en biologia: " << F[i].biologia << endl
                         << "Nota en educacion fisica: " << F[i].ef << endl
                         << "Nota en artes: " << F[i].artes<< endl
                         << "Promedio total: " << F[i].promedio << endl << endl;
        }
        break;

        default:
        cout << "Opcion invalida" << endl;
        break;
    }

    infile.close();
}
