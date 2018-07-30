#ifndef VILAREJO_H
#define VILAREJO_H
	
#include "trabalhador.h"
#include "guerreiro.h"
#include "recurso.h"
#include "estrutura.h"

class Vilarejo{
	public:
		std::string nome;
		std::vector < Recurso > rec;
		std::vector < Trabalhador > trab;
		std::vector < Guerreiro > guer;
		std::vector < Estruturas > est;
}

#endif