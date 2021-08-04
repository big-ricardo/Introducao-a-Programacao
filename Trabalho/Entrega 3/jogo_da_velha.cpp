#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define POSICOES_PLACAR 10

//struct para retornar os movimentos do bot
struct Move
{
  int linha, coluna;
};
// struct do placar
struct Placar
{
  int vitorias, derrotas, velhas;
};

//struct de dados do usuario
struct Jogador 
{
  char nome[20];
  int pontuacao;
  int peca;
};

//Aqui inicia a apresentação do MENU inicial do jogo
int main(void) {
  //Declara as funções que iniciam as operações
  int jogoInit();
  int rankingInit();

  int valor;

  //Loop do painel principal
  do{ 
    system("clear"); 

    printf("\n------ Jogo da Velha em C ------\n\n");
    printf("1. Jogar \n");
    printf("2. Ranking \n");
    printf("3. Sair\n");

    printf("\nEscolha uma opção:");
    scanf("%d", & valor);

    //Analisa a opção do usuario, caso seja valida chama a função correspondente, senão apresenta o painel novamente 
    switch(valor){
      case 1:
        jogoInit();
      case 2:
        rankingInit();
        break;
    }

  }while(valor != 3);

  system("clear"); 

  return 0;
}

//Inicia o Loop do Jogo e inicia todas as variaveis necessarias
int jogoInit(){
  
  void dadosUsuario(struct Jogador *, struct Placar *);
  void mostrarUsuario(struct Jogador *);
  void redefinirTabuleiro(int a[3][3]);
  void rodadaInit(int (*tabuleiro)[3], int, struct Placar *);
  void inserirRanking(struct Jogador);
  
  int calculaPontuacao(struct Placar);

  int tabuleiro[3][3];  //Variavel responsavel pelo tabuleiro
  int valor; //Pegar valor digitado no menu do usuario 
  struct Jogador jogador;
  struct Placar placar;

  //Chama a funcao para preencher dados do usuario
  dadosUsuario(&jogador, &placar);
  
  //Loop para do jogo, onde vai executando as rodadas até jogador desejar sair
  do{ 
    system("clear");

    redefinirTabuleiro(tabuleiro);

    //Inicia o loop das rodadas 
    rodadaInit(tabuleiro, jogador.peca, &placar);

    jogador.pontuacao = calculaPontuacao(placar);
    mostrarUsuario(&jogador);

    printf("\n\n1. Continuar \n\n");
    printf("2. Sair\n");

    printf("\nEscolha uma opção (digite o numero):");
    scanf("%d", & valor);

  }while(valor != 2); 

  inserirRanking(jogador);

  return 0;
}

//Pega os dados do usuario
void dadosUsuario(struct Jogador *jogador, struct Placar *placar){
  int valor;
  system("clear"); 

  printf("--------------------------------");
  printf("\nBem vindo ao jogo da velha em C \n");
  printf("--------------------------------\n");

  printf("\nQual seu nome:");
  scanf("%s", (*jogador).nome);

  do{ 
    printf("\nEscolha entre(Insira o numero):");
    printf("\n1. X \n");
    printf("2. O\n");

    printf("\nEscolha uma opção:");
    scanf("%d", & valor);

     //Analisa a opção do usuario, caso seja valida, senão apresenta o painel novamente 
    switch(valor){
      case 1:
        (*jogador).peca = 1;
        break;
      case 2:
         (*jogador).peca = -1;
        break;
    }
  }while(valor > 2 || valor <=0); 

  //inicializa os placares em 0
  (*placar).velhas = 0;
  (*placar).derrotas = 0;
  (*placar).vitorias = 0;

}

