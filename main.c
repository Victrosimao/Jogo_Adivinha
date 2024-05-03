#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para iniciar o número secreto com base no tempo
void iniciar_numero_secreto(int *numero_secreto) {
    int segundos = time(0);
    srand(segundos);
    int numero_grande = rand();
    *numero_secreto = numero_grande % 100;
}

// Função para perguntar o nível de dificuldade ao usuário
int obter_nivel() {
    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("1- Fácil 2- Médio 3- Díficil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    return nivel;
}

// Função para obter o número de tentativas baseado no nível
int numero_tentativas(int nivel) {
    if (nivel == 1) {
        return 25;
    } else if (nivel == 2) {
        return 15;
    } else {
        return 5;
    }
}

// Função para executar o jogo
void jogar(int numero_secreto, int tentativas_max) {
    int tentativas = 1;
    double pontos = 1000;

    printf("\nOlá, esse é um jogo de adivinhação. Tente adivinhar o número que o computador está pensando.\n\n");
    printf("BOA SORTE! \n");

    for (int i = 1; i <= tentativas_max; i++) {
        int chute;
        printf("Tentativa %d\n\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0) {
            printf("Você não pode chutar números negativos.\n\n");
            continue;
        }

        int acertou = (chute == numero_secreto);
        if (acertou) {

          printf("\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");
          printf("       ( (  ) )    \n");
          printf("        \\ || /     \n");
          printf("          ||      \n");
          printf("         [__]     \n");
          printf("        /)  (\\   \n");
          printf("       (( () ))   \n");
          printf("        \\\\__//  \n");
          printf("         `..'     \n");
          printf("          ||      \n");
          printf("          ||      \n");
          printf("         //\\\\__ \n");
          printf("        ((  `--'  \n");
          printf("         \\)      \n");
          printf("\n->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n");
            printf("Parabéns! Você acertou em %d tentativas!!\n\n", tentativas);
            printf("Total de pontos: %.1f\n", pontos);
            printf("\nFim de jogo!\n");
            return;
        } else {
            if (chute > numero_secreto) {
                printf("Seu chute foi maior que o número secreto\n\n");
            } else {
                printf("Seu chute foi menor que o número secreto\n\n");
            }

            tentativas++;
            double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
            pontos -= pontos_perdidos;
        }
    }

    printf("\nVocê atingiu o número máximo de tentativas.\n");
    printf("O número secreto era %d.\n", numero_secreto);
    printf("Fim de jogo!\n");
}

int main() {
    int numero_secreto;
    setlocale (LC_ALL, "Portuguese_Brazil");

  printf("                        /|  /|  ---------------------------    \n");
  printf("                        ||__||  |                         |    \n");
  printf("                       /   O O\\___    Bem vindo ao Jogo   |    \n");
  printf("                     /      \\     \\    de Adivinhação     |  \n");
  printf("                    /   _    \\     \\ ----------------------   \n");
  printf("                   /    |\\____\\     \\      ||               \n");
  printf("                  /     | | | |\\____/      ||                 \n");
  printf("                 /       \\| | | |/ |     __||                 \n");
  printf("                /  /  \\   -------  |_____| ||                 \n");
  printf("               /   |   |           |       --|                 \n");
  printf("               |   |   |           |_____  --|                 \n");
  printf("               |  |_|_|_|          |     \\----                \n");
  printf("               /\\                  |                          \n");
  printf("              / /\\        |        /                          \n");
  printf("             / /  |       |       |                            \n");
  printf("         ___/ /   |       |       |                            \n");
  printf("        |____/    c_c_c_C/ \\C_c_c_c                           \n");
  printf("\n\n");
  printf("->->->->->->->->->->->->->->->->->->->->->->->->->->->->->->\n\n");

    iniciar_numero_secreto(&numero_secreto);

    int nivel = obter_nivel();
    int tentativas_max = numero_tentativas(nivel);

    jogar(numero_secreto, tentativas_max);

    return 0;
}
