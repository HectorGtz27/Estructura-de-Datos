//SituacionP.h
#pragma once
#include <vector>
#include <string>

class Registro {
public:
    std::string fecha;
    std::string hora;
    char punto_entrada;
    std::string ubi;

    // Constructor predeterminado sin argumentos
    Registro() : fecha(""), hora(""), punto_entrada('\0'), ubi("") {}

    Registro(const std::string& f, const std::string& h, char p, const std::string& u);
    static void ordenaMerge(std::vector<Registro>& registros, int inicio, int fin);
    static void merge(std::vector<Registro>& registros, int inicio, int mitad, int fin);
    static int busquedaBinaria(const std::vector<Registro>& registros, const std::string& serieABuscar);
};
