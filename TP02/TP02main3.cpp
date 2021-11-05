#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std; 

// DEFINIÇÃO DA CLASSE BASICA:  
class Planeta { 
public: 
    int tempo, mes; 
	char *nome;
    Planeta* proximo; 
}; 
  
// DEFINIÇÃO DOS PROTOTIPOS DAS FUNÇÕES:
Planeta* merge(Planeta* a, Planeta* b); 
void particiona(Planeta* source, Planeta** frontRef, Planeta** backRef); 
void mergeSort(Planeta** headRef);
void printList(Planeta* planeta, int num_caracteres);
void printAgenda(Planeta* planeta, int num_caracteres);
void out(Planeta* planeta, int num_caracteres, int index);
void agendaList(Planeta* planeta, int tempo_visitacao);
void insere(Planeta** head_ref, int novo_tempo, string novo_nome, int num_caracteres);

  
// PROGRAMA PRINCIPAL:
int main() {  
	int i, index, tempo_visitacao, num_planetas, num_caracteres, tempo;
    string aux1, aux2, nome, str, planeta, saida, entrada;
	Planeta* agenda = NULL;

	for( index = 1; index < 15; index++) {
		i = 0;
		cout << "Lendo arquivo: ";
		if( index < 10) {
			aux1 = index + '0';
			entrada = "0" + aux1 + ".in";
		}
		else {
			aux1 = index/10 + '0';
			aux2 = index%10 + '0';
			entrada = aux1 + aux2 + ".in";
		}
		cout << entrada << endl;
		ifstream in(entrada);
		while (in.fail()) {
			cout << "arquivo não existe! digite novamente: " << endl;
			return 0;
		}
		agenda = NULL;

		while (getline(in, str)) {
			if( i == 0) {
				//cout << str << endl;
				tempo_visitacao = stoi(str.substr(0, str.find(' ')));
				//cout << "tempo_visitacao: " << tempo_visitacao << endl;
				num_planetas = stoi(str.substr((str.find(' ')), (str.find(' '))));
				//cout << "num_planeta: " << num_planetas << endl;
				aux1 = str.substr(str.find(' ')+1);
				//cout << "aux:" << aux << endl;
				//cout << "aux_split:" << aux.substr(aux.find(' ')) << endl;
				num_caracteres = stoi(aux1.substr(aux1.find(' ')));
				//cout << "Tempo de visitacao: " << tempo_visitacao << ", Numero de planetas: " << num_planetas << ", Tamanho dos nomes do planeta: " << num_caracteres << endl;
			}
			else {
				tempo = stoi(str.substr(0, str.find(' ')));
				nome = str.substr(str.find(' '));
				insere(&agenda, tempo, nome, num_caracteres);
				//cout <<	tempo << "; " << nome << endl;		
			}
			i++;
		}

		in.close();

		//cout << "Arquivo: \n"; 
		//printList(agenda, num_caracteres);
		cout << "Tempo de visitacao: " << tempo_visitacao << ", Numero de planetas: " << num_planetas << ", Tamanho dos nomes do planeta: " << num_caracteres << endl;
		mergeSort(&agenda); 
		//cout << "\n\nArquivo ordenado: \n"; 
		//printList(agenda, num_caracteres); 
		agendaList(agenda, tempo_visitacao);
		cout << "Agenda de visita: \n";
		printAgenda(agenda, num_caracteres);
		out(agenda, num_caracteres, index);
		cout << "\n\n";
		
	}
	delete agenda;
    return 0; 
}


// FUNÇÕES DO PROGRAMA:
void mergeSort(Planeta** headRef) {
	Planeta *head = *headRef, *a, *b; 
  
    if ((head == NULL) || (head->proximo == NULL)) return;  
  
    // SEPARA EM DUAS NOVAS LISTA DE PLANETAS
    particiona(head, &a, &b); 
    mergeSort(&a); 
    mergeSort(&b); 
	
	// MESCLA DUAS LISTA
    *headRef = merge(a, b); 
} 
  
