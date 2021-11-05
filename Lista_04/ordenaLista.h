#ifndef LISTA_H
#define LISTA_H

#include <iostream>
using namespace std;

class Lista {
		int TAMANHO;
        int lista[TAMANHO];
		
    public:
        lista();
		Lista(int*, int);
		~Lista();
		void troca(int, int);
		void bolha();
		void selecao();
		void insersao();
		void quicksort();
		void mergesort();
		void heapsort();
		void shellsort();
		void printLista();

};

#endif