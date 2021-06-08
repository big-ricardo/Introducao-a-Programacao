#include<stdio.h>
#include <stdlib.h>

int main (void){
	double n1,n2,n3;
	double maior = 0,menor = 0;
	
	printf("#######Sistema de Ordenação#######\n");
	
	printf("Digite o primeiro numero:");
	scanf("%lf", &n1);
	
	printf("Digite o primeiro numero:");
	scanf("%lf", &n2);
	
	if(n1 >= n2){
		maior = n1;
		menor = n2;
	}else{
		maior = n2;
		menor =n1;
	}
	
	printf("Digite o primeiro numero:");
	scanf("%lf", &n3);
	
	if(n3 > maior){
		maior = n3;
	}else{
		if(n3 < menor){
			menor = n3;
		}
	}
	
	printf("O maior numero: %.1lf", maior);
	printf("\nO menor numero: %.1lf", menor);
	
	return 1;
}
