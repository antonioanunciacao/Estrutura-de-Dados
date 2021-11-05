#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std; 
  
class Planet { 
public: 
    int time, mes; 
	char *name;
    Planet* next; 
}; 
  
/* function prototypes */
Planet* SortedMerge(Planet* a, Planet* b); 
void FrontBackSplit(Planet* source, Planet** frontRef, Planet** backRef); 
  
/* sorts the linked list by changing next pointers (not time) */
void MergeSort(Planet** headRef) {
	cout << "Chamada MergeSort!" << endl;
    Planet* head = *headRef; 
    Planet* a; 
    Planet* b; 
  
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) return;  
  
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b); 
  
    /* Recursively sort the sublists */
    MergeSort(&a); 
    MergeSort(&b); 
  
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b); 
} 
  
Planet* SortedMerge(Planet* a, Planet* b) {
	cout << "Chamada SortedMerge!" << endl;
    Planet* result = NULL; 
  
    /* Base cases */
    if (a == NULL) return (b); 
    else if (b == NULL) return (a); 
  
    /* Pick either a or b, and recur */
    if (a->time <= b->time) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
  
/* UTILITY FUNCTIONS */
/* Split the planets of the given list into front and back halves,  
    and return the two lists using the reference parameters.  
    If the length is odd, the extra planet should go in the front list.  
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(Planet* source, Planet** frontRef, Planet** backRef) { 
	//cout << "Chamada FrontBackSplit!" << endl;
    Planet* fast; 
    Planet* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two planets, and advance 'slow' one planet */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
  
/* Function to print planets in a given linked list */
void printList(Planet* planet, int num_caracteres) {
	//cout << "Chamada printList!" << endl;
	int i;
    string aux = ""; 
    while (planet != NULL) {
		aux = "";
		for (i = 0; i < num_caracteres+1; i++) aux = aux + (planet->name)[i]; 
		cout << planet->time << ", " << aux << endl;
		planet = planet->next;
    } 
} 
void printAgenda(Planet* planet, int num_caracteres) {
	//cout << "Chamada printAgenda!" << endl;
	int i;
    string aux = ""; 
    while (planet != NULL) {
		aux = "";
		for (i = 0; i < num_caracteres+1; i++) aux = aux + (planet->name)[i]; 
		cout << planet->mes << ", " << planet->time << ", " << aux << endl;
		planet = planet->next;
	} 
} 

void agendaList(Planet* planet, int tempo_visitacao) {
	//cout << "Chamada agendaList!" << endl;
	int mes_vizitacao = 1, soma = 0;
    while (planet != NULL) {
		soma = soma + planet->time;
		planet->mes = mes_vizitacao + soma/tempo_visitacao;
        planet = planet->next; 
    } 
}
  
/* Function to insert a planet at the beginging of the linked list */
void insert(Planet** head_ref, int new_time, string new_name, int num_caracteres) {
	cout << "Chamada insert!" << endl;
    /* allocate planet */
    Planet* new_planet = new Planet;
	//cout << "Planet* allocated!" << endl;
  
    /* put in the time */
	new_planet->mes = 0;
	//cout << "new_planet->mes = 0;!" << endl;
    new_planet->time = new_time;
	//cout << "new_planet->time = new_time; " << endl;
    new_planet->name = new char(num_caracteres+1); 
	//cout << "new_planet->name = new char(num_caracteres+1)" << endl;
    strcpy(new_planet->name, new_name.c_str()); 
	//cout << "strcpy(new_planet->name, new_name.c_str())" << endl;
  
    /* link the old list off the new planet */
    new_planet->next = (*head_ref);
	//cout << "new_planet->next = (*head_ref)" << endl;
  
    /* move the head to point to the new planet */
    (*head_ref) = new_planet;
	//cout << "(*head_ref) = new_planet" << endl;
	//string aux = "";
	//int i;
	//for (i = 0; i < num_caracteres+1; i++) aux = aux + (new_planet->name)[i]; 
	//cout << "Inserted: " << new_planet->time << ", " << aux << endl;
	
} 

void radixsort(String[] a, int lo, int hi, int d)
{  // Sort from a[lo] to a[hi], starting at the dth character.
   for (int i = lo; i <= hi; i++)
      for (int j = i; j > lo && less(a[j], a[j-1], d); j--)
         exch(a, j, j-1);
}
private static boolean less(String v, String w, int d)
{  return v.substring(d).compareTo(w.substring(d)) < 0;  }

void radixsort(Planet* planet, int MAX) {
    int i, j, d, m=1;
    Planet *temp, *head[10], *tail[10];

    // Process t digits
    for (j=1; j<=t; j++) { 
        // Initialize the queues, 0 to 9
        for (i=0; i<=9; i++) {
            head[i] = NULL;
            tail[i] = NULL;
        }

        // Process the list L
        while ( L != NULL ) {
            // Get the decimal digit with place value m
            d = static_cast<int>(L->val/m)%10;
            
            // Make temp point to the current list item
            temp = L;

            // Make L point to the next list item
            L = L->next;

            // Disconnect the current list item, making it self-contained
            temp->next = NULL;

            if (head[d]!= NULL) {   // The queue for digit d is not empty

                // Add the list item to the end of the queue for digit d
                tail[d]->next = temp;

                // Make tail[d] point to the new tail item of queue d
                tail[d] = temp;
            }
            else {   // The queue for digit d is empty
                head[d] = temp;  // Point to the new head
                tail[d] = temp;  // Point to the new tail
            }
        } // while

        // Find the index, d, of the first non-empty queue
        d=0;
        while (head[d]==NULL) d++;

        // Point to the first item of the first non-empty queue
        L = head[d];

        // Point to the last item of the first non-empty queue
        temp = tail[d];

        // Append the items of the remaining non-empty queues
        // to the tail of list L.
        d++;
        while (d<10) {
            if (head[d]!=NULL) {
                // Append the items of non-empty queue d to list L
                temp->next = head[d];

                // Point to the new tail of list L
                temp = tail[d];
            }

            d++;
        } // while

        // Prepare to process the next more significant digit
        m = m*10;
    } // for

} 
 
 
/* Main program*/
int main() { 
    Planet* agenda = NULL; 
	int i = 0, tempo_visitacao, num_planetas, num_caracteres, tempo;
    string aux, nome, str, planeta;

    cout << "Lendo arquivo: " << endl;
	ifstream in("07.in");
    while (in.fail()) {
        cout << "arquivo não existe! digite novamente: " << endl;
		return 0;
    } 

    while (getline(in, str)) {
		if( i == 0) {
			//cout << str << endl;
			tempo_visitacao = stoi(str.substr(0, str.find(' ')));
			//cout << "tempo_visitacao: " << tempo_visitacao << endl;
			num_planetas = stoi(str.substr((str.find(' ')), (str.find(' '))));
			//cout << "num_planeta: " << num_planetas << endl;
			aux = str.substr(str.find(' ')+1);
			//cout << "aux:" << aux << endl;
			//cout << "aux_split:" << aux.substr(aux.find(' ')) << endl;
			num_caracteres = stoi(aux.substr(aux.find(' ')));
			cout << "Tempo de visitacao: " << tempo_visitacao << ", Numero de planetas: " << num_planetas << ", Tamanho dos nomes do planeta: " << num_caracteres << endl;
		}
		else {
			tempo = stoi(str.substr(0, str.find(' ')));
			nome = str.substr(str.find(' '));
			insert(&agenda, tempo, nome, num_caracteres);
			//cout <<	tempo << "; " << nome << endl;		
		}
		i++;
	}

	in.close();

	cout << "Arquivo: \n"; 
    printList(agenda, num_caracteres);
	cout << "\n\n\n";
	cout << "Tempo de visitacao: " << tempo_visitacao << ", Numero de planetas: " << num_planetas << ", Tamanho dos nomes do planeta: " << num_caracteres << endl;
    MergeSort(&agenda); 
    //cout << "\n\nArquivo ordenado: \n"; 
    //printList(agenda, num_caracteres); 
	agendaList(agenda, tempo_visitacao);
	cout << "\n\nAgenda de visita: \n";
	printAgenda(agenda, num_caracteres);
	cout << "Tempo de visitacao: " << tempo_visitacao << ", Numero de planetas: " << num_planetas << ", Tamanho dos nomes do planeta: " << num_caracteres << endl;
	delete agenda;
    return 0; 
}