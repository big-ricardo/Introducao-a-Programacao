#include <stdio.h>
#include<stdlib.h>

int main(void) {
  
	int cont;
	cont = 1;
	
	printf("\n######Sistema de Contagem######\n");
	
	printf("\n\nOs numeros de 1 ate 20:\n");
  	while(cont <=20){
    	printf(" %d  ", cont);
    	cont++;
	}
	
	printf("\n\nOs numeros de 20 ate 1:\n");
	cont = 20;
  	while(cont >= 1){
    	printf(" %d  ", cont);
    	cont--;
	}
	
	printf("\n\nSomente os numeros ímpares de 1 a 20:\n");
	cont = 1;
  	while(cont <= 20){
    	if(cont % 2 != 0){
    		printf(" %d  ", cont);
		}
    	cont++;
	}
  	
  	return 0;
}
