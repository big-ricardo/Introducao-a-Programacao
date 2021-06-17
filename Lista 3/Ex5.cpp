#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int n1,n2;
	
	printf("\n######Sistema de Tabuada######\n\n");
	
	do{
		printf("1. Digite um número inteiro positivo:");
  		scanf("%d", &n1);
	}while(n1 < 0);
	
	do{
		printf("2. Digite um número inteiro positivo:");
  		scanf("%d", &n2);
	}while(n2 < 0 && n1 < n2);
	
		printf("\n");
		
		for(int i=0; i <= 10; i++){
		 for(int j=n1; j <= n2; j++){
			printf("%d x %d = %d\t", j,i, i*j);
		}
		printf("\n");
	}
  	
}
