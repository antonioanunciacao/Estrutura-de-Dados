#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Lista{ /* estrutura duplamente auto-referenciada */

	int valor;
    struct Lista *anterior, *proximo; 

};

typedef struct Lista Lista; /* definição do tipo Lista a partir do tipo 'struct Lista' */
typedef Lista *ListaPTR; /* definição do tipo *ListaPTR a partir do tipo Lista */

/* insere um nó no início da lista */
void insere_no_inicio(ListaPTR *inicio, int valor){
     
     ListaPTR novo;
     
     novo = (ListaPTR) malloc(sizeof(Lista)); /* aloca memória para o novo nó */
     
     if(novo == NULL) /* se não houver memória disponível */ 
         return;      /* sai da função */
     
     if(*inicio == NULL){    /* se a lista estivava vazia */
         novo->valor = valor; /* insere o valor no novo nó */
         novo->proximo = novo->anterior = NULL; /* não há próximo nó nem nó anterior, pois só há um nó */
         *inicio = novo; /* o novo nó é o primeiro da lista */
     }
     else{   /* se já havia nó na lista */
         novo->valor = valor; /* insere o valor no novo nó */
         novo->anterior = NULL; /* não há nó anterior */
         novo->proximo = *inicio; /* o novo nó aponta para o que está no início */
         (*inicio)->anterior = novo; /* o nó atual do início aponta para o novo nó */
         *inicio = novo; /* o novo nó passa a ser o primeiro da lista */
     }
}

/* insere um valor no final da lista */
void insere_no_final(ListaPTR *inicio, int valor){
     
     ListaPTR novo, atual;
     
     novo = malloc(sizeof(Lista));
     
     if(novo == NULL)
         return;
     
     if(*inicio == NULL){
         novo->valor = valor;
         novo->proximo = novo->anterior = NULL;
         *inicio = novo;
     }
     else{
         atual = *inicio; /* atual aponta para o início */
         while(atual->proximo != NULL) /* enquanto o nó atual não for o último */
             atual = atual->proximo;    /* vai para o nó seguinte */
         
         novo->valor = valor;
         novo->anterior = atual;  /*o nó anterior ao novo é o nó atual */
         novo->proximo = NULL; /* não há próximo nó, pois o novo será o último */
         atual->proximo = novo; /* o nó atual aponta para o novo nó e não é mais o último */
     }
}   

/* remove um nó escolhido pelo usuário */
int retira(ListaPTR *inicio, int valor){
    
    ListaPTR temporario, atual;
    
    if(*inicio == NULL) 
        return 0; /* retorna 0 caso a lista esteja vazia */
    
    atual = *inicio; /* o nó atual é o do início */
    
    if((*inicio)->valor == valor) /* caso o no a ser retirado seja o do inicio */
        *inicio = (*inicio)->proximo; /* o nó inicial passa a ser o próximo da lista */
    
    while(atual != NULL && atual->valor != valor) /*se há nó e o valor do mesmo não é o valor que se quer retirar*/
        atual = atual->proximo; /*passa para o próximo*/
    
    if(atual == NULL)
        return 0; /* retorna 0 se não encontrou o valor */
    /* caso tenha encontrado */
    else{
        temporario = atual; /* temporario aponta para o nó encontrado */
        
        if(atual->anterior != NULL)/* caso haja um nó anterior ao enontrado*/
            atual->anterior->proximo = atual->proximo; /* faz o nó anterior apontar para o nó posterior ao encontrado */
        
        if(atual->proximo != NULL) /* caso haja um nó posterior ao enontrado*/
            atual->proximo->anterior = atual->anterior; /* faz o nó posterior apontar para o nó anterior ao encontrado */
        
        free(temporario);/* remove o nó encontrado */
    }
    
    return 1;
}

/* verifica os nos existente dada uma condição */
void verifica(ListaPTR *inicio, int valor, int *recipientes){
    
    ListaPTR atual;
	int i = 0;
    
	atual = *inicio; /* o nó atual é o do início */

	while(atual != NULL){
		if(atual->valor < (valor+1)) {
			recipientes[i] = atual->valor;
			i++;
		}
		atual = atual->proximo; /*passa para o próximo*/
		recipientes[i] = 0;
	}
}

