#include "Autor.hh"

Autor::Autor(){}

Autor::Autor (string nomautor){
	nom_autor = nomautor;
	string iniciales;
	getline (cin, nomautor);
	istringstream issini(nomautor);
	while (issini >> nomautor){
		inicials_priv += nomautor[0];
	}
}

Autor::~Autor() {}

string Autor::nom() const {
	return nom_autor;
}

string Autor::inicials() const {
	return inicials_priv;
}

int Autor::consultar_numparaules() const {
	return num_paraules_aut;
}

int Autor::consultar_numfrases() const{
	return num_frases_aut;
}

void Autor::afegir_paraules (int paraules){
	num_paraules_aut += paraules;
}

void Autor::eliminar_paraules (int paraules){
	num_paraules_aut -= paraules;
}

void Autor::afegir_frases(int frases){
	num_frases_aut += frases;
}

void Autor::eliminar_frases(int frases){
	num_frases_aut -= frases;
}


