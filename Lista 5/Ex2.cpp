#include <stdio.h>
#include <stdlib.h>
#define NUMERO 8

int main(void) {
  
  int M[NUMERO][NUMERO];

  printf("\n######Sistema de Matrizes######\n");

  for(int i=0; i<NUMERO;i++){
    for(int j=0; j<NUMERO;j++){
      printf("\nDigite um numero intero:");
      scanf("%d", &M[i][j]);
    }
  }

  for(int i=0; i<NUMERO;i++){
    for(int j=0; j<NUMERO;j++){
      if(M[i][j] != M[j][i]){
        printf("Matriz não é simetrica");

        return 0;
      }
    }
  }

  printf("Matriz é simetrica\n");

  return 0;
}
