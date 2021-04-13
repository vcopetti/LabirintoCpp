/*
 * Labirinto.h
 *
 *  Created on: 12 de abr. de 2021
 *      Author: Vinicius Copetti
 */

#ifndef SRC_LABIRINTO_H_
#define SRC_LABIRINTO_H_
#include <string>

class Labirinto{
private:
	std::string nomeArquivo;
	char** maze;
	int linhasTotal;       //TOTAL DE LINHAS DO LABIRINTO
	int colunasTotal;      //TOTAL DE COLUNAS DO LABIRINTO
	int posicaoSaida[2];   //QUANDO HOVER SAÍDA, REGISTRA A POSICAO
	int posicaoEntrada[2]; //POSICAO INICIAL DO LABIRINTO
	char charSaida;        //CARACTERE QUE MARCA A SAÍDA

public:
	Labirinto(std::string arq);    // CONSTRUTOR
	~Labirinto();				   // DESTRUTOR
	void imprimeLabirinto();       // IMPRESSÃO EM TELA
	bool percorreLabirinto(int x, int y); // PERCORRER LABIRINTO
	int* getPosicaoEntrada();	  // RETORNA A POSICAO DE ENTRADA
	std::string getMaze();
	void imprimeLabirinto(std::string mensagem); // IMPRIME ARQUIVO DE SAIDA
private:
	bool acheiSaida(int x, int y); // ACHEI O CARACTERE DA SAÍDA?
	bool podeMover(int x, int y);  // POSSO IR PARA A POSICAO INDICADA?
};


#endif /* SRC_LABIRINTO_H_ */
