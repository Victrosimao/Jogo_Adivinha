#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Fun��o para iniciar o n�mero secreto com base no tempo
void iniciar_numero_secreto(int *numero_secreto) {
    int segundos = time(0);
    srand(segundos);
    int numero_grande = rand();
    *numero_secreto = numero_grande % 100;
}

// Fun��o para perguntar o n�vel de dificuldade ao usu�rio
int obter_nivel() {
    int nivel;
    printf("Qual o n�vel de dificuldade?\n");
    printf("1- F�cil 2- M�dio 3- D�ficil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    return nivel;
}

// Fun��o para obter o n�mero de tentativas baseado no n�vel
int numero_tentativas(int nivel) {
    if (nivel == 1) {
        return 25;
    } else if (nivel == 2) {
        return 15;
    } else {
        return 5;
    }
}

// Fun��o para executar o jogo
void jogar(int numero_secreto, int tentativas_max) {
    int tentativas = 1;
    double pontos = 1000;

    printf("\nOl�, esse � um jogo de adivinha��o. Tente adivinhar o n�mero que o computador est� pensando.\n\n");
    printf("BOA SORTE! \n");

    for (int i = 1; i <= tentativas_max; i++) {
        int chute;
        printf("Tentativa %d\n\n", tentativas);
        printf("Qual � o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if (chute < 0) {
            printf("Voc� n�o pode chutar n�meros negativos.\n\n");
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
            printf("Parab�ns! Voc� acertou em %d tentativas!!\n\n", tentativas);
            printf("Total de pontos: %.1f\n", pontos);
            printf("\nFim de jogo!\n");
            return;
        } else {
            if (chute > numero_secreto) {
                printf("Seu chute foi maior que o n�mero secreto\n\n");
            } else {
                printf("Seu chute foi menor que o n�mero secreto\n\n");
            }

            tentativas++;
            double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
            pontos -= pontos_perdidos;
        }
    }

    printf("\nVoc� atingiu o n�mero m�ximo de tentativas.\n");
    printf("O n�mero secreto era %d.\n", numero_secreto);
    printf("Fim de jogo!\n");
}

int main() {
    int numero_secreto;
    setlocale (LC_ALL, "Portuguese_Brazil");

  printf("                        /|  /|  ---------------------------    \n");
  printf("                        ||__||  |                         |    \n");
  printf("                       /   O O\\___    Bem vindo ao Jogo   |    \n");
  printf("                     /      \\     \\    de Adivinha��o     |  \n");
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
