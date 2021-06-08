#include<stdio.h>
#include <stdlib.h>

int main (void){
	double n1, n2,n3, n4;
	double media = 0;
	
	printf("#######Sistema de Notas#######\n");
	
	printf("Digite a primeira nota:");
	scanf("%lf", &n1);
	
	printf("Digite a segunda nota:");
	scanf("%lf", &n2);
	
	printf("Digite a terceira nota:");
	scanf("%lf", &n3);
	
	printf("Digite a quarta nota:");
	scanf("%lf", &n4);
	
	media = (n1+n2+n3+n4)/4;
	
	if(media >= 6){
		printf("\n  Aluno Aprovado");
	}else{
		printf("\n  Aluno Reprovado");
	}
	
	printf("\nAs notas foram %.2lf %.2lf %.2lf %.2lf \n", n1,n2,n3, n4);
	
	printf("A media obtida foi: %.2lf", media);
	
	return 1;
}
