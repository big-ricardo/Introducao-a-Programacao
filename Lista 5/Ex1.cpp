#include <stdio.h>
#include <stdlib.h>

int main(void) {
  
  int M[2][2], maior = 0;

  printf("\n######Sistema de Matrizes######\n");

  for(int i=0; i<2;i++){
    for(int j=0; j<2;j++){
      printf("\nDigite um numero intero:");
      scanf("%d", &M[i][j]);

      if(M[i][j] >maior){
        maior = M[i][j];
      }
    }
  }

  printf("Matriz M:\n ");
  for(int i=0; i<2;i++){
    for(int j=0; j<2;j++){
      printf("%d\t", M[i][j]);
    }
    printf("\n");
  }

  printf("\nMatriz R: \n");
  for(int i=0; i<2;i++){
    for(int j=0; j<2;j++){
      printf("%d\t", M[i][j] * maior);
    }
    printf("\n");
  }

  return 0;
}
