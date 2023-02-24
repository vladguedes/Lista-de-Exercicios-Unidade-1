#include <stdio.h>
#include <stdlib.h>

struct pessoa {  //estrutura com os dados de uma pessoa
    char nome[50];
    int idade, num_doc;
};

void ler(struct pessoa **p, int qnt_p) {  //função para ler os dados de uma pessoa
    int i;

    for(i = 0; i < qnt_p; i++) {           //laço de repetição para receber os dados das pessoas

        printf("\nDigite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]s", p[i] -> nome);
        printf("\nDigite a idade dessa pessoa: ");
        scanf("%d", &p[i] -> idade);
        printf("\nDigite o numero do seu documento: ");
        scanf("%d", &p[i] -> num_doc);

    }

}

void imprime(struct pessoa **p, int qnt_p) {   //função para imprimir os dados das pessoas
    int i;

    for(i = 0; i < qnt_p; i++) {                //laço de repetição para imprimir os dados das pessoas

        printf("\n=======================\n");
        printf("\nPessoa num.%d ", i + 1);
        printf("\nNome: %s", p[i] -> nome);
        printf("\nIdade: %d", p[i] -> idade);
        printf("\nNumero do Documento: %d", p[i] -> num_doc);

    }

}

void altera(struct pessoa **p) {    //função para alterar a idade de uma pessoa
    int altera;
    char escolha;
    
    printf("\nDeseja alterar a idade de alguem?\nDigite 's' para sim, e 'n' para nao: ");
    scanf(" %c", &escolha);
    if(escolha == 'n') {

    }

    else {

        printf("\nDigite o numero da pessoa que deseja alterar a idade: ");
        scanf("%d", &altera);
        printf("\nDigite a nova idade: ");
        scanf("%d", &p[altera - 1] -> idade);                    //digita a nova idade da pessoa a partir do numero dessa pessoa - 1 para poder acessar o elemento certo
        printf("\nA pessoa %d agora tem %d anos.", altera, p[altera - 1] -> idade);

    }

}

void maior(struct pessoa **p, int qnt_p) {   //função para calcular e mostrar quem a pessoa mais velha e a mais nova
    int maior, imaior, menor, imenor, i;

    for(i = 0; i < qnt_p; i++) {

        if(i == 0) {                        //condição que faz com que no começo do laço da repetição, as variáveis maior e menor recebem os valores
                                            //mas apenas no começo do laço, depois ele irá atualizar minhas variáveis
            maior = p[i] -> idade;          
            menor = p[i] -> idade;
            imaior = i;
            imenor = i;

        }

        if(maior < p[i] -> idade) {       //condição para verificar se a minha variável "maior" é menor que a idade atual que está sendo analizada

            maior = p[i] -> idade;
            imaior = i;

        }

        if(menor > p[i] -> idade) {       //condição para verificar se a minha variável "menor" é maior que a idade atual que está sendo analizada

            menor = p[i] -> idade;
            imenor = i;

        }

    }

    printf("\nA pessoa mais velha e %s.", p[imaior] -> nome);
    printf("\nE a pessoa mais nova e %s.", p[imenor] -> nome);

}

int main(void) {
    int qnt_pessoas, i;

    printf("Digite a quantidade de pessoas: ");
    scanf("%d", &qnt_pessoas);

    struct pessoa **p = (struct pessoa**) malloc(qnt_pessoas * sizeof(struct pessoa*));  //alocando minha variável p dinamicamente

    for(i = 0; i < qnt_pessoas; i++) {

        p[i] = (struct pessoa*) malloc(qnt_pessoas * sizeof(struct pessoa*));
    }

    ler(p, qnt_pessoas);            //chamada das funções
    imprime(p, qnt_pessoas);
    altera(p);
    maior(p, qnt_pessoas);

    for(i = 0; i < qnt_pessoas; i++) {    //liberando minha memória

        free(p[i]);
    }

    free(p);

    return(0);
}
