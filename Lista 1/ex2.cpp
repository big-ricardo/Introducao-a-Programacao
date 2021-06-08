#include<stdio.h>
#include <stdlib.h>

int main (void){
	double n1, n2,n3;
	double p1, p2,p3;
	double media = 0;
	
	printf("#######Sistema de Notas#######\n");
	
	printf("Digite a primeira nota:");
	scanf("%lf", &n1);
	printf("Digite  primeiro peso:");
	scanf("%lf", &p1);
	
	printf("Digite a segunda nota:");
	scanf("%lf", &n2);
	printf("Digite o segundo peso:");
	scanf("%lf", &p2);
	
	printf("Digite a terceira nota:");
	scanf("%lf", &n3);
	printf("Digite a terceiro peso:");
	scanf("%lf", &p3);
	
	media = ((n1*p1) + (n2*p2)+ (n3*p3))/(p1+p2+p3);
	
	printf("As notas foram %.2lf %.2lf %.2lf \n", n1,n2,n3);
	printf("As pesos foram %.2lf %.2lf %.2lf \n", p1,p2,p3);
	
	printf("A media obtida foi: %.2lf", media);
	
	return 1;
}
