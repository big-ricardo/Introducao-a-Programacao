#include<stdio.h>
#include <stdlib.h>

int main (void){
	double salario;
	double novo_salario;
	double taxa_variacao;
	
	printf("#######Sistema de Aumento#######\n");
	
	printf("Digite o salario:");
	scanf("%lf", &salario);
	
	printf("Digite o percentual de aumento(Ex: 0.5) :");
	scanf("%lf", &taxa_variacao);
	
	taxa_variacao = (salario*taxa_variacao);
	
	novo_salario = salario + taxa_variacao;
	
	printf("Aumento de R$%.2lf \n", taxa_variacao);
	printf("O novo salario e: R$%.2lf \n", novo_salario);
	
	return 1;
}