//Executa o loop das jogadas no tabuleiro
void rodadaInit(int tabuleiro[3][3], int jogador, struct Placar *placar){

  void desenharTabuleiro(int (*tabuleiro)[3]);
  void rodadaJogador(int (*tabuleiro)[3], int);
  void mostrarPlacar(struct Placar placar);

  int existemPossibilidades(int (*tabuleiro)[3]);
  int verificaVencedor(int (*tabuleiro)[3], int);
  
  void jogadaBot(int (*tabuleiro)[3], int);

  int bot = jogador == 1?-1:1; //Define qual será a peca do bot a partir da escolha do jogador
  int vez = rand()%3 + jogador; //Define quem irá começar a jogar

  int vencedor = 0;

  //Loop para as jogadas
  while(existemPossibilidades(tabuleiro)){
    system("clear"); 
    mostrarPlacar(*placar);
    desenharTabuleiro(tabuleiro);
    int rodada = 0;

    if(vez % 2 == 0){
      //jogada do usuario
      printf("\n\nSua Vez!");
      rodadaJogador(tabuleiro, jogador);
      rodada = jogador;
    }else{
      // jogada do bot
      printf("\n");
      jogadaBot(tabuleiro, bot);
      rodada = bot;
    }

    vez++;

    // caso houver vencedor
    if(verificaVencedor(tabuleiro, rodada)){
      system("clear");

      if(rodada == jogador){
        printf("\nParabens voce ganhou\n\n");
        vencedor = 1;
        (*placar).vitorias++;
      }else{
         printf("Ixi voce perdeu\n");
         vencedor = 1;
         (*placar).derrotas++;
      }
      break;
    }
  }

  if(!vencedor){
    system("clear");
    printf("\n Deu Velha \n\n");
    (*placar).velhas++;
  } 

  desenharTabuleiro(tabuleiro);
  mostrarPlacar(*placar);
}

//Inicia a Visualização do Ranking, fazendo a leitura do arquivo e apresentando ao usuario
int rankingInit(){
  
  void ordenarVetor(struct Jogador *jogadores, int);
  int mostrarUsuarioRanking(struct Jogador);

  int sair;
  struct Jogador jogadores[POSICOES_PLACAR]; //Array de jogadores do Placar

  //variaveis auxiliares
  char nome[20];
  int pontuacao;
  int ranking_total = 0;

  system("clear");
  printf("---------- Ranking ----------");

  //ponteiro do arquivo
  FILE *arquivo;

  //abrindo o arquivo somente para leitura
  arquivo = fopen("placar.txt", "r");
  
  //caso tiver um erro na abertura do arquivo ele não executa as operações
  if(arquivo == NULL){
      printf("\nErro ao abrir o arquivo!\n");
  }else{

    //enquanto não for fim de arquivo o looping será executado
    //e será impresso o texto
    while(fscanf(arquivo, "%s %d", nome, &pontuacao)!=EOF){
      // strcpy(nomes[ranking_total], nome);
      strcpy(jogadores[ranking_total].nome, nome);
      jogadores[ranking_total].pontuacao = pontuacao;
      ranking_total++;
    }
    //fecha o arquivo
    fclose(arquivo);

    // testa existem pessoas no ranking e ordena para apresenta-lo
    if(ranking_total>0){
      ordenarVetor(jogadores, ranking_total);
      for(int i=0; i < ranking_total + 1; i++){
        //Fazer a apresentação no terminal
        mostrarUsuarioRanking(jogadores[i]);
      }
    }
  }

  //apenas para travar o loop
  printf("\n\nSelecione 1 para voltar:");
  scanf("%d", &sair);  

  return 0;
}

//Fazer a ordenação dos ranking
void ordenarVetor(struct Jogador jogadores[POSICOES_PLACAR], int ranking_total){
  int status;
  do{
    status = 0;
    for(int i=ranking_total; i>0; i--){
      if(jogadores[i].pontuacao> jogadores[i-1].pontuacao){
        struct Jogador aux;
        aux = jogadores[i];
        jogadores[i] = jogadores[i-1];
        jogadores[i-1] = aux;
        status = 1;
      }
    }
  }while(status);
}

//Adicionar Jogador ao arquivo de ranking
void inserirRanking(struct Jogador jogador){

  FILE *arquivo;
  //abrindo o arquivo
  arquivo = fopen("placar.txt", "a");

  //salvando dados no aquivo
  fprintf(arquivo, "\n%s %d", jogador.nome, jogador.pontuacao);

  //fechando o arquivo
  fclose(arquivo);
}

