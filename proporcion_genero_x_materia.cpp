#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void proporcion_genero_x_materia()
{
    float apmat_masc = 0.0, apmat_fem = 0.0, apmat_ot = 0.0, repmat_masc = 0.0, repmat_fem = 0.0, repmat_ot = 0.0;
    float apsoc_masc = 0.0, apsoc_fem = 0.0, apsoc_ot = 0.0, repsoc_masc = 0.0, repsoc_fem = 0.0, repsoc_ot = 0.0;
    float apbio_masc = 0.0, apbio_fem = 0.0, apbio_ot = 0.0, repbio_masc = 0.0, repbio_fem = 0.0, repbio_ot = 0.0;
    float apfis_masc = 0.0, apfis_fem = 0.0, apfis_ot = 0.0, repfis_masc = 0.0, repfis_fem = 0.0, repfis_ot = 0.0;
    float apef_masc = 0.0, apef_fem = 0.0, apef_ot = 0.0, repef_masc = 0.0, repef_fem = 0.0, repef_ot = 0.0;
    float apart_masc = 0.0, apart_fem = 0.0, apart_ot = 0.0, repart_masc = 0.0, repart_fem = 0.0, repart_ot = 0.0;

    float prompas_mat_masc = 0.0, prompas_mat_fem = 0.0, prompas_mat_ot = 0.0;
    float promrep_mat_masc = 0.0, promrep_mat_fem = 0.0, promrep_mat_ot = 0.0; 
    float promrep_soc_masc = 0.0, promrep_soc_fem = 0.0, promrep_soc_ot = 0.0;
    float prompas_soc_masc = 0.0, prompas_soc_fem = 0.0, prompas_soc_ot = 0.0; 
    float prompas_bio_masc = 0.0, prompas_bio_fem = 0.0, prompas_bio_ot = 0.0;
    float promrep_bio_masc = 0.0, promrep_bio_fem = 0.0, promrep_bio_ot = 0.0; 
    float prompas_fis_masc = 0.0, prompas_fis_fem = 0.0, prompas_fis_ot = 0.0; 
    float promrep_fis_masc = 0.0, promrep_fis_fem = 0.0, promrep_fis_ot = 0.0;
    float prompas_ef_masc = 0.0, prompas_ef_fem = 0.0, prompas_ef_ot = 0.0; 
    float promrep_ef_masc = 0.0, promrep_ef_fem = 0.0, promrep_ef_ot = 0.0;
    float prompas_art_masc = 0.0, prompas_art_fem = 0.0, prompas_art_ot = 0.0;
    float promrep_art_masc = 0.0, promrep_art_fem = 0.0, promrep_art_ot = 0.0;

    float masc = 0.0, fem = 0.0, otro = 0.0;

    fflush(stdin);
    
    ifstream infile;
    infile.open("datos_estudiantes(1).csv");
    if (!infile)
    {
        cout << "Error al abrir el archivo" << endl;
    }
    else
    {
        string linea, nombre, apellido, email, genero, matematicas, sociales, biologia, fisica, educ_fisica, artes;
        string M = "Male";
        string F = "Female";

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
            
                if(genero == M)
                {
                    masc++;

                    if(stof(matematicas) >= 10) {apmat_masc++;} else{repmat_masc++;}
                    if(stof(sociales) >= 10) {apsoc_masc++;} else{repsoc_masc++;}
                    if(stof(biologia) >= 10) {apbio_masc++;} else{repbio_masc++;}
                    if(stof(fisica) >= 10) {apfis_masc++;} else{repfis_masc++;}
                    if(stof(educ_fisica) >= 10) {apef_masc++;} else{repef_masc++;}
                    if(stof(artes) >= 10) {apart_masc++;} else{repart_masc++;}   
                }

                if(genero == F)
                {
                    fem++;

                    if(stof(matematicas) >= 10) {apmat_fem++;} else{repmat_fem++;}
                    if(stof(sociales) >= 10) {apsoc_fem++;} else{repsoc_fem++;}
                    if(stof(biologia) >= 10) {apbio_fem++;} else{repbio_fem++;}
                    if(stof(fisica) >= 10) {apfis_fem++;} else{repfis_fem++;}
                    if(stof(educ_fisica) >= 10) {apef_fem++;} else{repef_fem++;}
                    if(stof(artes) >= 10) {apart_fem++;} else{repart_fem++;}   
                }

                if(!(genero == M) && !(genero == F))
                {
                    otro++;

                    if(stof(matematicas) >= 10) {apmat_ot++;} else{repmat_ot++;}
                    if(stof(sociales) >= 10) {apsoc_ot++;} else{repsoc_ot++;}
                    if(stof(biologia) >= 10) {apbio_ot++;} else{repbio_ot++;}
                    if(stof(fisica) >= 10) {apfis_ot++;} else{repfis_ot++;}
                    if(stof(educ_fisica) >= 10) {apef_ot++;} else{repef_ot++;}
                    if(stof(artes) >= 10) {apart_ot++;} else{repart_ot++;}   
                }
        }

        prompas_mat_masc = (apmat_masc / masc)*100;
        prompas_mat_fem = (apmat_fem / fem)*100;
        prompas_mat_ot = (apmat_ot / otro)*100;
        promrep_mat_masc = (repmat_masc / masc)*100;
        promrep_mat_fem = (repmat_fem / fem)*100;
        promrep_mat_ot = (repmat_ot / otro)*100;

        prompas_soc_masc = (apsoc_masc / masc)*100;
        prompas_soc_fem = (apsoc_fem / fem)*100;
        prompas_soc_ot = (apsoc_ot / otro)*100;
        promrep_soc_masc = (repsoc_masc / masc)*100;
        promrep_soc_fem = (repsoc_fem / fem)*100;
        promrep_soc_ot = (repsoc_ot / otro)*100;

        prompas_bio_masc = (apbio_masc / masc)*100;
        prompas_bio_fem = (apbio_fem / fem)*100;
        prompas_bio_ot = (apbio_ot / otro)*100;
        promrep_bio_masc = (repbio_masc / masc)*100;
        promrep_bio_fem = (repbio_fem / fem)*100;
        promrep_bio_ot = (repbio_ot / otro)*100;

        prompas_fis_masc = (apfis_masc / masc)*100;
        prompas_fis_fem = (apfis_fem / fem)*100;
        prompas_fis_ot = (apfis_ot / otro)*100;
        promrep_fis_masc = (repfis_masc / masc)*100;
        promrep_fis_fem = (repfis_fem / fem)*100;
        promrep_fis_ot = (repfis_ot / otro)*100;
        
        prompas_ef_masc = (apef_masc / masc)*100;
        prompas_ef_fem = (apef_fem / fem)*100;
        prompas_ef_ot = (apef_ot / otro)*100;
        promrep_ef_masc = (repef_masc / masc)*100;
        promrep_ef_fem = (repef_fem / fem)*100;
        promrep_ef_ot = (repef_ot / otro)*100;

        prompas_art_masc = (apart_masc / masc)*100;
        prompas_art_fem = (apart_fem / fem)*100;
        prompas_art_ot = (apart_ot / otro)*100;
        promrep_art_masc = (repart_masc / masc)*100;
        promrep_art_fem = (repart_fem / fem)*100;
        promrep_art_ot = (repart_ot / otro)*100;

        cout << "-- Proporcion de genero en matematicas --" << endl
            << "Femenino :" << prompas_mat_fem << "% " << "pasados, " << promrep_mat_fem << "% no pasados" << endl
            << "Masculino :" << prompas_mat_masc << "% " << "pasados, " << promrep_mat_masc << "% no pasados" << endl
            << "Otros generos :" << prompas_mat_ot << "% " << "pasados, " << promrep_mat_ot << "% no pasados" << endl << endl;

        cout << "-- Proporcion de genero en sociales --" << endl
            << "Femenino :" << prompas_soc_fem << "% " << "pasados, " << promrep_soc_fem << "% no pasados" << endl
            << "Masculino :" << prompas_soc_masc << "% " << "pasados, " << promrep_soc_masc << "% no pasados" << endl
            << "Otros generos :" << prompas_soc_ot << "% " << "pasados, " << promrep_soc_ot << "% no pasados" << endl << endl;
        
        cout << "-- Proporcion de genero en biologia --" << endl
            << "Femenino :" << prompas_bio_fem << "% " << "pasados, " << promrep_bio_fem << "% no pasados" << endl
            << "Masculino :" << prompas_bio_masc << "% " << "pasados, " << promrep_bio_masc << "% no pasados" << endl
            << "Otros generos :" << prompas_bio_ot << "% " << "pasados, " << promrep_bio_ot << "% no pasados" << endl << endl;
        
        cout << "-- Proporcion de genero en fisica --" << endl
            << "Femenino :" << prompas_fis_fem << "% " << "pasados, " << promrep_fis_fem << "% no pasados" << endl
            << "Masculino :" << prompas_fis_masc << "% " << "pasados, " << promrep_fis_masc << "% no pasados" << endl
            << "Otros generos :" << prompas_fis_ot << "% " << "pasados, " << promrep_fis_ot << "% no pasados" << endl << endl;

        cout << "-- Proporcion de genero en educacion fisica --" << endl
            << "Femenino :" << prompas_ef_fem << "% " << "pasados, " << promrep_ef_fem << "% no pasados" << endl
            << "Masculino :" << prompas_ef_masc << "% " << "pasados, " << promrep_ef_masc << "% no pasados" << endl
            << "Otros generos :" << prompas_ef_ot << "% " << "pasados, " << promrep_ef_ot << "% no pasados" << endl << endl;
        
        cout << "-- Proporcion de genero en artes --" << endl
            << "Femenino :" << prompas_art_fem << "% " << "pasados, " << promrep_art_fem << "% no pasados" << endl
            << "Masculino :" << prompas_art_masc << "% " << "pasados, " << promrep_art_masc << "% no pasados" << endl
            << "Otros generos :" << prompas_art_ot << "% " << "pasados, " << promrep_art_ot << "% no pasados" << endl << endl;
    }
    infile.close();
}