//main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SituacionP.h"
using namespace std;

int main() {
    // Leer el nombre del archivo
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo de entrada: ";
    cin >> nombreArchivo;

    ifstream archivo(nombreArchivo);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    vector<Registro> registros;

    string fecha, hora, ubi;
    char puntoEntrada;

    while (archivo >> fecha >> hora >> puntoEntrada >> ubi) {
        Registro registro(fecha, hora, puntoEntrada, ubi);
        registros.push_back(registro);
    }

    archivo.close();

    //-----------------------------------------------------------

    // Ordenar los registros utilizando Merge Sort
    Registro::ordenaMerge(registros, 0, registros.size() - 1);

    // Mostrar los registros ordenados por UBI + Fecha
    cout << "Registros ordenados por UBI + Fecha:" << endl;
    for (const Registro& reg : registros) {
        cout << reg.ubi  << " " << reg.fecha << endl;
    }


    // Solicitar al usuario la serie a buscar (los primeros tres caracteres del UBI)
    cout << endl;
    string serieABuscar;
    cout << "Ingrese los primeros tres caracteres de la serie a buscar: ";
    cin >> serieABuscar;

    // Utilizar la búsqueda binaria para encontrar la serie
    int indiceEncontrado = Registro::busquedaBinaria(registros, serieABuscar);

    if (indiceEncontrado != -1) {
        // Mostrar los registros encontrados en orden UBI+Fecha
        cout << "Registros encontrados para la serie " << serieABuscar << ":" << endl;
        while (indiceEncontrado >= 0 && registros[indiceEncontrado].ubi.substr(0, 3) == serieABuscar) {
            cout << registros[indiceEncontrado].ubi << " " << registros[indiceEncontrado].fecha << " " << registros[indiceEncontrado].hora << " " << registros[indiceEncontrado].punto_entrada << endl;
            indiceEncontrado--;
        }
    }
    else {
        cout << "No se encontraron registros para la serie " << serieABuscar << "." << endl;
    }


    return 0;
}
