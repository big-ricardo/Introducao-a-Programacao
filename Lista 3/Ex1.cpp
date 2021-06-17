#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void){
	
	int x;
	
  printf("\n#######Sistema de Potenciacao######\n\n");

	printf("Insira um numero inteiro positivo x:");
	scanf("%d",&x);
	
	printf("\nO resultado das potencias de x, de 0 ate 10 e:");
	for(int i=0; i<=10; i++){
		printf(" %.0f  ", pow(x,i));
	}
  printf("\n");

  printf("\nO resultado das potencias de 10, de 0 até x e:");
	for(int i=0; i<=x; i++){
		printf(" %.0f  ", pow(10,i));
	}
  printf("\n");
	
	return 0;
}
