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

int main(int argc, char *argv[]) {
	ifstream entrada;
    streambuf *oldbuff = cin.rdbuf();
    int i, j, Tempo_visitacao, num_planetas, num_caracteres;
	int *planetaTempo;
	//char **planetaNomes;
		
    if(argc > 1) {
		entrada.open(argv[1]);
		if(!entrada.good()) {
			cout << "O arquivo \"" << argv[1] << "\" nao existe!\n";
            return 0;
        }
        cin.rdbuf(entrada.rdbuf());
	}
	else {
		cout << "Nenhum arquivo foi passado!\n";
        return 0;
    }

    do {
        cin >> Tempo_visitacao >> num_planetas >> num_caracteres;
        if(Tempo_visitacao < 0) {
            cout << "Tempo de visitacao invalido invalido\n";
            return 0;
        }
        else if(0 > num_planetas || num_planetas > 150000) {
            cout << "Numero de planetas invalido invalido\n";
            return 0;
        }

    } while(Tempo_visitacao < 0 || num_planetas <0 || num_caracteres < 0);
	
	cout << "Tempo_visitacao: " << Tempo_visitacao << ", num_planetas: " << num_planetas << ", num_caracteres: " << num_caracteres << endl;
	planetaTempo = new int(num_planetas);
	cout << "Vetor alocado!" << endl;
	//planetaNomes = new char(num_caracteres+1);
	
	//planetaNomes = new char *[num_planetas];
	//for (i = 0; i < num_planetas; i++) planetas[i] = new char[num_caracteres+1];

		
	for (i = 0; i < num_planetas; i++) {
		cin >> planetaTempo[i];
	}
	
	cout << "Vetor preenchido!" << endl;
	
	
	if(argc > 1) {
        entrada.close();
        cin.rdbuf(oldbuff);
		cout << "Arquivo fechado!" << endl;
    }
	
	
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
	
	
	int n;
	n= sizeof(planetaTempo);
	cout << "Tamanho da lista: " << n << endl;
	mergesort(planetaTempo, 0, n-1);
	cout << "mergesort:";
	printLista(planetaTempo, n);
	
    return 0;
}
