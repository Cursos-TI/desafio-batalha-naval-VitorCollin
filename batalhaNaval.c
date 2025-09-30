#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval 

#define LINHA 10
#define COLUNA 10
#define TAMANHO_HABLIDADE 5

int main() {
   
    // Criando a matriz do tabuleiro
    int tabuleiro [LINHA][COLUNA];
    //Criando os vetores dos navios
    int navio1[3];
    int navio2[3];

    //Declarando as posições verticais do navio 1
    navio1[0] = 4;
    navio1[1] = 5;
    navio1[2] = 6;

    //Declarando as posições horizontais do navio 2
    navio2[0] = 3;
    navio2[1] = 4;
    navio2[2] = 5;
    
    //Zerando todas os indices do tabuleiro
    for (int i = 0; i < LINHA; i++)
    {
        for ( int j = 0; j < COLUNA; j++)
        {
            tabuleiro[i][j] = 0;
            
        }
    }

    //Posicionando os navios verticais e horizontais
    for (int k = 0; k < 3; k++)
    {
        tabuleiro[navio1[k]][5] = 3;

        tabuleiro[2][navio2[k]] = 3;
        
    }

    //Posicionando os navios diagonais
    for (int k = 0; k < 3; k++)
    {
        tabuleiro[1 + k][k] = 3;
        
        tabuleiro[5 + k][(9 - k) - 1] = 3; // (9 - k) faz com que o navio seja posicionado na diagonal secundaria 
    }

    int habilidade_cruz [TAMANHO_HABLIDADE] [TAMANHO_HABLIDADE];
    int centro = TAMANHO_HABLIDADE / 2;
    
    for (int h = 0; h < 5; h++)
    {
        for (int i = 0; i < 5; i++)
        {
        // Verificando se a posição está na linha central ou na coluna central
        if (h == centro || i == centro) {
            habilidade_cruz[h][i] = 1; 
        } else {
            habilidade_cruz[h][i] = 0; 
        }
        }
    }

    int cruz_linha = 7;
    int cruz_coluna = 3;
    
    for (int i_hab = 0; i_hab < TAMANHO_HABLIDADE; i_hab++) {
        for (int j_hab = 0; j_hab < TAMANHO_HABLIDADE; j_hab++) {

            //Verifica a area de efeito da habilidade
            if (habilidade_cruz[i_hab][j_hab] == 1) {

                // Calcula a coordenada correspondente no tabuleiro principal
                int linha_tabuleiro = cruz_linha + i_hab - centro;
                int coluna_tabeiro = cruz_coluna + j_hab - centro;
            }
                // Validando as cordenadas
                if (habilidade_cruz[i_hab][j_hab] == 1) {
                    int linha_tab = cruz_linha + i_hab - centro;
                    int coluna_tab = cruz_coluna + j_hab - centro;

                    // Checando os limites do tabuleiro 
                    if (linha_tab >= 0 && linha_tab < 10 && coluna_tab >= 0 && coluna_tab < 10) {
                        
                        if (tabuleiro[linha_tab][coluna_tab] == 0) {
                            
                            // Modificando o tabuleiro se tudo estiver certo
                            tabuleiro[linha_tab][coluna_tab] = 5;
                        } 
                    }
                }
        }
    }


    //Criando a hablidade do cone
    int habilidade_cone[TAMANHO_HABLIDADE][TAMANHO_HABLIDADE];

    //Zerando a matriz do cone
    for (int i = 0; i < TAMANHO_HABLIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABLIDADE; j++) {
        habilidade_cone[i][j] = 0;
    }   
}
    
    //Definindo as cordenada do cone 
    int cone_linha = 3;
    int cone_coluna = 7;

    //For para percorrer a matriz do cone 
    for (int i = 0; i < 3; i++) {
    for (int j = centro - i; j <= centro + i; j++) {

        // Calcula posição no tabuleiro
        int linha_tabuleiro = cone_linha + i;
        int coluna_tabuleiro = cone_coluna + j - centro;

        // Checa limites
        if (linha_tabuleiro >= 0 && linha_tabuleiro < LINHA &&
            coluna_tabuleiro >= 0 && coluna_tabuleiro < COLUNA) {

            // Marca no tabuleiro se vazio
            if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] == 0) {
                tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5;
            }
        }
    }
}

    //Criando a matriz do Octaedro
    int habilidade_octaedro[TAMANHO_HABLIDADE][TAMANHO_HABLIDADE];

    //Inserindo as cordenadas da habilidade
    int octa_linha = 2;
    int octa_coluna = 8;

    //Zerando a matriz 
    for (int i = 0; i < TAMANHO_HABLIDADE; i++) {
    for (int j = 0; j < TAMANHO_HABLIDADE; j++) {
        habilidade_octaedro[i][j] = 0;
        }  
    }

    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {

        // 1. Calcula se o ponto (i, j) faz parte do octaedro
        if (abs(i - centro) + abs(j - centro) <= centro) {

            // 2. Calcula a posição correspondente no tabuleiro principal
            int linha_tabuleiro = octa_linha + i - centro;
            int coluna_tabuleiro = octa_coluna + j - centro;

            // 3. Verifica se essa posição está dentro dos limites do tabuleiro
            if (linha_tabuleiro >= 0 && linha_tabuleiro < LINHA &&
                coluna_tabuleiro >= 0 && coluna_tabuleiro < COLUNA) {

                // 4. Marca no tabuleiro se a posição estiver vazia (valor 0)
                if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] == 0) {
                    tabuleiro[linha_tabuleiro][coluna_tabuleiro] = 5; // Usa o número 5 para marcar
                }
            }
        }
    }
}

    //Criando o laço de repetição para apresentar o tabuleiro
    for (int i = 0; i < LINHA; i++)
    {
        for ( int j = 0; j < COLUNA; j++)
        {
         printf(" %d ", tabuleiro[i][j]);  
        }
        printf("\n");
    }

    return 0;
}

