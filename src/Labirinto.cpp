/*
 * Labirinto.cpp
 *
 *  Created on: 12 de abr. de 2021
 *      Author: Vinicius Copetti
 */
#include "Labirinto.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Labirinto::Labirinto(string arq){
	this->nomeArquivo = arq;
	this->linhasTotal = 0;
	this->colunasTotal = 0;
	this->posicaoEntrada[0] = 0;
	this->posicaoEntrada[1] = 0;
	this->posicaoSaida[0] = 0;
	this->posicaoSaida[1] = 0;
	this->charSaida = 'D';
	string conteudo;
	bool acheiD = false;
	ifstream MyReadFile(this->nomeArquivo);

	try {

		cout << "Arquivo: " << this->nomeArquivo << endl;
		if (MyReadFile.good())
		{
			getline(MyReadFile, conteudo);
			this->linhasTotal = stoi(conteudo);
			getline(MyReadFile, conteudo);
			this->colunasTotal = stoi(conteudo);
			// não é moleza não
			this->maze = new char* [this->linhasTotal -1];
			for(int i=0; i < this->colunasTotal; i++)
				this->maze[i] = new char[this->colunasTotal -1];

			for(int i=0; getline(MyReadFile, conteudo); i++) {
				//  for para percorrer os caracteres
				for(int j=0; j < this->colunasTotal; j++) {
					this->maze[i][j] = conteudo[j];
					if(conteudo[j] == 'D'){
						acheiD = true;
						this->posicaoSaida[0] = i;
						this->posicaoSaida[1] = j;
					}
				}
			}
			if (!acheiD)
				throw 1 ;
		} else {
			throw 2;
		}
	} catch(int numErro) {
		if (numErro == 1)
			cout << "[ERRO 1] Caractere [D] não localizado no arquivo: " << this->nomeArquivo << endl;
		if (numErro == 2){
			cout << endl << "[ERRO 2] Arquivo Inexistente" << endl;
		}
	}
	MyReadFile.close();
}

Labirinto::~Labirinto(){
	delete this->maze;
}

void Labirinto::imprimeLabirinto(){
	for(int i=0; i< linhasTotal; i++){
		cout << "[" << i << "]";
		for(int j=0; j< colunasTotal; j++){
			cout << maze[i][j];
		}
		cout << endl;
	}
}

bool Labirinto::acheiSaida(int x, int y){
	if (maze[x][y] == 'D')
		return true;
	return false;
}

bool Labirinto::podeMover(int x, int y){
	if ((x < 0) || (y < 0) || (x == linhasTotal) || (y == colunasTotal))
		return false;
	if((maze[x][y] == 'X') || (maze[x][y] == '.'))
		return false;
	return true;
}

bool Labirinto::percorreLabirinto(int x, int y){
	bool acheiFim = false;

	if (acheiSaida(x, y)){
		posicaoSaida[0] = x;
		posicaoSaida[1] = y;
		return true;
	}
	// CARACTERE QUE MARCA POR ONDE PASSEI
	maze[x][y] = '.';
	// PODE MOVER PARA A DIREITA?
	if (podeMover(x, y + 1) && !acheiFim)
		acheiFim = percorreLabirinto(x, y + 1);
	// PODE MOVER PARA A BAIXO?
	if (podeMover(x + 1, y) && !acheiFim)
		acheiFim = percorreLabirinto(x + 1, y);
	// PODE MOVER PARA A ESQUERDA?
	if (podeMover(x, y - 1) && !acheiFim)
		acheiFim = percorreLabirinto(x, y - 1);
	// PODE MOVER PARA A CIMA?
	if (podeMover(x - 1, y) && !acheiFim)
		acheiFim = percorreLabirinto(x - 1, y);

	return acheiFim;
}

int* Labirinto::getPosicaoEntrada(){
  return this->posicaoEntrada;
}

void Labirinto::imprimeLabirinto(string mensagem){
	ofstream arqSaida("OUT-" + this->nomeArquivo);

	arqSaida << "===ANÁLISE DO ARQUIVO: " << this->nomeArquivo << "===" << endl << endl;
	arqSaida << mensagem << endl;
	arqSaida << "CAMINHO PERCORRIDO:" << endl;
	arqSaida << getMaze();
	arqSaida << endl << "PROCESSO FINALIZADO";
	arqSaida.close();
}

string Labirinto::getMaze(){
	string ret = "";

	for(int i=0; i< linhasTotal; i++){
		ret = ret + "[" + to_string(i) + "]";
		for(int j=0; j< colunasTotal; j++){
			ret = ret + maze[i][j];
		}
		ret = ret + '\n';
	}
	return ret;
}
