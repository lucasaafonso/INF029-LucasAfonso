#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "escola.h"

typedef struct disciplinas {
  char nome_disciplina[50];
  int codigo;
  int semestre;
  int professor_matricula;
  int aluno_matricula[TAM_ALUNO];
} Disciplina;

int main_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int incluir_aluno_disciplina(Disciplina lista_disciplina[],
                             int quantidade_disciplinas, int quantidade_aluno);
