#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVagas 2
#define MaxTurmas 3

typedef struct Aluno {
    int mat;
    char nome[50];
    float notas[3];
    float media;
}Aluno;

typedef struct Turma {
    int id;
    int vagas;
    Aluno* alunos[MaxVagas];
}Turma;

Turma* turmas[MaxTurmas];

Turma* criar_turma(int id);
void menu();
int procura_turma(Turma* turmas, int id);
void matricula_alunos(Turma* turmas, int mat, int pos, char* nome);

int main(void) {

    int aux = 0, opcao = 0, pos;
    int mat, id_turma;
    char* nomeAluno[50];

    Turma** turmasTotais = (Turma**) malloc(MaxTurmas * sizeof(Turma*));
    
    do {                    //laço de repetição que só irá parar quando o usuário digitar '6'

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
            
                printf("Digite o id da turma: ");
                scanf("%d", &id_turma);
                pos = procura_turma(turmasTotais, id_turma);
                printf("\nInsira o nome do aluno: ");
                scanf(" %s", nomeAluno);
                printf("\nDigite a sua matricula: ");
                scanf("%d", &mat);
            
                matricula_aluno(turmasTotais, mat, pos, nomeAluno);
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
                printf("AKI%d\n", turmasTotais[pos]->id);
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

    if(t == NULL) {                            //condição caso minha alocação tenha sido mal sucedida
        printf("\nERRO NA CRIACAO DA TURMA!\n");
        exit(1);
    }
    else {

        t->id = id;                         //minha variável id da struct Turma recebe meu id digitado
        t->vagas = MaxVagas;                //minha variável vagas da struct Turma recebe minha constante MaxVagas          
        for(int i = 0; i < MaxVagas; i++)   //aqui estou inicializando minha struct alunos com NULL
            t->alunos[i] = NULL;
    
        printf("\nCriando nova turma...");

        return(t);
    }

}

void menu(void) {                       //função para imprimir meu menu
    printf("\n1 - Criar Turma");
    printf("\n2 - Listar Turmas");
    printf("\n3 - Matricular Alunos");
    printf("\n4 - Lancar Notas");
    printf("\n5 - Listar Alunos");
    printf("\n6 - Sair");
    printf("\n\nDigite sua opcao: ");
}

int procura_turma(Turma* turmas, int id) {  //função para saber se a turma x foi criada
    int i, certo;
    for(i = 0; i < MaxTurmas; i++){         //comparando as turmas[i].id com o meu id informado
        if(id == turmas[i].id){
            certo = i;                      //se a turma existir, minha variável certo recebe o index 'i' e retorna ele
            break;
        }
    }
    return certo;
}

void matricula_alunos(Turma* turmas, int mat, int pos, char* nome) {
    int i;
    for(i = 0; i < MaxVagas; i++) {
        turmas[pos].alunos[i]->mat = mat;
        strcpy(turmas[pos].alunos[i]->nome, nome);


    }
}


//DESISTO DE TENTAR FAZER ESSA QUESTÃO, SOU INCAPAZ!!!!!
