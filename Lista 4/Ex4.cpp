#include <stdio.h>

int main(void) {
 
  char palavra[10];

   printf("\n #######Sistema Inverter Palavra######\n\n");

  printf("Insira uma palavra:");
  scanf("%s", palavra);

  for(int i = 10; i >=0; i--){
    printf("%c", palavra[i]);
  }

  printf("\n");

}
