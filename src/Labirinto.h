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
	int posicaoSaida[2];   //QUANDO HOVER SA�DA, REGISTRA A POSICAO
	int posicaoEntrada[2]; //POSICAO INICIAL DO LABIRINTO
	char charSaida;        //CARACTERE QUE MARCA A SA�DA

public:
	Labirinto(std::string arq);    // CONSTRUTOR
	~Labirinto();				   // DESTRUTOR
	void imprimeLabirinto();       // IMPRESS�O EM TELA
	bool percorreLabirinto(int x, int y); // PERCORRER LABIRINTO
	int* getPosicaoEntrada();	  // RETORNA A POSICAO DE ENTRADA
	std::string getMaze();
	void imprimeLabirinto(std::string mensagem); // IMPRIME ARQUIVO DE SAIDA
private:
	bool acheiSaida(int x, int y); // ACHEI O CARACTERE DA SA�DA?
	bool podeMover(int x, int y);  // POSSO IR PARA A POSICAO INDICADA?
};


#endif /* SRC_LABIRINTO_H_ */
