#include <iostream>

void Troca(int vetor[], int i, int j) {
	int c = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = c;
}

void Bolha(int vetor[], int n) {
	if(n == 1) return;
	for(int i = 0; i < n - 1; i++)
		if(vetor[i] > vetor[i+1]) Troca(vetor, i, i+1);
	Bolha(vetor, n-1);
}

void Selecao(int vetor[], int n) {
	int Min;
	for (int i = 0; i < n - 1; i++) {
		Min = i;
		for (int j = i + 1 ; j < n; j++) 
			if (vetor[j] < vetor[Min]) Min = j;
		Troca(vetor, i, Min);	
	}
}

void Selecao2(int vetor1[], int vetor2[], int n) {
	int Min;
	for (int i = 0; i < n - 1; i++) {
		Min = i;
		for (int j = i + 1 ; j < n; j++) 
			if (vetor1[j] < vetor1[Min]) Min = j;
		Troca(vetor1, i, Min);
		Troca(vetor2, i, Min);
		
	}
}

void SelecaoEstavel(int vetor1[], int vetor2[], int n) {
	int Min;
	for (int i = 0; i < n - 1; i++) {
		Min = i;
		for (int j = i + 1 ; j < n; j++) 
			if (vetor1[j] < vetor1[Min]) Min = j;
		Troca(vetor1, i, Min);
		Troca(vetor2, i, Min);
		
	}
}

int main() {
	int A[10], B[10], CC[10], CC1[10], aux[10], n;
	int C[10] = {10, 12, 12, 15, 21, 1, 3, 78, 103, 1};
	int C1[10] = {10, 12, 12, 15, 21, 1, 3, 78, 103, 1};
	
	for(int i = 0; i < 10; i++) {
		A[i] = rand() % 10000;
		B[i] = rand() % 100;
		aux[i] = 0;
	}
	n = sizeof(A)/sizeof(int);
	std::cout << "\nVetor A original: ";
	for(int i = 0; i < 10; i++) std::cout << A[i] << " ";
	
	std::cout << "\nVetor B original: ";
	for(int i = 0; i < 10; i++) std::cout << B[i] << " ";
	
	Bolha(A, n);
	Selecao(B,n);
	
	std::cout << "\nVetor A ordenado: ";
	for(int i = 0; i < 10; i++) std::cout << A[i] << " ";
	
	std::cout << "\nVetor B ordenado: ";
	for(int i = 0; i < 10; i++) std::cout << B[i] << " ";

	std::cout << "\nVetor C: ";
	for(int i = 0; i < 10; i++) std::cout << C[i] << " ";
	for(int i = 0; i < 10; i++) CC[i] = i+1;
	std::cout << "\nOrdem do vetor C: ";
	for(int i = 0; i < 10; i++) std::cout << CC[i] << " ";
	
	Selecao2(C, CC,n);
	std::cout << "\nVetor C ordenado: ";
	for(int i = 0; i < 10; i++) std::cout << C[i] << " ";
	std::cout << "\n/Nova ordem dos indices do vetor C: ";
	for(int i = 0; i < 10; i++) std::cout << CC[i] << " ";
	
    return 0;
}

