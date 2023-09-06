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

	Registro(const std::string& f, const std::string& h, char p, const std::string& u);
	void Merge(std::vector<int>& nums, int inicio, int mitad, int fin);
	void oredenaMerge(std::vector<int>& nums, int inicio, int fin);

private:



};
