#ifndef GUERREIRO_H
#define GUERREIRO_H
	
#include <iostream>
#include <string>

class Guerreiro{
	public:
		std::string nome;
		int nivel;
		int qtd;
		int dano;
		int tipo;
		Recurso *custo;

		Guerreiro( std::string , int , int , int, int, *Recurso);

		int Dano_causado();
}

#endif