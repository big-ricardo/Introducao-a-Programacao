#include<stdio.h>
#include <stdlib.h>

int main (void){
	double salario;
	double novo_salario;
	double calcular_aumento(double,double);
	
	printf("#######Sistema de Aumento#######\n");
	
	printf("Digite o salario:");
	scanf("%lf", &salario);
	
	if(salario <= 1000){
		novo_salario = calcular_aumento(salario, 0.15);
	}else{
		if(salario > 1000 && salario <2000){
			novo_salario = calcular_aumento(salario, 0.1);
		}else{
			if(salario >= 2000){
				novo_salario = calcular_aumento(salario, 0.05);
			}else{
				printf("Salario R$%.2lf  invalido!\n", salario);
			}
		}
	}
	
	printf("O novo salario e: R$%.2lf \n", novo_salario);
	
	return 1;
}

double calcular_aumento(double salario, double taxa_variacao){
	taxa_variacao = (salario*taxa_variacao);
	
	return salario + taxa_variacao;
}
