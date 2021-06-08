#include<stdio.h>
#include <stdlib.h>

int main (void){
	double n1, n2,n3;
	double media = 0;
	
	printf("#######Sistema de Notas#######\n");
	
	printf("Digite a primeira nota:");
	scanf("%lf", &n1);
	
	printf("Digite a segunda nota:");
	scanf("%lf", &n2);
	
	printf("Digite a terceira nota:");
	scanf("%lf", &n3);
	
	media = (n1+n2+n3)/3;
	
	printf("As notas foram %.2lf %.2lf %.2lf \n", n1,n2,n3);
	
	
	printf("A media obtida foi: %.2lf", media);
	
	return 1;
}
