#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int index, j, l, c; 
    char** linhas;
    int costas = 0;

    printf("Digite o tamanho do seu mapa: "); //usuário irá digitar a quantidade de linhas e colunas da matriz
    scanf("%d %d", &l, &c);

    linhas = (char**) malloc(l * sizeof(char*)); //alocando as linhas dinâmicamente

    for(index = 0; index < c; index++) {

        linhas[index] = (char*) malloc(c * sizeof(char)); //alocanfo as colunas dinâmicamente

    }

    for(index = 0; index < l; index++) {

        scanf("%s", linhas[index]); //pedindo para ler as linhas do mapa

    }

    for(index = 0; index < l; index++) { //fazendo a verificação do território

        for(j = 0; j < c; j++) {

            if(linhas[index][j] == '#') { //condição para verificar se aquele ponto no mapa é terra

                if((index == 0 || linhas[index - 1][j] == '.')) { //verificando se a esquerda da minha terra tem água
                    costas++;
                }
                else if((index == l - 1 || linhas[index + 1][j] == '.')) { //verificando se a direita da minha terra tem água
                    costas++;
                }
                else if((j == 0 || linhas[index][j - 1] == '.')) { //verificando se acima da minha terra tem água
                    costas++;
                }
                else if((j == c - 1 || linhas[index][j + 1] == '.')) { //verificando se abaixo da minha terra tem água
                    costas++;                                          //se algumas dessas condições forem verdadeira, meu contador soma mais um
                }

            }

        }

    }

    printf("\nQuantidade de costas: %d", costas);

    for(index = 0; index < c; index++) { //liberando minha memória

        free(linhas[index]);

    }

    free(linhas);

    return(0);
}