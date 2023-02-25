#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VAGAS 3 
#define ALUNOS 3
#define MaxTurmas 3

typedef struct aluno {

    int mat;
    char nome[50];
    float notas[3];
    float media;

}Aluno;

typedef struct turma {

    char id;
    int vagas;
    Aluno * alunos[ALUNOS];

}Turma;

Turma * turmas[MaxTurmas];

Turma * criar_turma(char id);
void matricula_aluno(int matr, char * nome, char id);
void lanca_notas(Turma * turmas, char id);
void imprime_alunos(Turma * turmas, char id);
void imprime_turmas(Turma ** turmas);
Turma * procura_turma(Turma ** turmas, int n, char id);


int main(void) {

    int opcao, mat, i_turma = 0, i_alunos = 0;
    char id_turmas, nome_aluno[50];

    do {

        printf("\nMENU:\n");
        printf("\n1 - Criar turma\n2 - Listar turma\n3 - Matricular Aluno\n4 - Lancar notas\n5 - Listar alunos\n6 - Sair\n");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                if(i_turma < MaxTurmas) {

                    printf("\nInforme o id da turma: ");
                    scanf(" %[^\n]c", &id_turmas);

                    turmas[i_turma] = criar_turma(id_turmas);

                    i_turma++;

                }  
                else
                    printf("\nSem Vagas!\n");        
            
                break;

            case 2:

                imprime_turmas(turmas);
                break;

            case 3:
            
                if(i_alunos < ALUNOS) {

                    printf("\nInforme o id da turma: ");
                    scanf(" %[^\n]c", &id_turmas);

                    printf("\nInforme o nome do aluno: ");
                    scanf(" %[^\n]s", nome_aluno);

                    printf("\nDigite a sua matricula: ");
                    scanf("%d", &mat);

                    matricula_aluno(procura_turma(mat, nome_aluno, id_turmas);
                    i_alunos++;

                }
                else 
                    printf("\nSem Vagas!\n");

                break;

            case 4:

                printf("\nDigite o id da turma: ");
                scanf(" %[^\n]c", &id_turmas);

                //lanca_notas(turmas, id_turmas);

                break;

            case 5:

                printf("\nDigite o id da turma: ");
                scanf(" %[^\n]c", &id_turmas);

                //imprime_alunos(turmas, id_turmas);

                break;

            default:

                opcao = 6;

            }

        }

    while(opcao != 6);

    return(0);
}

Turma * criar_turma(char id) {

    printf("\nEntrou na funcao criar TURMA!!!\n");

    int i;

    Turma * t = (Turma*) malloc(sizeof(Turma));

    if(t == NULL) {

        exit(1);
        
    }

    t -> id = id;
    t -> vagas = VAGAS;

    for(i = 0; i < ALUNOS; i++) {

        t -> alunos[i] = NULL;

    }
    
    printf("\nCriando nova turma...");

    if(t -> vagas > 0) {

        t -> vagas--;

    }

    printf("\nSAIU na funcao criar TURMA!!!\n");


    return(t);
}

void matricula_aluno(int matr, char * nome, char id) {

    if(procura_turma(turmas, MaxTurmas, id) != NULL) {

        printf("\nEntrou na funcao matricula!!!\n");



        int j;

        for(j = 0; j < MaxTurmas; j++) {

            strcpy(turmas[id].alunos[j] -> nome, nome);
            turmas[id].alunos[j] -> mat = matr;

        }

    }

    printf("\nMatriculando aluno...");

    printf("\nSAIU na funcao matricula!!!\n");


}

void lanca_notas(Turma * turmas, char id) {

    printf("\nEntrou na funcao lanca nota!!!\n");


    int i;

    printf("\nLancando as Notas...");

    for(i = 0; i < MaxTurmas - turmas -> vagas; i++) {

        printf("\n====================================\n");
        printf("\nAluno: %s", turmas[id].alunos[i] -> nome);
        printf("\nNota 1: ");
        scanf("%f", &turmas[id].alunos[i] -> notas[0]);
        printf("\nNota 2: ");
        scanf("%f", &turmas[id].alunos[i] -> notas[1]);
        printf("\nNota 3: ");
        scanf("%f", &turmas[id].alunos[i] -> notas[2]);
                
        turmas[id].alunos[i] -> media = (turmas[id].alunos[i] -> notas[0] + turmas[id].alunos[i] -> notas[1] + turmas[id].alunos[i] -> notas[2]) / 3.0;
        printf("\nMedia: %.1f", turmas[id].alunos[i] -> media);

    }




    printf("\nSAIU na funcao lanca nota!!!\n");


}



void imprime_alunos(Turma * turmas, char id) {

    int i, j;

    printf("\nListando Alunos...");

    if(procura_turma(turmas, MaxTurmas, id) != NULL) {

        for(i = 0; i < MaxTurmas; i++) {

            for(j = 0; j < MaxTurmas; j++) {

                printf("\n========================================\n");

                printf("\nNome: %s", turmas[i].alunos[j] -> nome);
                printf("Matricula: %d", turmas[i].alunos[j] -> mat);
                printf("Media: %.1f", turmas[i].alunos[j] -> media);

            }

        }

    }

    else {

        printf("\nTurma nao Existe!\n");

    }

}

void imprime_turmas(Turma ** turmas) {

    int i;

    printf("\nListando Turmas...");

    for(i = 0; i < MaxTurmas; i++) {

        printf("\n===========================\n");
        printf("\nTurma %c", turmas[i] -> id);
        printf(" - Vagas Disponiveis: %d", 3 - turmas[i] -> vagas);

    }

}

Turma * procura_turma(Turma ** turmas, int n, char id) {

    int i;

    for(i = 0; i < n; i++) {

        if(turmas[i] -> id == id) {

            printf("\nTem Vagas!\n");

            return turmas[i];

            break;

        }

    }

}
