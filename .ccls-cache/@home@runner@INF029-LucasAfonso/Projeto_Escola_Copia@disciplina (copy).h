#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct disciplinas
{
    char nome_disciplina[50];
    int codigo;
    int semestre;
    int professor_matricula;
    int matricula_aluno;
}Disciplina;

int main_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
