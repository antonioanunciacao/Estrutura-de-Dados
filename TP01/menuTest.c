#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void menu(){
	printf("Ola Rick! O que voce quer fazer?\n\n");
    printf("\n\tOPCOES:\n");
    printf("\t\ti - Incluir Recipeiente novo :)\n");
    printf("\t\tr - Remover Recipiente quebrado :(\n");
    printf("\t\tp - Fazer uma medicao :o\n");
    printf("\t\ts - sair\n\n");
     
}

int convert(char opcao){
	if(opcao == 'i') return 0;
	else if(opcao == 'r') return 1;
	else if(opcao == 'p') return 2;
	else if(opcao == 's') return 3;
	else return 4;
}
	
int main(){
	int op;
	char opcao;
	
	menu();
	printf("Escolha uma das opcoes: ");
	scanf("%c", &opcao);
	op = convert(opcao);

	while(op != 3){
		switch(op){
			case 0:
                printf("\nDigite o volume do recipiente: ");
                scanf("\n%d", &valor);
                insere_no_final(&lista, valor);
                system("cls");
                break;
            
            case 1:
                printf("\nDigite o recipiente a ser removido: ");
                scanf("\n%d", &valor);
                if(! retira(&lista, valor)){
                    printf("\nRecipiente nao listado!\n\n");
                    getch();
                }
                system("cls");
                break;
            
            case 2:
                printf("\nDigite o volume a ser medido: ");
                scanf("\n%d", &valor);
                verifica(&lista, valor, recipientes);
				medicao(valor, recipientes);
                system("cls");
                break;
            
            case 3:
				printf("\nSaindo ");
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
        scanf("%c", &opcao);
    }
	printf("\nAte a proxima Rick!\n");
  
    return 0;
}