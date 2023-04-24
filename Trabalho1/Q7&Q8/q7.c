#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
char jogador = 'X';
int num_jogadas = 0;


void imprimir_tabuleiro()
{
    system("cls");
    printf("\n");
    printf(" %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}


int verificar_vencedor(char p)
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        if ((tabuleiro[i][0] == p) && (tabuleiro[i][1] == p) && (tabuleiro[i][2] == p))
            return 1;
    }

    for(j = 0; j < 3; j++)
    {
        if ((tabuleiro[0][j] == p) && (tabuleiro[1][j] == p) && (tabuleiro[2][j] == p))
            return 1;
    }

    if((tabuleiro[0][0] == p) && (tabuleiro[1][1] == p) && (tabuleiro[2][2] == p))
        return 1;

    if((tabuleiro[0][2] == p) && (tabuleiro[1][1] == p) && (tabuleiro[2][0] == p))
        return 1;

    return 0;
}

int verificar_empate()
{
    if(num_jogadas == 9)
    { 
        return 1;
    }
    return 0;
}

void atualizar_tabuleiro(int linha, int coluna, char p)
{
    tabuleiro[linha][coluna] = p;
    num_jogadas++;
}

void fazer_jogada()
{
    int linha, coluna;
    char jogada[3];

    printf("Jogador %c, informe a posicao: ", jogador);
    scanf("%s", jogada);

    linha = jogada[0] - 'A';
    coluna = jogada[1] - '1';

    if(tabuleiro[linha][coluna] != ' ')
    {
        printf("Essa posicao já está ocupada. Tente novamente.\n");
        fazer_jogada();
    }
    else
    {
        atualizar_tabuleiro(linha, coluna, jogador);
    }
}


int main()
{
    int i, j;

    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            tabuleiro[i][j] = ' ';
        }
    }
    
    imprimir_tabuleiro();

    while(1)
    {
        fazer_jogada();
        imprimir_tabuleiro();
  
        if(verificar_vencedor(jogador))
        {
            printf("Parabens, Jogador %c venceu!\n", jogador);
            break;
        }
   
        if(verificar_empate())
        {
            printf("O jogo empatou!\n");
            break;
        }
   
        if(jogador == 'X')
        {
            jogador = 'O';
        }
        else
        {
            jogador = 'X';
        }
    }
    return 0;
}
