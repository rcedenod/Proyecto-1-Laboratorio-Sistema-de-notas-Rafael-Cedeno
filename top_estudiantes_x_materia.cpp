#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void top_estudiantes_x_materia()
{
    ifstream infile;
    infile.open("datos_estudiantes(1).csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        int numestudiantes = 0;

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

            estudiante[numestudiantes].nombre = nombre;
            estudiante[numestudiantes].apellido = apellido;
            estudiante[numestudiantes].email = email;
            estudiante[numestudiantes].genero = genero;
            estudiante[numestudiantes].notas_matematica = stof(matematicas);
            estudiante[numestudiantes].notas_sociales = stof(sociales);
            estudiante[numestudiantes].notas_biologia = stof(biologia);
            estudiante[numestudiantes].notas_fisica = stof(fisica);
            estudiante[numestudiantes].notas_educ_fisica = stof(educ_fisica);
            estudiante[numestudiantes].notas_artes = stof(artes);
            numestudiantes++;
        }
    
            cout << "-- 10 mejores estudiantes --" << endl
                 << "1. Matematicas" << endl
                 << "2. Sociales" << endl
                 << "3. Biologia" << endl
                 << "4. Fisica" << endl
                 << "5. Educacion fisica" << endl
                 << "6. Artes" << endl
                 << " : ";

            int opcion;
            cin >> opcion;
            switch(opcion)
            {
                case 1:
                quicksort_mate(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en mate: " << endl << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                        
                }
                break;

                case 2:
                quicksort_soc(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en sociales: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 3:
                quicksort_bio(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en biologia: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 4:
                quicksort_fis(estudiante, 0, numestudiantes - 1);
                cout << endl <<"10 Mejores estudiantes en fisica: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 5:
                quicksort_ef(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en educacion fisica: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en artes: " << estudiante[i].notas_artes<< endl
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                case 6:
                quicksort_art(estudiante, 0, numestudiantes - 1);
                cout << endl << "10 Mejores estudiantes en artes: " << endl;
                for (int i = 0; i < 10; i++)
                {
                float promedio = (estudiante[i].notas_biologia + estudiante[i].notas_matematica + estudiante[i].notas_sociales + estudiante[i].notas_fisica + estudiante[i].notas_educ_fisica + estudiante[i].notas_artes) / 6;
                    cout << "#" << i+1 << ". " << estudiante[i].nombre << " " << estudiante[i].apellido << endl
                         << "Email: " << estudiante[i].email << endl
                         << "Genero: " <<  estudiante[i].genero << endl
                         << "Nota en artes: " << estudiante[i].notas_artes << endl
                         << "Nota en matematicas: " << estudiante[i].notas_matematica << endl
                         << "Nota en sociales: " << estudiante[i].notas_sociales << endl
                         << "Nota en biologia: " << estudiante[i].notas_biologia << endl
                         << "Nota en fisica: " << estudiante[i].notas_fisica << endl
                         << "Nota en educacion fisica: " << estudiante[i].notas_educ_fisica << endl 
                         << "Promedio total: " << promedio << endl << endl;
                }
                break;

                default:
                    cout << endl << "Opcion invalida";
                break;
            }
    }
    infile.close();
}