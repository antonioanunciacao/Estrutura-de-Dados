#include <cstdio> // em C substituir por #include <stdio.h>
#include "foo.h"



enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun}; 
  
int main() 
{ 
    enum week day; 
    day = Wed; 
    printf("%d",day); 
    return 0; 
}  

int main() {
  int q;
  char e;
  while(scanf("%d %c", &q, &e) != EOF) {
    if (e == 'p')
      // veja que a funcao bar() sempre retorna 1, entao o programa sempre
      // vai imprimir 1.
      // Troque essa funcao (inclusive o nome dela) caso queira tirar uma nota
      // melhor no TP!
      printf("%d\n", bar());
  }
  return 0;
}

