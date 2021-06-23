#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  
  char palavra[60], novapalavra[60], a;
  int n;

  printf("\n\n######Sistema de Codificacao\n");

  printf("\nDigite a palavra:");
  scanf("%s", palavra);

  printf("\nDigite o N:");
  scanf("%d", &n);

  for(int i=0; i < strlen(palavra); i++){
    novapalavra[i] = palavra[i] + n;
  }

  system("clear");
  printf("\n\n######Sistema de Codificacao\n");

  printf("\nN: %d", n);
  printf("\nString: %s", palavra);
  printf("\nNova String: %s\n\n", novapalavra);
}
