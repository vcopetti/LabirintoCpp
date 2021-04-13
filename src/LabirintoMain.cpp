//============================================================================
// Name        : LabirintoMain.cpp
// Author      : Vinicius Copetti
// Version     : 1.0
// Copyright   : FREE
// Description : Percorrer labirinto em C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include "Labirinto.h"
#include <fstream>

using namespace std;


int main() {
	string nomeArq = "Labirinto1.txt";

	cout << "Labirinto Inicializado!" << endl;
	cout << "Digite o nome do arquivo: ";
	// cin >> nomeArq;
	Labirinto lab1(nomeArq);
	lab1.imprimeLabirinto();
	cout << "\nAnalisando o labirinto... \n";

	if (lab1.percorreLabirinto(lab1.getPosicaoEntrada()[0],
			lab1.getPosicaoEntrada()[1])) {
		cout << "Achei o FIM!!!!\n";
		lab1.imprimeLabirinto("SA�DA ENCONTRADA!");
	} else {
		cout << "N�o encontrei sa�da v�lida!\n";
		lab1.imprimeLabirinto("SEM SOLU��O");
	}
	cout << "\nLabirinto Finalizado!" << endl;
	delete &lab1;
	return 0;
	exit(0);
}
