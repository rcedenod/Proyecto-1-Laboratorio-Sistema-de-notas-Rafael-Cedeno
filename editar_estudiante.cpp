#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void editar_estudiante()
{
ifstream infile;
infile.open("datos_estudiantes(1).csv");
ofstream outfile;
outfile.open("Datos_Estudiantes_aux.csv");
    if (!infile||!outfile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, email_buscar, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        string nombre_nuevo, apellido_nuevo, email_nuevo, genero_nuevo;
        float matematicas_nuevo, sociales_nuevo, biologia_nuevo, fisica_nuevo, ef_nuevo, artes_nuevo;
        bool existe = false;

        cout << endl << "Ingrese el email del alumno: ";
        cin >> email_buscar;

        getline(infile, linea);
        outfile << linea << endl;

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
 
                if(email == email_buscar)
                {
                existe = true;
                
                cout<< endl << "Se ha encontrado el alumno" << endl
                    << "1. Modificar nombre" << endl
                    << "2. Modificar apellido" << endl
                    << "3. Modificar email" << endl
                    << "4. Modificar genero" << endl
                    << "5. Modificar notas de matematicas" << endl
                    << "6. Modificar notas de sociales" << endl
                    << "7. Modificar notas de biologia" << endl
                    << "8. Modificar notas de fisica" << endl
                    << "9. Modificar notas de educacion fisica" << endl
                    << "10. Modificar notas de arte" << endl
                    << "11. Modificar todo" << endl
                    << ": ";

                int opcion;
                bool repetido = false;
                cin >> opcion;

                switch(opcion)
                {
                    case 1:
                    cout << endl << "Nuevo nombre: ";
                    cin >> nombre_nuevo;
                    outfile << nombre_nuevo << ";" << apellido << ";" << email << ";" << genero << ";" <<  matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 2:
                    cout << endl << "Nuevo apellido: ";
                    cin >> apellido_nuevo;
                    outfile << nombre << ";" << apellido_nuevo << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 3: 
                    cout << endl << "Nuevo email: ";
                    cin >> email_nuevo;
                    if(frecuencia(email_nuevo) == 0)
                    {
                    outfile << nombre << ";" << apellido << ";" << email_nuevo << ";" << genero << ";" <<  matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    }else{
                        cout << "Un estudiante con este correo ya se encuentra en el sistema"<< endl;
                        repetido = true;
                        
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica << ";"
                            << educ_fisica << ";" << artes << endl; 
                    }
                    break;

                    case 4:
                    cout << endl << "Nuevo genero: ";
                    cin >> genero_nuevo;
                    outfile << nombre << ";" << apellido << ";" << genero_nuevo << ";" << genero_nuevo << ";" <<  matematicas << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 5:
                    cout << endl << "Nueva nota de matematicas: ";
                    cin >> matematicas_nuevo;
                    if(matematicas_nuevo > 20){matematicas_nuevo = 20;}
                    if (matematicas_nuevo < 0){matematicas_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas_nuevo << ";" << sociales << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 6:
                    cout << endl << "Nueva nota de sociales: ";
                    cin >> sociales_nuevo;
                    if(sociales_nuevo > 20){sociales_nuevo = 20;}
                    if(sociales_nuevo < 0){sociales_nuevo = 0;}
                        
                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales_nuevo << ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 7:
                    cout << endl << "Nueva nota de biologia: ";
                    cin >> biologia_nuevo;
                    if(biologia_nuevo > 20){biologia_nuevo = 20;}
                    if (biologia_nuevo < 0){biologia_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia_nuevo << ";" << fisica
                             << ";" << educ_fisica << ";" << artes << endl;
                    break;

                    case 8:
                    cout << endl << "Nueva nota de fisica: ";
                    cin >> fisica_nuevo;
                    if(fisica_nuevo > 20){fisica_nuevo = 20;}
                    if (fisica_nuevo < 0){fisica_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica_nuevo
                             << ";" << educ_fisica << ";" << artes << endl;
                        break;

                    case 9:
                    cout << endl << "Nueva nota de educacion fisica: ";
                    cin >> ef_nuevo;
                    if(ef_nuevo > 20){ef_nuevo = 20;}
                    if (ef_nuevo < 0){ef_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" <<genero <<";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica
                             << ";" << ef_nuevo << ";" << artes << endl;
                        break;

                    case 10:
                    cout << endl << "Nueva nota de artes: ";
                    cin >> artes_nuevo;
                    if(artes_nuevo > 20){artes_nuevo = 20;}
                    if (artes_nuevo < 0){artes_nuevo = 0;}

                    outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales<< ";" << biologia << ";" << fisica
                             << ";" << educ_fisica << ";" << artes_nuevo << endl;
                        break;

                    case 11:
                    cout << endl << "Nuevo nombre: ";
                    cin >> nombre_nuevo; 

                    cout << endl << "Nuevo apellido: ";
                    cin >> apellido_nuevo;

                    cout << endl << "Nuevo email: ";
                    cin >> email_nuevo;

                    cout << endl << "Nuevo genero: ";
                    cin >> genero_nuevo;

                    cout << endl << "Nueva nota en matematicas: ";
                    cin >> matematicas_nuevo;
                    if(matematicas_nuevo > 20){matematicas_nuevo = 20;}
                    if (matematicas_nuevo < 0){matematicas_nuevo = 0;}

                    cout << endl << "Nueva nota en sociales: "; 
                    cin >> sociales_nuevo;
                    if(sociales_nuevo > 20){ sociales_nuevo = 20;}
                    if(sociales_nuevo < 0){ sociales_nuevo = 0;}

                    cout << endl << "Nueva nota en biologia: ";
                    cin >> biologia_nuevo;
                    if(biologia_nuevo > 20){biologia_nuevo = 20;}
                    if (biologia_nuevo < 0){biologia_nuevo = 0;}

                    cout << endl << "Nueva nota en fisica: ";
                    cin >> fisica_nuevo;
                    if(fisica_nuevo > 20){fisica_nuevo = 20;}
                    if (fisica_nuevo < 0){fisica_nuevo = 0;}
                    cout << endl << "Nueva nota en educacion fisica: ";
                    cin >> ef_nuevo;
                    if(ef_nuevo > 20){ef_nuevo = 20;}
                    if (ef_nuevo < 0){ef_nuevo = 0;}

                    cout << endl << "Nueva nota en artes: ";
                    cin >> artes_nuevo;
                    if(artes_nuevo > 20){artes_nuevo = 20; }
                    if (artes_nuevo < 0){artes_nuevo = 0;}

                    outfile << nombre_nuevo << ";" << apellido_nuevo << ";" << email_nuevo << ";" << genero_nuevo << ";" << matematicas_nuevo << ";" << sociales_nuevo << ";" 
                            << biologia_nuevo << ";" << fisica_nuevo << ";" << ef_nuevo << ";" << artes_nuevo << endl;
                    break;
                }
                if(repetido == false)
                {
                cout << endl << "Se ha modificado el estudiante correctamente" << endl;
                }
            }
        else
        {
            outfile << nombre << ";" << apellido << ";" << email << ";" << genero << ";" << matematicas << ";" << sociales << ";" << biologia << ";" << fisica << ";"
                    << educ_fisica << ";" << artes << endl; 
        }
    }

    if(existe == false)
    {
        cout << "No se encontro el estudiante con el correo: " << email_buscar << endl;
    }
        infile.close();
        outfile.close();
        remove("datos_estudiantes(1).csv");
        rename("Datos_Estudiantes_aux.csv", "datos_estudiantes(1).csv"); 
    }
}