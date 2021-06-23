#include <stdio.h>

int main(void) {
  
  int sorteado[20], frequencia[20];

  printf("#####Sistema de Sorteio######");

  for(int i=0; i< 20; i++){
    printf("\n Digite o numero %d sorteado:", i+1);
    scanf("%d", & sorteado[i]);
  }

  for(int i=0; i< 20; i++){
    frequencia[i] = 1;
  }

  for(int i=0; i< 20; i++){
    for(int j=0; j<20; j++){
      if(sorteado[i] == sorteado[j]){
        if(i != j){
          frequencia[i]++;
        }
      }
    }
  }

  for(int i=0; i< 20; i++){
    printf("\n Numero sorteado %d, %d vezes", sorteado[i], frequencia[i]);
  }

}
