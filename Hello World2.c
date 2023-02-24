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
    int id;
    int vagas;
    Aluno* alunos[MaxVagas];
}Turma;

Turma* turmas[MaxTurmas];

Turma* criar_turma(int id);
void menu();

int main(void) {

    int aux = 0, opcao = 0, pos;
    int mat, id_turma;
    char* nomeAluno[50];

    Turma** turmasTotais = (Turma**) malloc(MaxTurmas * sizeof(Turma*));
    
    do {

        menu();
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:     
                if(aux < MaxTurmas) {
                    printf("Insira o id da turma: ");  
                    scanf("%d", &id_turma);
                    turmasTotais[aux] = criar_turma(id_turma);
                    aux++;
                }
                else {
                    printf("\nSem Vagas Para Turmas!\n");
                }
                break;

            case 2:
                    scanf("%d", &id_turma);
            
                //imprime_turmas(turmasTotais);

                break;

            case 3:
            /*
                printf("Digite o id da turma: ");
                scanf("%d", &id_turma);
                printf("\nInsira o nome do aluno: ");
                scanf(" %s", nomeAluno);

                printf("\nDigite a sua matricula: ");
                scanf("%d", &mat);
            */
                //matricula_aluno(turmasTotais, mat, id_turma);
                break;

            case 4:
                //lanca_notas(turmasTotais);

                break;

            case 5:
                //imprime_alunos(turmasTotais);

                break;
            case 7:
                printf("insira o id da turma: ");
                scanf("%d", &id_turma);
                pos = procura_turma(turmasTotais, id_turma);
                printf("%d\n", turmasTotais[pos]->id);
                break;
            default:

                opcao = 6;

            }
        }

    while(opcao != 6);

    return(0);
}

Turma* criar_turma(int id) {

    Turma* t = (Turma*) malloc(sizeof(Turma)); //alocando dinâmicamente a variável (t)

    if(t == NULL) {  //condição caso minha alocação tenha sido mal sucedida
        printf("\nERRO NA CRIACAO DA TURMA!\n");
        exit(1);
    }
    else {

        t->id = id;
        t->vagas = MaxVagas;
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

int procura_turma(Turma* turmas, int id){
    for(int i = 0; i < MaxTurmas; i++){
        if(id == turmas[i].id){
            return i;
        }
    }
}