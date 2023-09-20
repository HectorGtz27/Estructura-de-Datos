// SituacionP.cpp
#define _CRT_SECURE_NO_WARNINGS

#include "SituacionP.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//  Esta línea de código es parte de la implementación del constructor de la clase Registro y 
// se utiliza para configurar los valores iniciales de los miembros de datos cuando se crea un nuevo objeto Registro.
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
        // Primero, compara por UBI
        if (L[i].ubi < R[j].ubi) {
            registros[k] = L[i];
            i++;
        }
        else if (L[i].ubi > R[j].ubi) {
            registros[k] = R[j];
            j++;
        }
        else { // Si las UBI son iguales, compara por fecha en formato día/mes/año
            std::string fechaL = L[i].fecha;
            std::string fechaR = R[j].fecha;

            int diaL, mesL, anioL, diaR, mesR, anioR;

            sscanf(fechaL.c_str(), "%d/%d/%d", &diaL, &mesL, &anioL);
            sscanf(fechaR.c_str(), "%d/%d/%d", &diaR, &mesR, &anioR);

            if (anioL < anioR || (anioL == anioR && mesL < mesR) || (anioL == anioR && mesL == mesR && diaL < diaR)) {
                registros[k] = L[i];
                i++;
            }
            else {
                registros[k] = R[j];
                j++;
            }
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
    vector<int> resultados;

    while (bajo <= alto) {
        int central = (bajo + alto) / 2;
        const std::string& ubiCentral = registros[central].ubi;

        // Verificar si la serie en UBI comienza con los primeros tres caracteres proporcionados
        if (ubiCentral < serieABuscar) {
            bajo = central + 1;
        }
        else {
            alto = central - 1;
        }
        
    }

    // Encontrar todas las entradas que coinciden
    int indice = bajo;
    while (indice < registros.size()) {
        const std::string& ubi = registros[indice].ubi;
        if (ubi.compare(0, serieABuscar.size(), serieABuscar) == 0) {
            resultados.push_back(indice);
            indice++;
        }
        else {
            break;
        }
    }

    // Imprimir las entradas encontradas
    if (!resultados.empty()) {
        cout << "Entradas encontradas para la serie " << serieABuscar << ":" << endl;
        for (int resultado : resultados) {
            cout << registros[resultado].ubi << " " << registros[resultado].fecha << " " << registros[resultado].hora << " " << registros[resultado].punto_entrada << endl;
        }
    }
    else {
        cout << "No se encontraron entradas para la serie " << serieABuscar << "." << endl;
    }

    return -1;
}
