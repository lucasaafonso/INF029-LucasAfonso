#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "escola.h"

typedef struct disciplinas
{
    char nome_disciplina[50];
    int codigo;
    int semestre;
    int professor_matricula;
    int aluno_matricula[TAM_ALUNO];
    int alunos_cadastrados_quantidade;
}Disciplina;

int main_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int menu_disciplina();
int adicionar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int codigo();
void listar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int posicao_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina, int codigo);
int excluir_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int atualizar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina);
int menu_disciplina_aluno();
int incluir_aluno_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina);
