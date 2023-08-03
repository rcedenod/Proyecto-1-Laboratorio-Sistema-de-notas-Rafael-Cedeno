#include <iostream>
#include <string>
using namespace std;

struct Estudiantes
{
    string nombre;
    string apellido;
    string email;
    string genero;
    int notas_matematica;
    int notas_sociales;
    int notas_biologia;
    int notas_fisica;
    int notas_educ_fisica;
    int notas_artes;
};

Estudiantes estudiante[1500];

int partition_mate(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_matematica >= pivot.notas_matematica) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort_mate(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_mate(arr, low, high);
  
        quicksort_mate(arr, low, pivotIndex - 1);
        quicksort_mate(arr, pivotIndex + 1, high);
    }
}

int partition_soc(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_sociales >= pivot.notas_sociales) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort_soc(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_soc(arr, low, high);
  
        quicksort_soc(arr, low, pivotIndex - 1);
        quicksort_soc(arr, pivotIndex + 1, high);
    }
}

int partition_bio(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_biologia >= pivot.notas_biologia) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort_bio(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_bio(arr, low, high);
  
        quicksort_bio(arr, low, pivotIndex - 1);
        quicksort_bio(arr, pivotIndex + 1, high);
    }
}

int partition_fis(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_fisica >= pivot.notas_fisica) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort_fis(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_fis(arr, low, high);
  
        quicksort_fis(arr, low, pivotIndex - 1);
        quicksort_fis(arr, pivotIndex + 1, high);
    }
}

int partition_ef(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_educ_fisica >= pivot.notas_educ_fisica) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort_ef(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_ef(arr, low, high);
  
        quicksort_ef(arr, low, pivotIndex - 1);
        quicksort_ef(arr, pivotIndex + 1, high);
    }
}

int partition_art(Estudiantes arr[], int low, int high) {
    Estudiantes pivot = arr[high];
    int i = low - 1;
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].notas_artes >= pivot.notas_artes) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
  
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quicksort_art(Estudiantes arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition_art(arr, low, high);
  
        quicksort_art(arr, low, pivotIndex - 1);
        quicksort_art(arr, pivotIndex + 1, high);
    }
}