//Apresenta os dados do usuario
void mostrarUsuario(struct Jogador *jogador){
  printf("\n---------------------------");
  printf("\nNome: %s \t", (*jogador).nome);
  printf("Pontuacao: %d\n", (*jogador).pontuacao);

}

//Apresenta os dados do usuario
int mostrarUsuarioRanking(struct Jogador jogador){
  
  for(int i = 0; i < strlen(jogador.nome); i++){
    if((jogador.nome[i] < 'a' && jogador.nome[i] > 'z') || (jogador.nome[i] < 'A' && jogador.nome[i] > 'Z') ||  
    (jogador.pontuacao > 10000) || (jogador.pontuacao < 0)){
      return 0;
    }
  }

  printf("\n\n%s \t", jogador.nome);
  printf("%d\n", jogador.pontuacao);
  printf("-----------------------------");

  return 1;
}

//Apresenta o placar
void mostrarPlacar(struct Placar placar){

  printf("\n| Voce || velha || Bot |\n");
  printf("|   %d  ||   %d   ||  %d  | \n\n", placar.vitorias, placar.velhas, placar.derrotas);
}

//Recebe o placar e faz o calculo da sua pontuacao
int calculaPontuacao(struct Placar placar){
  int pontuacao = 0;

  int vitorias = placar.vitorias * 3;
  int derrotas = placar.derrotas * 2;
  int empates = placar.velhas;

  pontuacao = ((vitorias + empates)-derrotas);

  //Caso a pontuacao seja menor que 0, será retornado o valor 0
  return pontuacao > 0 ? pontuacao : 0;
}

//recebe e testa as jogadas do usuario para efetuala
void rodadaJogador(int tabuleiro[3][3], int jogador){
  int verificaJogada(int (*tab)[3], int, int);
  void efetuarJogada(int (*tab)[3],int, int, int);
  
  int linha, coluna;

  //Loop o usuario definir uma jogada correta
  do{

    printf("\nInsira a Linha que deseja jogar:");
    scanf("%d", &linha); 

    printf("\nInsira a Coluna que deseja jogar:");
    scanf("%d", &coluna);

  }while(!verificaJogada(tabuleiro, linha-1, coluna-1));
  efetuarJogada(tabuleiro, linha-1, coluna-1, jogador);
}

//Desenhar o tabuleiro 
void desenharTabuleiro(int tabuleiro[3][3]){
  char converteNumero(int);
  int tabuleiroChar[3][3];

  for(int i = 0; i <3; i++){
    printf("\n  %d", i+1);
     printf("\t ");
    for(int j = 0; j<3; j++){
      tabuleiroChar[i][j] = converteNumero(tabuleiro[i][j]);
      if(j < 2){
        printf("  %c |", tabuleiroChar[i][j]);
      }else{
        printf(" %c  ", tabuleiroChar[i][j]);
      }
    }
    if(i<2){
      printf("\n\t  ------------");
    }
  } 
  printf("\n\n\t   1    2   3 \n");
}

//Recebe tabuleiro, e altera seus valores em nulo
void redefinirTabuleiro(int tab[3][3]){
  for(int i = 0; i <3; i++){
    for(int j = 0; j<3; j++){
      tab[i][j] = 0;
    }
  }
}

//Recebe um numero e converte em seu respectivo caracter
char converteNumero(int valor){
  if(valor == 0){
    return ' ';
  }else{
    if(valor == 1){
      return 'X';
    }else{
      if(valor == -1){
        return 'O';
      }
    }
  }
  return ' ';
} 

//Efetuar jogada no tabuleiro
void efetuarJogada(int tabuleiro[3][3], int linha, int coluna, int jogador){
  tabuleiro[linha][coluna] = jogador;
}

//Recebe a jogada e verifica se esta disponivel, sendo 1 ou 0
int verificaJogada(int tab[3][3], int x, int y) {
  if(x >= 0 && y >= 0 && x <= 3 && y<= 3){
    if(tab[x][y] == 0){
       return 1;
    }
  }
  return 0;
}

