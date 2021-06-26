#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
  
  char palavra[60], novapalavra[60], a;
  int n;

  printf("\n\n######Sistema de Codificacao\n");

  printf("\nDigite a palavra:");
  scanf("%s", palavra);

  printf("\nDigite o N:");
  scanf("%d", &n);


  for(int i=0; i < strlen(palavra); i++){
    palavra[i]= tolower(palavra[i]);
    char aux = palavra[i] + n;
   
    if(aux >= 'a' && aux <= 'z'){
         novapalavra[i] = aux;
    
    }else{
      aux = palavra[i];

      for(int j = 1; j <= n; j++){
        aux++;
        if((aux < 'a' || aux > 'z')){
          aux= 'a';
        }
      }
      novapalavra[i] = aux;
    }
  }

  // system("clear");
  printf("\n\n######Sistema de Codificacao\n");

  printf("\nN: %d", n);
  printf("\nString: %s", palavra);
  printf("\nNova String: %s\n\n", novapalavra);
}
