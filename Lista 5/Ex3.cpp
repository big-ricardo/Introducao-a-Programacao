#include <stdio.h>
#include <stdlib.h>
#define X 4
#define Y 7

int main(void) {
  
  float M[X][Y], minMax = 0; 
  int  menor=0, menorX, menorY = 0;

   for (int i = 0; i < X; i++)
    {
        printf("\t");
        for (int j = 0; j < Y; j++)
        {
            M[i][j] = rand() %9;
            if(i==0 && j==0){
                menor = M[i][j];
            }else if(M[i][j]<menor){
                menor = M[i][j];
                menorX = i;
            }
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < Y; i++)
    {
        if(M[menorX][i]>minMax){
            minMax = M[menorX][i];
            menorY = i;
        }
    }
    printf("\nMINMAX: %.2f \n", minMax);
    printf("\nPosicao: (%d,%d) \n", menorX, menorY);

}
