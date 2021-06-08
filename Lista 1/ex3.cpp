#include<stdio.h>
#include <stdlib.h>

int main (void){
	double salario;
	double novo_salario;
	double taxa_variacao = 0.25;
	
	printf("#######Sistema de Aumento#######\n");
	
	printf("Digite o salario:");
	scanf("%lf", &salario);
	
	novo_salario = (salario + (salario*taxa_variacao)) ;
	
	printf("O novo salario e R$%.2lf \n", novo_salario);
	
	return 1;
}
