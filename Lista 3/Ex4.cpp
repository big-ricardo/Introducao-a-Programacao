#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int numero;
	
	printf("\n######Sistema de Piramides######\n\n");
	
	do{
		printf("Digite um número inteiro maior ou igual a 2:");
  		scanf("%d", &numero);
	}while(numero <2);
	
	for(int i=0; i <= numero; i++){
		for(int j=0; j< i; j++){
			printf("#");
		}
		printf("\n");
	}
  	
}
