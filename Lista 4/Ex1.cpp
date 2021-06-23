#include <stdio.h>

int main(void) {
  
  int numeros[8];
  
  for(int i = 0; i<8 ; i++){
    numeros[i] = 0;
  }

  for(int i = 0; i<8 ; i++){  
    printf("\nDigite o numero %d inteiro:", i+1);
    scanf("%d", & numeros[i]);

    for(int j = 0; j< i; j++){
      for(int k=0; k < i-1; k++){

        if(numeros[i] < numeros[j]){
          int aux = numeros[j];
          numeros[j]= numeros[i];
          numeros[i] = aux; 
        }
      }
    }
  }

  printf("Numeros são:\n");

  for(int i = 0; i<8 ; i++){  
    printf("%d\n", numeros[i]);
  }

  return 0;
}
