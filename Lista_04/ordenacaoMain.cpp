#include <iostream>
using namespace std;
  
void troca(int* a, int* b){
    int t = *a;  
    *a = *b;  
    *b = t; 
}

void bolha(int lista[], int tamanho){
	int iteracao = 0;	
	for(int i = 0; i < tamanho; i++){
		for(int j = 1; j < tamanho; j++){
			if( (lista[j] < lista[j-1]) && (iteracao < 3) ) {
				troca(&lista[j-1], &lista[j]);
				iteracao++;
				cout << iteracao << " ";
			}
		}
	}
}

void selecao(int lista[], int tamanho){
	int iteracao = 0;	
	int min;
	for(int i = 0; i < tamanho - 1; i++){
		min = i;
		for(int j = i+1; j < tamanho; j++){
			if(lista[j] < lista[min]) min = j;
		}
		troca(&lista[i], &lista[min]);
		iteracao++;
		cout << iteracao << " ";
		if(iteracao == 3) break;
	}
}

void insercao(int lista[], int tamanho){
	int aux, j;
	int iteracao = 0;	
	
	for(int i = 1; i < tamanho; i++){
		aux = lista[i];
		j = i - 1;
		while( (j >= 0) && (aux < lista[j]) ){
			lista[j+1] = lista[j];
			j--;
			iteracao++;
			cout << iteracao << " ";	
		}
		lista[j+1] = aux;
		if(iteracao == 3) break;
	}
}

int particao(int lista[], int inicio, int fim){  
    int pivo = lista[fim];
    int i = (inicio - 1);
  
    for (int j = inicio; j <= fim - 1; j++){
		if (lista[j] < pivo){
			i++;
            troca(&lista[i], &lista[j]);  
        }  
    }  
    troca(&lista[i + 1], &lista[fim]); 
	
    return(i+1);  
}  
  
void quicksort(int lista[], int inicio, int fim){  
    if (inicio < fim){  
        int p_index = particao(lista, inicio, fim);  
		quicksort(lista, inicio, p_index - 1);  
        quicksort(lista, p_index + 1, fim);  
    }  
}  

void merge(int lista[], int esquerda, int meio, int direita){ 
    int i, j, k; 
    int n1 = meio - esquerda + 1; 
    int n2 =  direita - meio; 
  
    int auxEsquerda[n1], auxDireita[n2]; 
  
    for(i = 0; i < n1; i++) auxEsquerda[i] = lista[esquerda + i]; 
    for(j = 0; j < n2; j++) auxDireita[j] = lista[meio + 1+ j];
  
    i = 0;
    j = 0;
    k = esquerda;
    while(i < n1 && j < n2){ 
        if(auxEsquerda[i] <= auxDireita[j]){ 
            lista[k] = auxEsquerda[i]; 
            i++; 
        } 
        else{ 
            lista[k] = auxDireita[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1){ 
        lista[k] = auxEsquerda[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2){ 
        lista[k] = auxDireita[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergesort(int lista[], int esquerda, int direita){ 
    if (esquerda < direita){ 
        int meio = esquerda + (direita-esquerda)/2; 
  
        mergesort(lista, esquerda, meio); 
        mergesort(lista, meio+1, direita); 
  
        merge(lista, esquerda, meio, direita); 
    } 
} 

void heap(int lista[], int tamanho, int i){ 
    int maior = i;
    int esquerda = 2*i + 1;
    int direita = 2*i + 2;
  
    if (esquerda < tamanho && lista[esquerda] > lista[maior]) maior = esquerda; 
    if (direita < tamanho && lista[direita] > lista[maior]) maior = direita; 
  
    if (maior != i){
		troca(&lista[i], &lista[maior]); 
        heap(lista, tamanho, maior); 
    } 
} 
  
void heapsort(int lista[], int tamanho){ 
    for (int i = tamanho/2 - 1; i >= 0; i--) heap(lista, tamanho, i); 
	for (int i = tamanho-1; i>=0; i--){
		troca(&lista[0], &lista[i]); 
        heap(lista, i, 0); 
    } 
}

void shellsort(int lista[], int tamanho){ 
    for (int h = tamanho/2; h > 0; h /= 2){ 
        for (int i = h; i < tamanho; i += 1) { 
            int temp = lista[i]; 
            int j;             
            for (j = i; j >= h && lista[j - h] > temp; j -= h) lista[j] = lista[j - h];
			lista[j] = temp; 
        } 
    }
}

void printLista(int lista[], int tamanho){
	cout << endl;
	for(int i = 0; i < tamanho; i++){
		if(i < tamanho-1) cout << lista[i] << ", ";
		else cout << lista[i];
	}
	cout << endl;
}  
 
int main(){
/*  
    int lista1[] = {13, 140, 7, 19, 1, 43, 14, 5, 27, 117, 101, 6, 12, 8, 99};
	int lista2[] = {13, 140, 7, 19, 1, 43, 14, 5, 27, 117, 101, 6, 12, 8, 99};
	int lista3[] = {13, 140, 7, 19, 1, 43, 14, 5, 27, 117, 101, 6, 12, 8, 99};
	int lista4[] = {13, 140, 7, 19, 1, 43, 14, 5, 27, 117, 101, 6, 12, 8, 99};
	int lista5[] = {13, 140, 7, 19, 1, 43, 14, 5, 27, 117, 101, 6, 12, 8, 99};
	int lista6[] = {13, 140, 7, 19, 1, 43, 14, 5, 27, 117, 101, 6, 12, 8, 99};
	int lista7[] = {13, 140, 7, 19, 1, 43, 14, 5, 27, 117, 101, 6, 12, 8, 99};
	
	int n = sizeof(lista1) / sizeof(int);
	bolha(lista1, n);
	cout << "Bolha:";
	printLista(lista1, n);
	
	selecao(lista2, n);
	cout << "selecao:";
	printLista(lista2, n);
	
	insercao(lista3, n);
	cout << "Insercao:";
	printLista(lista3, n);
	
	quicksort(lista4, 0, n-1);
	cout << "Quicksort:";
	printLista(lista4, n);

	mergesort(lista5, 0, n-1);
	cout << "mergesort:";
	printLista(lista5, n);

	mergesort(lista6, 0, n-1);
	cout << "heapsort:";
	printLista(lista6, n);
	
	shellsort(lista7, n);
	cout << "shellsort:";
	printLista(lista7, n);
*/	

	cout << endl << endl << "EXERCICIO 2" << endl;
	int listaE2_1[] = {2, 5, 1, 7, 6, 8, 4, 3};
	int listaE2_2[] = {2, 5, 1, 7, 6, 8, 4, 3};
	int listaE2_3[] = {2, 5, 1, 7, 6, 8, 4, 3};
	int listaE2_4[] = {3, 6, 4, 2, 5, 8, 7, 1};	
	int m = sizeof(listaE2_1) / sizeof(int);
	bolha(listaE2_1, m);
	cout << "Bolha:";
	printLista(listaE2_1, m);
	
	selecao(listaE2_2, m);
	cout << "selecao:";
	printLista(listaE2_2, m);
	
	insercao(listaE2_3, m);
	cout << "Insercao:";
	printLista(listaE2_3, m);
	
	heapsort(listaE2_4, m);
	cout << "Heapsort:";
	printLista(listaE2_4, m);
	
    return 0;  
}  
  