//Verifica se existe um vencedor
int verificaVencedor(int tabuleiro[3][3], int jogador){
  
   // Verificando as linhas para a vitória.
   if (tabuleiro[0][0]==jogador 
      && tabuleiro[0][1]==jogador 
      && tabuleiro[0][2]==jogador) {
      printf("\nLinha 1\n");
    return 1 ;
  }
  if (tabuleiro[1][0]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[1][2]==jogador) {
        printf("\nLinha 2\n");
    return 1 ;
  }
  if (tabuleiro[2][0]==jogador 
      && tabuleiro[2][1]==jogador 
      && tabuleiro[2][2]==jogador) {
        printf("\nLinha 3\n");
    return 1 ;
  }
  if (tabuleiro[0][0]==jogador 
      && tabuleiro[1][0]==jogador 
      && tabuleiro[2][0]==jogador) {
        printf("\nColuna 1\n");
    return 1 ;
  } 
   // Verificando as ncolunas para a vitória.
  if (tabuleiro[0][1]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[2][1]==jogador) {
        printf("\nColuna 2\n");
    return 1 ;
  } 
  if (tabuleiro[0][2]==jogador 
      && tabuleiro[1][2]==jogador 
      && tabuleiro[2][2]==jogador) {
        printf("\nColuna 3\n");
    return 1 ;
  }
   // Verificando as diagonais para a vitória.
  if (tabuleiro[0][0]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[2][2]==jogador) {
        printf("\nDiagonal principal\n");
    return 1 ;
  }
  if (tabuleiro[0][2]==jogador 
      && tabuleiro[1][1]==jogador 
      && tabuleiro[2][0]==jogador) { 
        printf("\nDiagonal secundaria\n");
    return 1 ;
  }   

  return 0; //Caso não tenha vencedor, retorna 0
}

// Esta função retorna verdadeiro se houver movimentos
// no tabuleiro. Retorna 0 se
// não há mais movimentos para jogar.
int existemPossibilidades(int tabuleiro[3][3])
{
  for (int i = 0; i<3; i++)
      for (int j = 0; j<3; j++)
          if (tabuleiro[i][j]== 0)
              return 1;
  return 0;
}

//Codigo referente a analise do Bot

//Responsavel por receber o tabuleiro, analisar e efetuar a jogada do bot
void jogadaBot(int tabuleiro[3][3], int bot)
{
  struct Move movimentoBot(int a[3][3], int);
  void efetuarJogada(int (*tabuleiro)[3], int linha, int coluna, int jogador);

  struct Move jogadaBot = movimentoBot(tabuleiro, bot);

  efetuarJogada(tabuleiro, jogadaBot.linha, jogadaBot.coluna, bot);
} 
 
// Considera alguns dos caminhos possíveis que o jogo pode seguir
int minimax(int tabuleiro[3][3], int isMax, int jogador){
  int avaliaJogada(int (*tabuleiro)[3], int);

  int pontuacaoJogada = avaliaJogada(tabuleiro, jogador);

  // Se o Maximizer ganhou o jogo, devolva o seu
  // pontuação avaliada
  if (pontuacaoJogada == 10){
    return pontuacaoJogada;
  }  
  // Se o Minimizer ganhou o jogo, devolva o seu
  // pontuação avaliada
  if (pontuacaoJogada == -10){
    return pontuacaoJogada;
  }

  if (existemPossibilidades(tabuleiro)){
    return 0;
  }
  // Se não houver mais movimentos e nenhum vencedor, então
  // é um empate

  if (isMax == 1)
  {
      int melhor = -1000;

      // Percorre todas as células
      for (int i = 0; i<3; i++)
      {
          for (int j = 0; j<3; j++)
          {
              // Verifique se a célula está vazia
              if (tabuleiro[i][j]== 0)
              {
                  // Faça o movimento
                  tabuleiro[i][j] = jogador;

                  // Chame minimax recursivamente e escolunaha
                  // o valor máximo
                  melhor =  minimax(tabuleiro, !isMax, jogador);

                  // Desfaz o movimento
                  tabuleiro[i][j] =  0;
              }
          }
      }
      return melhor;
  }

  // Se este minimizador se mover
  else
  {
      int melhor = 1000;

      // Percorre todas as células
      for (int i = 0; i<3; i++)
      {
          for (int j = 0; j<3; j++)
          {
            // Verifique se a célula está vazia
              if (tabuleiro[i][j]== 0)
              {
                  // Make the move
                  tabuleiro[i][j] = jogador == 1 ? -1: 1;
                  // Chame minimax recursivamente e escolunaha
                  // o valor mínimo
                  melhor =  minimax(tabuleiro, !isMax, jogador);

                  tabuleiro[i][j] =  0;
              }
          }
      }
      return melhor;
  }
}

