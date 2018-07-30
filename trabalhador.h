#ifndef TRABALHADOR_H
#define TRABALHADOR_H

#include <iostream>
#include <string>
#include "recurso.h" 
class Trabalhador{
	public:
		//N
		std::string nome;
		//Variavel com nivel do trabalhador
		int nivel;
		//Quantidade de trabalhadores
		int qtd;	
		//Eficiencia do trabalhador
		int efic;
		//Custo pra produção do trabalhador
		Recurso *custo;
		//Criação do trabalhador
		Trabalhador(std::string , int , int , int , Recurso*);

		~Trabalhador();
		//Retorna quantidade de recurso conquistado
		int get_collected_res();
	
}

#endif