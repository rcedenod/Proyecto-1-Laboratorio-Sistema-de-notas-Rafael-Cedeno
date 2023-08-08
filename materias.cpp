#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void materias()
{
    ifstream infile;
    infile.open("datos_estudiantes(1).csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, nombre_buscar, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        int pasados_mate = 0, nopasados_mate = 0, pasados_sociales = 0, nopasados_sociales = 0, pasados_biologia = 0, nopasados_biologia = 0;
        int pasados_fisica = 0, nopasados_fisica = 0, pasados_ef = 0, nopasados_ef = 0, pasados_artes = 0, nopasados_artes = 0, total = 0;

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

            total++;
            
            if(stof(matematicas) >= 10)
            {
                pasados_mate++;
            }else{
                nopasados_mate++;
            }

            if(stof(sociales) >= 10)
            {
                pasados_sociales++;
            }else{
                nopasados_sociales++;
            }

            if(stof(biologia) >= 10)
            {
                pasados_biologia++;
            }else{
                nopasados_biologia++;
            }
                    
            if(stof(fisica) >= 10)
            {
                pasados_fisica++;
            }else{
                nopasados_fisica++;
            }
                    
            if(stof(educ_fisica) >= 10)
            {
                pasados_ef++;
            }else{
                nopasados_ef++;
            }
                    
            if(stof(artes) >= 10)
            {
                pasados_artes++;
            }else{
                nopasados_artes++;
            }
        }
                cout << endl << "-- Matematicas --" << endl
                     << "Estudiantes pasados: " << pasados_mate << endl
                     << "Estudiantes aplazados: " << nopasados_mate << endl
                     << endl ;

                cout << "-- Sociales --" << endl
                     << "Estudiantes pasados: " << pasados_sociales << endl
                     << "Estudiantes aplazados: " << nopasados_sociales << endl
                     << endl ;

                cout << "-- Biologia --" << endl
                     << "Estudiantes pasados: " << pasados_biologia << endl
                     << "Estudiantes aplazados: " << nopasados_biologia << endl
                     << endl ;
        
                cout << "-- Fisica --" << endl
                     << "Estudiantes pasados: " << pasados_fisica << endl
                     << "Estudiantes aplazados: " << nopasados_fisica << endl
                     << endl ;

                cout << "-- Educacion fisica --" << endl
                     << "Estudiantes pasados: " << pasados_ef << endl
                     << "Estudiantes aplazados: " << nopasados_ef << endl
                     << endl ;

                cout << "-- Artes --" << endl
                     << "Estudiantes pasados: " << pasados_artes << endl
                     << "Estudiantes aplazados: " << nopasados_artes << endl
                     << endl ;
                
                cout << "Total de estudiantes :" << total << endl;
    }
    infile.close();
}