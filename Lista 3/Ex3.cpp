#include <stdio.h>
#include<stdlib.h>

int main(void) {
	
	int numero, maior, menor, cont;
	
	cont = 0;
	maior = 0;
	menor = 0;
	
	printf("\n######Sistema de Numeros######");
	
	do{
		printf("\nDigite um numero inteiro:");
		scanf("%d", &numero);
		if(numero > maior && cont != 0){
			maior = numero;
		}else{
			if(numero < menor && numero >= 0 && cont != 0){
				menor = numero;
			}else{
				if(numero > 0){
					maior = numero;
					menor = numero;	
				}
			}
		}
		cont++;
	}while(numero >= 0);
	
	printf("\nO maior numero digitado foi: %d", maior);
	printf("\nO menor numero digitado foi: %d\n", menor);
	
	return 0;
}
