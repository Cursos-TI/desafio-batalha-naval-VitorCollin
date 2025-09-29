#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Criando a matriz do tabuleiro
    int tabuleiro [10][10];
    //Criando os vetores dos navios
    int navio1[3];
    int navio2[3];

    //Declarando as posições verticais do navio 1
    navio1[0] = 4;
    navio1[1] = 5;
    navio1[2] = 6;

    //Declarando as posições horizontais do navio 2
    navio2[0] = 2;
    navio2[1] = 3;
    navio2[2] = 4;
    
    //Zerando todas os indices do tabuleiro
    for (int i = 0; i < 10; i++)
    {
        for ( int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
            
        }
    }

    //Adicionando os navios verticais e horizontais
    for (int k = 0; k < 3; k++)
    {
        tabuleiro[navio1[k]][5] = 3;

        tabuleiro[2][navio2[k]] = 3;
    }
    
    //Criando o laço de repetição para apresentar o tabuleiro
    for (int i = 0; i < 10; i++)
    {
        for ( int j = 0; j < 10; j++)
        {
         printf(" %d ", tabuleiro[i][j]);  
        }
        printf("\n");
    }
    




    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
