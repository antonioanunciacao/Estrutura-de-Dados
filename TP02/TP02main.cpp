#include <bits/stdc++.h> 
using namespace std; 
  
class Planet { 
public: 
    int time; 
	string name;
    Planet* next; 
}; 
  
/* function prototypes */
Planet* SortedMerge(Planet* a, Planet* b); 
void FrontBackSplit(Planet* source, Planet** frontRef, Planet** backRef); 
  
/* sorts the linked list by changing next pointers (not time) */
void MergeSort(Planet** headRef) { 
    Planet* head = *headRef; 
    Planet* a; 
    Planet* b; 
  
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b); 
  
    /* Recursively sort the sublists */
    MergeSort(&a); 
    MergeSort(&b); 
  
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b); 
} 
  
Planet* SortedMerge(Planet* a, Planet* b) { 
    Planet* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
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
void FrontBackSplit(Planet* source, Planet** frontRef, Planet** backRef) 
{ 
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
void printList(Planet* planet) 
{ 
    while (planet != NULL) { 
        cout << planet->time << ", " << planet->name << endl;
        planet = planet->next; 
    } 
} 
  
/* Function to insert a planet at the beginging of the linked list */
void insert(Planet** head_ref, int new_time, string new_name) 
{ 
    /* allocate planet */
    Planet* new_planet = new Planet(); 
  
    /* put in the time */
    new_planet->time = new_time; 
	new_planet->name = new_name; 
  
    /* link the old list off the new planet */
    new_planet->next = (*head_ref); 
  
    /* move the head to point to the new planet */
    (*head_ref) = new_planet; 
} 
  
/* Drier program to test above functions*/
int main() { 
    Planet* agenda = NULL; 
	int i = 0, tempo_visitacao, num_planetas, num_caracteres, tempo;
    string aux, nome, str, planeta;

    cout << "Lendo arquivo: " << endl;
	ifstream in("07.in");
    while (in.fail()) {
        cout << "arquivo não existe! digite novamente: " << endl;
    } 

    while (getline(in, str)) {
		if( i == 0) {
			tempo_visitacao = stoi(str.substr(0, str.find(' ')));
			num_planetas = stoi(str.substr(str.find(' '), str.find(' ')));
			aux = str.substr(str.find(' '));
			num_caracteres = stoi(aux.substr(str.find(' ')));
		}
		else {
			tempo = stoi(str.substr(0, str.find(' ')));
			nome = str.substr(str.find(' '));
			insert(&agenda, tempo, nome); 
		}
		i++;
	}

	in.close();
  
    /* Sort the above created Linked List */
	cout << "Arquivo: \n"; 
    printList(agenda);
	cout << "\n\n\n";
	cout << "Tempo de visitacao: " << tempo_visitacao << ", Numero de planetas: " << num_planetas << ", Tamanho dos nomes do planeta: " << num_caracteres << endl;
    MergeSort(&agenda); 
    cout << "Arquivo ordenado: \n"; 
    printList(agenda); 
  
    return 0; 
}