Planeta* merge(Planeta* a, Planeta* b) {
    Planeta* result = NULL; 
  
    if (a == NULL) return (b); 
    else if (b == NULL) return (a); 
  
    /* Pick either a or b, and recur */
    if (a->tempo <= b->tempo) { 
        result = a; 
        result->proximo = merge(a->proximo, b); 
    } 
    else { 
        result = b; 
        result->proximo = merge(a, b->proximo); 
    } 
    return (result); 
} 
  
/* UTILITY FUNCTIONS */
/* Split the planets of the given list into front and back halves,  
    and return the two lists using the reference parameters.  
    If the length is odd, the extra planet should go in the front list.  
    Uses the fast/slow pointer strategy. */
void particiona(Planeta* source, Planeta** frontRef, Planeta** backRef) { 
	//cout << "Chamada particiona!" << endl;
    Planeta *fast, *slow;
    slow = source; 
    fast = source->proximo; 
  
    /* Advance 'fast' two planets, and advance 'slow' one planet */
    while (fast != NULL) { 
        fast = fast->proximo; 
        if (fast != NULL) { 
            slow = slow->proximo; 
            fast = fast->proximo; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source; 
    *backRef = slow->proximo; 
    slow->proximo = NULL; 
} 
  
/* Function to print planets in a given linked list */
void printList(Planeta* planeta, int num_caracteres) {
	//cout << "Chamada printList!" << endl;
	int i;
    string aux = ""; 
    while (planeta != NULL) {
		aux = "";
		for (i = 0; i < num_caracteres+1; i++) aux = aux + (planeta->nome)[i]; 
		cout << planeta->tempo << ", " << aux << endl;
		planeta = planeta->proximo;
    } 
}

void printAgenda(Planeta* planeta, int num_caracteres) {
	//cout << "Chamada printAgenda!" << endl;
	int i;
    string aux = ""; 
    while (planeta != NULL) {
		aux = "";
		for (i = 0; i < num_caracteres+1; i++) aux = aux + (planeta->nome)[i]; 
		cout << planeta->mes << ", " << planeta->tempo << ", " << aux << endl;
		planeta = planeta->proximo;
	} 
} 

void out(Planeta* planeta, int num_caracteres, int index) {
	ofstream out;
	string saida, aux, aux1, aux2;
		if( index < 10) {
			aux1 = index + '0';
			saida = "0" + aux1 + ".out";
		}
		else {
			aux1 = index/10 + '0';
			aux2 = index%10 + '0';
			saida = aux1 + aux2 + ".out";
		}
	out.open(saida);
	int i;
    aux = ""; 
    while (planeta != NULL) {
		aux = "";
		for (i = 0; i < num_caracteres+1; i++) aux = aux + (planeta->nome)[i]; 
		out << planeta->mes << " " << aux << " " << planeta->tempo << endl;
		planeta = planeta->proximo;
	}
	out.close();
} 

void agendaList(Planeta* planeta, int tempo_visitacao) {
	int mes_vizitacao = 1, soma = 0;
    while (planeta != NULL) {
		soma = soma + planeta->tempo;
		planeta->mes = mes_vizitacao + soma/tempo_visitacao;
        planeta = planeta->proximo; 
    } 
}
  
// INSERE DADO NO INICO DA LISTA
void insere(Planeta** head_ref, int novo_tempo, string novo_nome, int num_caracteres) {
    Planeta* novo_planeta = new Planeta;
	
	// ATRIBUIÇÃO DOS VALORES
	novo_planeta->mes = 0;
    novo_planeta->tempo = novo_tempo;
    novo_planeta->nome = new char(num_caracteres+1); 
    strcpy(novo_planeta->nome, novo_nome.c_str()); 
  
    // LIGA UM NÓ AO ANTERIOR
    novo_planeta->proximo = (*head_ref);
  
    // ATUALIZA A CABEÇA DA LISTA
    (*head_ref) = novo_planeta;

} 
