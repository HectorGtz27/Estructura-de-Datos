//SituacionP.cpp
#include "SituacionP.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Registro::Registro(const std::string& f, const std::string& h, char p, const std::string& u)
    : fecha(f), hora(h), punto_entrada(p), ubi(u) {}

//Merge para MergeSort
void Registro::Merge(std::vector<int>& nums, int inicio, int mitad, int fin) {
    vector<int> aux(fin + 1); // Vector auxiliar para almacenar el resultado fusionado
    int i = inicio, j = mitad + 1, k = inicio;

    while (i <= mitad && j <= fin) {
        if (nums[i] < nums[j]) { // Comparar los elementos de los subarreglos
            aux[k] = nums[i];
            i++;
        }
        else {
            aux[k] = nums[j];
            j++;
        }
        k++;
    }

    while (i <= mitad) {
        aux[k] = nums[i];
        i++;
        k++;
    }

    while (j <= fin) {
        aux[k] = nums[j];
        j++;
        k++;
    }

    for (k = inicio; k <= fin; k++) {
        nums[k] = aux[k];
    }
}


//Ordenamiento por MergeSort
void Registro::oredenaMerge(std::vector<int>& nums, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        oredenaMerge(nums, inicio, mitad); // "Conquer"
        oredenaMerge(nums, mitad + 1, fin); // "Conquer"
        Merge(nums, inicio, mitad, fin); // "Combine"
    }
}
