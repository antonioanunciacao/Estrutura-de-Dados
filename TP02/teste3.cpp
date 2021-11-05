#include <iostream>
#include <fstream>

using namespace std;

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

void printLista(int lista[], int tamanho){
	cout << endl;
	for(int i = 0; i < tamanho; i++){
		if(i < tamanho-1) cout << lista[i] << ", ";
		else cout << lista[i];
	}
	cout << endl;
}  

int main( ) {
	ifstream entrada;
    int i, j, Tempo_visitacao, num_planetas, num_caracteres;
	int *planetaTempo;
	entrada.open("filetest3.txt");

	entrada >> Tempo_visitacao >> num_planetas >> num_caracteres;
	cout << "Tempo_visitacao: " << Tempo_visitacao << ", num_planetas: " << num_planetas << ", num_caracteres: " << num_caracteres << endl;

	planetaTempo = new int(num_planetas);
	cout << "Vetor alocado!" << endl;
		
	for (i = 0; i < num_planetas; i++) {
		entrada >> planetaTempo[i];
	}
	cout << "Vetor preenchido!" << endl;
	
	entrada.close();
	cout << "Arquivo fechado!" << endl;

	
	
	for(j = 0; j < num_planetas; j++) {
		cout << planetaTempo[j] << endl;
	}
	
	float media = 0;
	int tempoTotal = 0;
	for(int k = 0; k < num_planetas; k++) {
		tempoTotal = tempoTotal + planetaTempo[k];
		media = media + planetaTempo[k]/num_planetas;
	}
	
	cout << "Tempo medio: " << media << endl;
	cout << "Tempo total: " << tempoTotal << endl;
	
	mergesort(planetaTempo, 0, num_planetas-1);
	cout << "mergesort:";
	printLista(planetaTempo, num_planetas);
	
    return 0;
}
