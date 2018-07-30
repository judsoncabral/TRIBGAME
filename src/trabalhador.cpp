#include "../include/trabalhador.h"

Trabalhador::Trabalhador(std::string n, int l, int a, int e, Recurso *c) : nome(n), nivel(l) , qtd(a), efic(e), custo(c);{
	
}
Trabalhador::~Trabalhador(){
	
}

int Trabalhador::get_collected_res(){
	return qtd*efic*nivel;
}