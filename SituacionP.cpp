// SituacionP.cpp
#include "SituacionP.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

Registro::Registro(const std::string& f, const std::string& h, char p, const std::string& u)
    : fecha(f), hora(h), punto_entrada(p), ubi(u) {}

void Registro::ordenaMerge(std::vector<Registro>& registros, int inicio, int fin) {
    if (inicio < fin) {
        int mitad = (inicio + fin) / 2;
        ordenaMerge(registros, inicio, mitad); // "Conquer"
        ordenaMerge(registros, mitad + 1, fin); // "Conquer"
        merge(registros, inicio, mitad, fin); // "Combine"
    }
}

void Registro::merge(std::vector<Registro>& registros, int inicio, int mitad, int fin) {
    int n1 = mitad - inicio + 1;
    int n2 = fin - mitad;

    vector<Registro> L(n1);
    vector<Registro> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = registros[inicio + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = registros[mitad + 1 + i];
    }

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        // Comparación de UBI primero y luego fecha
        if (L[i].ubi + L[i].fecha < R[j].ubi + R[j].fecha) {
            registros[k] = L[i];
            i++;
        }
        else {
            registros[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        registros[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        registros[k] = R[j];
        j++;
        k++;
    }
}


int Registro::busquedaBinaria(const std::vector<Registro>& registros, const std::string& serieABuscar) {
    int bajo = 0;
    int alto = registros.size() - 1;

    while (bajo <= alto) {
        int central = (bajo + alto) / 2;
        const std::string& ubiCentral = registros[central].ubi;
        if (ubiCentral.substr(0, 3) == serieABuscar) {
            return central;
        }
        else if (serieABuscar < ubiCentral.substr(0, 3)) {
            alto = central - 1;
        }
        else {
            bajo = central + 1;
        }
    }

    return -1;
}
