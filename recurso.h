#ifndef RECURSO_H
#define RECURSO_H

#include <iostream>
#include <string>

class Recurso{
	public:
		//Tipo do recurso
		std::string nome;
		//Quantidade de Recurso
		int qtd;
		//Indicar o tipo do recurso;
		int tipo;

		//Contrutor pra inicializar as variaveis
		Recurso( std::string, int, int );
}

#endif