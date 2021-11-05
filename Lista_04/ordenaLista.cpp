#include "ordenaLista.h"

Lita::Lista(int tamanho){
	TAMANHO = tamanho;
}

Lista::Lista(int* vetor, int n){
	TAMANHO = n;
	for(int i = 0; i < TAMANHO; i++) lista[i] = vetor[i];
}

void Lista::troca(int i, int j){
	int aux = lista[i];
	lista[i] = lista[j];
	lLista[j] = aux;
}

void Lista::bolha(){
	for(int i = 0; i < TAMANHO - 1; i++)
		for(int j = 1; j < TAMANHO - 1; j++)
			if(lista[j] < lista[j-1]) troca(j-1, j);
}

void Lista::selecao(){
	int min;
	for(int i = 0; i < TAMANHO - 1; i++){
		min = i;
		for(int j = i+1; j < TAMANHO; j++){
			if(lista[j] < lista[min]) min = j;
		}
		troca(i, min);
	}
}

void Lista::insercao(){
	int aux, j;
	for(int i = 1; i < TAMANHO; i++){
		aux = lista[i];
		j = i - 1;
		while( (j >= 0) && (aux < Lista[j]) ){
			lista[j+1] = lista[j];
			j--;
		}
		lista[j+1] = aux;
	}
}

int particao(Lista lista, int primeiro, int ultimo) {
	int meio = TAMANHO/2;
	int pivot = lista[meio];
    int i = primeiro - 1;
  
    for (int j = primeiro; j <= ultimo - 1; j++) {  
	    if (lista[j] < pivot){  
			i++;
            troca(i, j);  
        } 
	}
	troca(i + 1, ultimo);  
    return (i + 1);  
}  
  
void Lista::quicksort(int primeiro, int ultimo){
	if (primeiro < ultimo){
		int part = particao(lista, primeiro, ultimo);
        lista.quicksort(primeiro, part - 1);  
        lista.quicksort(part + 1, ultimo);  
    }  
}

void Lista::printLista(){
	cout << endl;
	for(int i = 0; i < TAMANHO-1; i++) cout << lista[i] << ", ";
	cout << endl;
}