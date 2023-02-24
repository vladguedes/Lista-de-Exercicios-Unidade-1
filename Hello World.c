#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVagas 2
#define MaxTurmas 3

typedef struct estruturaAluno {
    int mat;
    char nome[50];
    float notas[3];
    float media;
}Aluno;

typedef struct estruturaTurma {
    char id;
    int vagas;
    Aluno* alunos[MaxVagas];
}Turma;

Turma* turmas[MaxTurmas];

Turma* criar_turma(int cont, char id);
void menu();

int main(void) {

    int cont = 0;
    int opcao = 0;

    Turma* turmasTotais = (Turma*) malloc(MaxTurmas * sizeof(Turma));
    
    do {

        menu();
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:        
                
                cont++;
                break;

            case 2:

                break;

            case 3:
            
                break;

            case 4:

                break;

            case 5:

                break;

            default:

                opcao = 6;

            }

        }

    while(opcao != 6);

    return(0);
}

Turma* criar_turma(int cont, char id) {

    printf("\nEntrou na funcao criar TURMA!!!\n");

    Turma* t = (Turma*) malloc(sizeof(Turma)); //alocando dinâmicamente a variável (t)

    if(t == NULL) {  //condição caso minha alocação tenha sido mal sucedida
        printf("\nERRO NA CRIACAO DA TURMA!\n");
        exit(1);
    }
    else {

        t->id = id;
        t->vagas = MaxVagas;
        cont++;
        for(int i = 0; i < MaxVagas; i++)
            t->alunos[i] = NULL;
    
        printf("\nCriando nova turma...");

        return(t);
    }

}

void menu(void) {
    printf("\n1 - Criar Turma");
    printf("\n2 - Listar Turmas");
    printf("\n3 - Matricular Turma");
    printf("\n4 - Lancar Notas");
    printf("\n5 - Listar Alunos");
    printf("\n6 - Sair");
    printf("\n\nDigite sua opcao: ");
}

void matricula_aluno(Turma* turmas){

}