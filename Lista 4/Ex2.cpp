#include <stdio.h>
#include <stdlib.h>
#define N_QUESTOES 8
#define N_ALUNOS 10

int main(void) {
  char gabarito[N_QUESTOES];
  char respostas[N_QUESTOES];
  float aprovacao=0, notas[N_ALUNOS];
  int numeros[N_ALUNOS];
  float notas_questao = 10/N_QUESTOES;

  system("clear");
  
  printf("\n######Sistema de Notas######\n");
  printf("\nPreencha o gabarito");

  for(int i=0; i< N_QUESTOES;i++){
    printf("\nQuestao %d:", i+1);
    scanf("%s", & gabarito[i]);
  }

  for(int i=0; i < N_ALUNOS; i++){
    system("clear");
    printf("\n######Sistema de Notas######\n");
    printf("\n Respostas dos Alunos");

    printf("\nNumero do Aluno:");
    scanf("%d", &numeros[i]);

    notas[i] = 0;

    for(int j=0; j <N_QUESTOES; j++){  
      printf("\nQuestao %d:", j+1);
      scanf("%s", &respostas[j]);
    }

    for(int j =0; j< N_QUESTOES; j++){
      if(gabarito[j] == respostas[j]){
        notas[i]+= notas_questao;
      }
    }

  }

  for(int i=0; i < N_ALUNOS; i++){
    if(notas[i] >= 6){
      aprovacao++;
    }
  }

  float taxa_aprovacao = (aprovacao*100)/N_ALUNOS;

  system("clear");
  for(int i=0; i < N_ALUNOS; i++){
    printf("\nAluno %d com a nota: %.2f\n", numeros[i], notas[i]); 
  }

  printf("\nTaxa de Aprovacao: %.2f por cento\n", taxa_aprovacao);

}