/* deleta um nó apartir do início da lista */
int elimina_no(ListaPTR *inicio){
    
    ListaPTR temporario;
    int c;
    
    temporario = *inicio; /* nó do início passa a ser temporário */
    c = (*inicio)->valor; /* pega o valor que estava no nó */
    *inicio = (*inicio)->proximo; /* o nó seguinte passa a ser o do início */
    free(temporario); /* deleta o nó temporário */
    
    return c;
}

int esta_vazia(ListaPTR lista){
    
    return lista == NULL;
    
}

void imprime_lista_ordem_direta(ListaPTR lista){
     
     if(esta_vazia(lista))
         printf("\n\nA lista esta vazia.\n\n");
     else{
         printf("\nA lista eh:\n\n");
         while(lista != NULL){
             printf(" %d", lista->valor);
             lista = lista->proximo;
         }
     }
}

void imprime_lista_ordem_inversa(ListaPTR lista){
     
     if(esta_vazia(lista))
         printf("\n\nA lista esta vazia.\n\n");
     else{
         while(lista->proximo != NULL) /* enquanto não chegar no último nó ...*/
             lista = lista->proximo;   /* ... percorre a lista */
             
         printf("\nA lista eh:\n\n");
         while(lista != NULL){
             printf(" %d", lista->valor);
             lista = lista->anterior;
         }
         
     }
}

void menu(){
     
     printf("     <------> OPERACOES BASICAS EM UMA LISTA DUPLAMENTE ENCADEADA <------>\n\n");
     printf("\n\n\t\t\t\t  OPCOES\n\n");
     printf("\t\t1 - Inserir um elemento no inicio da lista\n");
     printf("\t\t2 - Inserir um elemento no final da lista\n");
     printf("\t\t3 - Remover um elemento da lista\n");
     printf("\t\t4 - Imprimir a lista na ordem direta\n");
     printf("\t\t5 - Imprimir a lista na ordem inversa\n");
	 printf("\t\t6 - Verifica Valores da Lista\n");
     printf("\t\t7 - sair\n\n");
     
}

int main(){
    
	ListaPTR lista = NULL;
	int opcao, valor, i;
	int recipientes[100];

	menu();
	printf("Escolha uma das opcoes: ");
	scanf("%d", &opcao);

	while(opcao != 7){
		switch(opcao){
			
			case 1:
				printf("\nDigite um caracetere: ");
				scanf("\n%d", &valor);
				insere_no_inicio(&lista, valor);
				system("cls");
				break;
            
            case 2:
                printf("\nDigite um caracetere: ");
                scanf("\n%d", &valor);
                insere_no_final(&lista, valor);
                system("cls");
                break;
            
            case 3:
                printf("\nDigite o valor a ser retirado: ");
                scanf("\n%d", &valor);
                if(! retira(&lista, valor)){
                    printf("\nNo inexistente!\n\n");
                    getch();
                }
                system("cls");
                break;
            
            case 4:
                imprime_lista_ordem_direta(lista);
                getch();
                system("cls");
                break;
            
            case 5:
                imprime_lista_ordem_inversa(lista);
                getch();
                system("cls");
                break;
				 
            case 6:
				i = 0;
				printf("\nDigite o valor do recipiente: ");
				scanf("\n%d", &valor);
				verifica(&lista, valor, recipientes);
				printf("Frascos do labolatorio: ");
				while(recipientes[i] != 0){
				 printf(" %d", recipientes[i]);
				 i++;
				}
				getch();
				system("cls");
				break;
            
            default:
                printf("\nOpcao invalida!!!\n\n");
                getch();
                system("cls");
                break;
        }
        menu();
        printf("Escolha uma das opcoes: ");
        scanf("%d", &opcao);
    }
    while(! esta_vazia(lista)) elimina_no(&lista);
    getch();
    
    return 0;
}