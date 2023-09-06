//main.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SituacionP.h"
using namespace std;



int main(){

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
        Registro registro (fecha, hora, puntoEntrada, ubi);
        registros.push_back(registro);
    }

    archivo.close();

    //-----------------------------------------------------------

    for (int i = 0; i < registros.size(); i++) {
		cout << registros[i].fecha << " " << registros[i].hora << " " << registros[i].punto_entrada << " " << registros[i].ubi << endl;
	}

}

