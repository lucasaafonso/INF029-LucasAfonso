#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_professor.h"

typedef struct professor {
  int matricula_professor;
  char nome_professor[50];
  char sexo_professor;
  Data_Professor data_de_nascimento_professor;
  char cpf_professor[15];
} Professor;

int main_professor(Professor lista_professor[], int quantidade_professor);

Professor get_professor_aux(int matricula);
Professor get_professor(Professor lista_professor[], int quantidade_professor, int matricula_professor);
