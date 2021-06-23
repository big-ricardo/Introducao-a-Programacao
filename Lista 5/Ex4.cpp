#include <stdio.h>
#include <stdlib.h>
#define X 5
#define Y 7

int main(void) {
  
  int M[X][Y];
  int sela, selaY, tst_sela;
  

  for (int i = 0; i < X; i++){

    tst_sela = 0;

    for (int j = 0; j < Y; j++)
    {
        M[i][j] = rand() %60;
        
        printf("%d ", M[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < X; i++){

    for(int j = 0; j < Y; j++){
      if(j == 0) {
          sela = M[i][j];
          selaY = j;
      }
      if(M[i][j] < sela){
        sela = M[i][j];
        selaY = j;
      }
    }

    for(int j = 0; j < X ; j++){
      if(sela < M[j][selaY]){
        tst_sela++;
      }
    }

    if(tst_sela == 0){
      printf("\nPonto de sela valor:%d\n", sela);
      printf("Ponto de posicao:(%d, %d) \n", i, selaY);
    }
  }  

  return 0;

}