//Esse função avalia se a jogada irá resultar chances de vitoria ou derrota 
int avaliaJogada(int tabuleiro[3][3], int jogador)
{
  // Verificando as linhas para a vitória de X ou O.
  for (int linha = 0; linha<3; linha++)
  {
      if (tabuleiro[linha][0]==tabuleiro[linha][1] &&
          tabuleiro[linha][1]==tabuleiro[linha][2] && tabuleiro[linha][2]!=0)
      {
          if (tabuleiro[linha][0]==jogador)
              return +10;
          else 
              return -10;
      }
  }

  // Verificando colunas nas para vitória de X ou O.
  for (int coluna = 0; coluna<3; coluna++)
  {
      if (tabuleiro[0][coluna]==tabuleiro[1][coluna] &&
          tabuleiro[1][coluna]==tabuleiro[2][coluna] && tabuleiro[2][coluna]!=0)
      {
          if (tabuleiro[0][coluna]==jogador)
              return +10;
          else
              return -10;
      }
  }

  // Verificando as diagonais para a vitória de X ou O.
  if (tabuleiro[0][0]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][2] && tabuleiro[2][2]!=0)
  {
      if (tabuleiro[0][0]==jogador)
          return +10;
      else 
          return -10;
  }

  if (tabuleiro[0][2]==tabuleiro[1][1] && tabuleiro[1][1]==tabuleiro[2][0] !=0)
  {
      if (tabuleiro[0][2]==jogador)
          return +10;
      else 
          return -10;
  }

  // Do contrário, se nenhum deles ganhou, retorna 0
  return 0;
}

// Isso retornará o melhor movimento para o bot
struct Move movimentoBot(int tabuleiro[3][3], int jogador)
{
  int verificaJogada(int (*tab)[3], int, int);

  int pontuacaoJogada = -1000;
  struct Move melhorMovimento;
  melhorMovimento.linha = -1;
  melhorMovimento.coluna = -1;

  // Percorre todas as células, avalia a função minimax para
  // todas as células vazias. E retornar o celular com ótimo
  // valor.
  for (int i = 0; i<3; i++)
  {
      for (int j = 0; j<3; j++)
      {
          // Verifique se a célula está vazia
          if (tabuleiro[i][j]== 0)
          {
              // Make the move
              tabuleiro[i][j] = jogador;
              // computar função de avaliação para este
              // mover.
              int moveVal = minimax(tabuleiro, 0, jogador);

              // Desfaz o movimento
              tabuleiro[i][j] =  0;

              // Se o valor do movimento atual for
              // mais do que o melhor valor, então atualize
              // melhor/
              if (moveVal > pontuacaoJogada)
              {
                  melhorMovimento.linha = i;
                  melhorMovimento.coluna = j;
                  pontuacaoJogada = moveVal;
              }
          }
      }
  }

  //Caso não tenha uma melhor jogada, sera definido uma posição aleatoria
  if(pontuacaoJogada == 0){
    do{
      melhorMovimento.linha = rand()%3;
      melhorMovimento.coluna = rand()%3;
    }while(!verificaJogada(tabuleiro, melhorMovimento.linha,melhorMovimento.coluna));
  }

  return melhorMovimento;
}
