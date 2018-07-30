#ifndef ESTRUTURA_H
#define ESTRUTURA_H
	
#include <iostream>
#include <string>

class Estrutura{
	public:
		std::string nome;
		int nivel;
		int qtd;
		int tipo;
		Recurso *custo;
	Estrutura(std::string , int , int , int , Recurso );
}

#endif