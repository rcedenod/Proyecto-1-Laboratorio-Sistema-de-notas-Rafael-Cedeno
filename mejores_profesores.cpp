#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void mejores_profesores(){
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

    cout << "----- Mejores profesores ------ " << endl;
    cout << "1. Por seccion" << endl;
    cout << "2. Por materia" << endl;
    cout << ": " << endl;
    int opcion;
    cin >> opcion;

    if(opcion == 1){
    float medidor = 0;
    int contador1 = 0, contador2 = 0, contador3 = 0, contador4 = 0, contador5 = 0, contador6 = 0;
    string id_materia;

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

        if(seccion == secciones[0]){
            contador1++;
        }
        if(seccion == secciones[1]){
            contador2++;
        } 
        if(seccion == secciones[2]){
            contador3++;
        } 
        if(seccion == secciones[3]){
            contador4++;
        } 
        if(seccion == secciones[4]){
            contador5++;
        } 
        if(seccion == secciones[5]){
            contador6++;
        }     
    }

    Mejores A[contador1], B[contador2], C[contador3], D[contador4], E[contador5], F[contador6];
    int c1 = contador1, c2 = contador2, c3 = contador3, c4 = contador4, c5 = contador5, c6 = contador6;
    contador1 = 0;
    contador2 = 0;
    contador3 = 0;
    contador4 = 0;
    contador5 = 0;
    contador6 = 0;
    int indice = 0;

    profesores.clear();
    profesores.seekg(0, ios::beg);

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

        if (stoi(id_materia) == 1001) {
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_mate[i] * 100) / contador_seccion[i];
                }
            }
        if(indice == 0){
            A[contador1].nombre = nombre;
            A[contador1].apellido = apellido;
            A[contador1].rendimiento = medidor;
            A[contador1].materia = "Matematica";
            A[contador1].id = stoi(id);
            A[contador1].seccion = secciones[indice];
            contador1++;  
        }
        if(indice == 1){
            B[contador2].nombre = nombre;
            B[contador2].apellido = apellido;
            B[contador2].rendimiento = medidor;
            B[contador2].materia = "Sociales";
            B[contador2].id = stoi(id);
            B[contador2].seccion = secciones[indice];
            contador2++;   
        }
        if(indice == 2){
            C[contador3].nombre = nombre;
            C[contador3].apellido = apellido;
            C[contador3].rendimiento = medidor;
            C[contador3].materia = "Biologia";
            C[contador3].id = stoi(id);
            C[contador3].seccion = secciones[indice];
            contador3++;
        }
        if(indice == 3){
            D[contador4].nombre = nombre;
            D[contador4].apellido = apellido;
            D[contador4].rendimiento = medidor;
            D[contador4].materia = "Educacion fisica";
            D[contador4].id = stoi(id);
            D[contador4].seccion = secciones[indice];
            contador4++;    
        }
        if(indice == 4){
            E[contador5].nombre = nombre;
            E[contador5].apellido = apellido;
            E[contador5].rendimiento = medidor;
            E[contador5].materia = "Artes";
            E[contador5].id = stoi(id);
            E[contador5].seccion = secciones[indice];
            contador5++; 
        }
        if(indice == 5){
            F[contador6].nombre = nombre;
            F[contador6].apellido = apellido;
            F[contador6].rendimiento = medidor;
            F[contador6].materia = "Artes";
            F[contador6].id = stoi(id);
            F[contador6].seccion = secciones[indice];
            contador6++;    
        }
    }

    if (stoi(id_materia) == 1002) {
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_soc[i] * 100) / contador_seccion[i];
                }
            }
        if(indice == 0){
            A[contador1].nombre = nombre;
            A[contador1].apellido = apellido;
            A[contador1].rendimiento = medidor;
            A[contador1].materia = "Matematica";
            A[contador1].id = stoi(id);
            A[contador1].seccion = secciones[indice];
            contador1++;  
        }
        if(indice == 1){
            B[contador2].nombre = nombre;
            B[contador2].apellido = apellido;
            B[contador2].rendimiento = medidor;
            B[contador2].materia = "Sociales";
            B[contador2].id = stoi(id);
            B[contador2].seccion = secciones[indice];
            contador2++;   
        }
        if(indice == 2){
            C[contador3].nombre = nombre;
            C[contador3].apellido = apellido;
            C[contador3].rendimiento = medidor;
            C[contador3].materia = "Biologia";
            C[contador3].id = stoi(id);
            C[contador3].seccion = secciones[indice];
            contador3++;
        }
        if(indice == 3){
            D[contador4].nombre = nombre;
            D[contador4].apellido = apellido;
            D[contador4].rendimiento = medidor;
            D[contador4].materia = "Educacion fisica";
            D[contador4].id = stoi(id);
            D[contador4].seccion = secciones[indice];
            contador4++;    
        }
        if(indice == 4){
            E[contador5].nombre = nombre;
            E[contador5].apellido = apellido;
            E[contador5].rendimiento = medidor;
            E[contador5].materia = "Artes";
            E[contador5].id = stoi(id);
            E[contador5].seccion = secciones[indice];
            contador5++; 
        }
        if(indice == 5){
            F[contador6].nombre = nombre;
            F[contador6].apellido = apellido;
            F[contador6].rendimiento = medidor;
            F[contador6].materia = "Artes";
            F[contador6].id = stoi(id);
            F[contador6].seccion = secciones[indice];
            contador6++;    
        }
    }

    if (stoi(id_materia) == 1003) {
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_bio[i] * 100) / contador_seccion[i];
                }
            }
        if(indice == 0){
            A[contador1].nombre = nombre;
            A[contador1].apellido = apellido;
            A[contador1].rendimiento = medidor;
            A[contador1].materia = "Matematica";
            A[contador1].id = stoi(id);
            A[contador1].seccion = secciones[indice];
            contador1++;  
        }
        if(indice == 1){
            B[contador2].nombre = nombre;
            B[contador2].apellido = apellido;
            B[contador2].rendimiento = medidor;
            B[contador2].materia = "Sociales";
            B[contador2].id = stoi(id);
            B[contador2].seccion = secciones[indice];
            contador2++;   
        }
        if(indice == 2){
            C[contador3].nombre = nombre;
            C[contador3].apellido = apellido;
            C[contador3].rendimiento = medidor;
            C[contador3].materia = "Biologia";
            C[contador3].id = stoi(id);
            C[contador3].seccion = secciones[indice];
            contador3++;
        }
        if(indice == 3){
            D[contador4].nombre = nombre;
            D[contador4].apellido = apellido;
            D[contador4].rendimiento = medidor;
            D[contador4].materia = "Educacion fisica";
            D[contador4].id = stoi(id);
            D[contador4].seccion = secciones[indice];
            contador4++;    
        }
        if(indice == 4){
            E[contador5].nombre = nombre;
            E[contador5].apellido = apellido;
            E[contador5].rendimiento = medidor;
            E[contador5].materia = "Artes";
            E[contador5].id = stoi(id);
            E[contador5].seccion = secciones[indice];
            contador5++; 
        }
        if(indice == 5){
            F[contador6].nombre = nombre;
            F[contador6].apellido = apellido;
            F[contador6].rendimiento = medidor;
            F[contador6].materia = "Artes";
            F[contador6].id = stoi(id);
            F[contador6].seccion = secciones[indice];
            contador6++;    
        }
    }

    if (stoi(id_materia) == 1004) {
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_ef[i] * 100) / contador_seccion[i];
                }
            }
        if(indice == 0){
            A[contador1].nombre = nombre;
            A[contador1].apellido = apellido;
            A[contador1].rendimiento = medidor;
            A[contador1].materia = "Matematica";
            A[contador1].id = stoi(id);
            A[contador1].seccion = secciones[indice];
            contador1++;  
        }
        if(indice == 1){
            B[contador2].nombre = nombre;
            B[contador2].apellido = apellido;
            B[contador2].rendimiento = medidor;
            B[contador2].materia = "Sociales";
            B[contador2].id = stoi(id);
            B[contador2].seccion = secciones[indice];
            contador2++;   
        }
        if(indice == 2){
            C[contador3].nombre = nombre;
            C[contador3].apellido = apellido;
            C[contador3].rendimiento = medidor;
            C[contador3].materia = "Biologia";
            C[contador3].id = stoi(id);
            C[contador3].seccion = secciones[indice];
            contador3++;
        }
        if(indice == 3){
            D[contador4].nombre = nombre;
            D[contador4].apellido = apellido;
            D[contador4].rendimiento = medidor;
            D[contador4].materia = "Educacion fisica";
            D[contador4].id = stoi(id);
            D[contador4].seccion = secciones[indice];
            contador4++;    
        }
        if(indice == 4){
            E[contador5].nombre = nombre;
            E[contador5].apellido = apellido;
            E[contador5].rendimiento = medidor;
            E[contador5].materia = "Artes";
            E[contador5].id = stoi(id);
            E[contador5].seccion = secciones[indice];
            contador5++; 
        }
        if(indice == 5){
            F[contador6].nombre = nombre;
            F[contador6].apellido = apellido;
            F[contador6].rendimiento = medidor;
            F[contador6].materia = "Artes";
            F[contador6].id = stoi(id);
            F[contador6].seccion = secciones[indice];
            contador6++;    
        }
    }

    if (stoi(id_materia) == 1005) {
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_art[i] * 100) / contador_seccion[i];
                }
            }
        if(indice == 0){
            A[contador1].nombre = nombre;
            A[contador1].apellido = apellido;
            A[contador1].rendimiento = medidor;
            A[contador1].materia = "Matematica";
            A[contador1].id = stoi(id);
            A[contador1].seccion = secciones[indice];
            contador1++;  
        }
        if(indice == 1){
            B[contador2].nombre = nombre;
            B[contador2].apellido = apellido;
            B[contador2].rendimiento = medidor;
            B[contador2].materia = "Sociales";
            B[contador2].id = stoi(id);
            B[contador2].seccion = secciones[indice];
            contador2++;   
        }
        if(indice == 2){
            C[contador3].nombre = nombre;
            C[contador3].apellido = apellido;
            C[contador3].rendimiento = medidor;
            C[contador3].materia = "Biologia";
            C[contador3].id = stoi(id);
            C[contador3].seccion = secciones[indice];
            contador3++;
        }
        if(indice == 3){
            D[contador4].nombre = nombre;
            D[contador4].apellido = apellido;
            D[contador4].rendimiento = medidor;
            D[contador4].materia = "Educacion fisica";
            D[contador4].id = stoi(id);
            D[contador4].seccion = secciones[indice];
            contador4++;    
        }
        if(indice == 4){
            E[contador5].nombre = nombre;
            E[contador5].apellido = apellido;
            E[contador5].rendimiento = medidor;
            E[contador5].materia = "Artes";
            E[contador5].id = stoi(id);
            E[contador5].seccion = secciones[indice];
            contador5++; 
        }
        if(indice == 5){
            F[contador6].nombre = nombre;
            F[contador6].apellido = apellido;
            F[contador6].rendimiento = medidor;
            F[contador6].materia = "Artes";
            F[contador6].id = stoi(id);
            F[contador6].seccion = secciones[indice];
            contador6++;    
            }
        }
    }
        profesores.close();

        cout << "-- Mejores profesores por seccion --" << endl //Los imprimo todos porque son muy pocos
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
        quicksort_mejores_prof(A, 0, c1 - 1);
        for(int i=0; i < c1; i++){
            cout << "#" << i+1 << ". " << A[i].nombre << " " << A[i].apellido << endl
                         << "ID: " << A[i].id << endl
                         << "Seccion: " <<  A[i].seccion << endl
                         << "Materia: " << A[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << A[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 2:
        quicksort_mejores_prof(B, 0, c2 - 1);
        for(int i=0; i < c2; i++){
            cout << "#" << i+1 << ". " << B[i].nombre << " " << B[i].apellido << endl
                         << "ID: " << B[i].id << endl
                         << "Seccion: " <<  B[i].seccion << endl
                         << "Materia: " << B[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << B[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 3:
        quicksort_mejores_prof(C, 0, c3 - 1);
        for(int i=0; i < c3; i++){
            cout << "#" << i+1 << ". " << C[i].nombre << " " << C[i].apellido << endl
                         << "ID: " << C[i].id << endl
                         << "Seccion: " <<  C[i].seccion << endl
                         << "Materia: " << C[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << C[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 4:
        quicksort_mejores_prof(D, 0, c4 - 1);
        for(int i=0; i < c4; i++){
            cout << "#" << i+1 << ". " << D[i].nombre << " " << D[i].apellido << endl
                         << "ID: " << D[i].id << endl
                         << "Seccion: " <<  D[i].seccion << endl
                         << "Materia: " << D[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << D[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 5:
        quicksort_mejores_prof(E, 0, c5 - 1);
        for(int i=0; i < c5; i++){
            cout << "#" << i+1 << ". " << E[i].nombre << " " << E[i].apellido << endl
                         << "ID: " << E[i].id << endl
                         << "Seccion: " <<  E[i].seccion << endl
                         << "Materia: " << E[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << E[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 6:
        quicksort_mejores_prof(F, 0, c6 - 1);
        for(int i=0; i < c6; i++){
            cout << "#" << i+1 << ". " << F[i].nombre << " " << F[i].apellido << endl
                         << "ID: " << F[i].id << endl
                         << "Seccion: " <<  F[i].seccion << endl
                         << "Materia: " << F[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << F[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        default:
        cout << "Opcion invalida" << endl;
        break;
    }
}

    if(opcion == 2){
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

    float medidor = 0;
    int contador_mate = 0, contador_soc = 0, contador_bio = 0, contador_ef = 0, contador_art;
    string id_materia;

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

        if(stoi(id_materia) == 1001){
            contador_mate++;
        }
        if(stoi(id_materia) == 1002){
            contador_soc++;
        } 
        if(stoi(id_materia) == 1003){
            contador_bio++;
        } 
        if(stoi(id_materia) == 1004){
            contador_ef++;
        } 
        if(stoi(id_materia) == 1005){
            contador_art++;
        }  
    }

    profesores.clear();
    profesores.seekg(0, ios::beg);

    Mejores mate[contador_mate], soc[contador_soc], bio[contador_bio], edf[contador_ef], art[contador_art];
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
    int indice = 0;

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

        if(stoi(id_materia) == 1001){
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_mate[i] * 100) / contador_seccion[i];
                }
            }
            mate[c1].nombre = nombre;
            mate[c1].apellido = apellido;
            mate[c1].seccion = seccion;
            mate[c1].rendimiento = medidor;
            mate[c1].id = stoi(id);
            mate[c1].materia = "Matematicas";
            c1++;
    }

    if(stoi(id_materia) == 1002){
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_soc[i] * 100) / contador_seccion[i];
                }
            }
            soc[c2].nombre = nombre;
            soc[c2].apellido = apellido;
            soc[c2].seccion = seccion;
            soc[c2].rendimiento = medidor;
            soc[c2].id = stoi(id);
            soc[c2].materia = "Sociales";
            c2++;
    }

    if(stoi(id_materia) == 1003){
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_bio[i] * 100) / contador_seccion[i];
                }
            }
            bio[c3].nombre = nombre;
            bio[c3].apellido = apellido;
            bio[c3].seccion = seccion;
            bio[c3].rendimiento = medidor;
            bio[c3].id = stoi(id);
            bio[c3].materia = "Biologia";
            c3++;
    }

    if(stoi(id_materia) == 1004){
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_ef[i] * 100) / contador_seccion[i];
                }
            }
            edf[c4].nombre = nombre;
            edf[c4].apellido = apellido;
            edf[c4].seccion = seccion;
            edf[c4].rendimiento = medidor;
            edf[c4].id = stoi(id);
            edf[c4].materia = "Biologia";
            c4++;
    }

    if(stoi(id_materia) == 1005){
            for (int i = 0; i < 6; i++) {
                if (seccion == secciones[i]) {
                    indice = i;
                    medidor = (pasados_art[i] * 100) / contador_seccion[i];
                }
            }
            art[c5].nombre = nombre;
            art[c5].apellido = apellido;
            art[c5].seccion = seccion;
            art[c5].rendimiento = medidor;
            art[c5].id = stoi(id);
            art[c5].materia = "Biologia";
        }
    }
    profesores.close();

    cout << "-- 3 Mejores profesores por materia --" << endl
        << "1. Matematica" << endl
        << "2. Sociales" << endl
        << "3. Biologia" << endl
        << "4. Educacion fisica" << endl
        << "5. Artes" << endl
        << " : ";

        int opcion;
    cin >> opcion;

    switch(opcion){
        case 1:
        quicksort_mejores_prof(mate, 0, c1 - 1);
        for(int i=0; i < 3; i++){
            cout << "#" << i+1 << ". " << mate[i].nombre << " " << mate[i].apellido << endl
                         << "ID: " << mate[i].id << endl
                         << "Seccion: " <<  mate[i].seccion << endl
                         << "Materia: " << mate[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << mate[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 2:
        quicksort_mejores_prof(soc, 0, c2 - 1);
        for(int i=0; i < 3; i++){
            cout << "#" << i+1 << ". " << soc[i].nombre << " " << soc[i].apellido << endl
                         << "ID: " << soc[i].id << endl
                         << "Seccion: " <<  soc[i].seccion << endl
                         << "Materia: " << soc[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << soc[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 3:
        quicksort_mejores_prof(bio, 0, c3 - 1);
        for(int i=0; i < 3; i++){
            cout << "#" << i+1 << ". " << bio[i].nombre << " " << bio[i].apellido << endl
                         << "ID: " << bio[i].id << endl
                         << "Seccion: " <<  bio[i].seccion << endl
                         << "Materia: " << bio[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << bio[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 4:
        quicksort_mejores_prof(edf, 0, c4 - 1);
        for(int i=0; i < 3; i++){
            cout << "#" << i+1 << ". " << edf[i].nombre << " " << edf[i].apellido << endl
                         << "ID: " << edf[i].id << endl
                         << "Seccion: " <<  edf[i].seccion << endl
                         << "Materia: " << edf[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << edf[i].rendimiento << " %" << endl
                         << endl;
        }
        break;

        case 5:
        quicksort_mejores_prof(art, 0, c5 - 1);
        for(int i=0; i < 3; i++){
            cout << "#" << i+1 << ". " << art[i].nombre << " " << art[i].apellido << endl
                         << "ID: " << art[i].id << endl
                         << "Seccion: " <<  art[i].seccion << endl
                         << "Materia: " << art[i].materia << endl
                         << "Rendimiento (Porcentaje de alumnos pasados): " << art[i].rendimiento << " %" << endl
                         << endl;
        }
        break;
    }
}

    if(!(opcion == 1 || opcion ==2)){
        cout << "Opcion invalida" << endl;
        exit(1);
    }
}