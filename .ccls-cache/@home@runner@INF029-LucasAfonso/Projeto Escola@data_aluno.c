#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_aluno.h"
#include "escola.h"

int validar_data_aluno(Data_Aluno data_aluno) {
  int dia_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if (data_aluno.ano_aluno <= 0 || data_aluno.mes_aluno < 1 ||
      data_aluno.mes_aluno > 12 || data_aluno.dia_aluno < 1) {
    return DATA_ALUNO_ERRO;
  }

  if (data_aluno.mes_aluno == 2) {
    int bissexto =
        (data_aluno.ano_aluno % 4 == 0 && data_aluno.ano_aluno % 100 != 0) ||
        (data_aluno.ano_aluno % 400 == 0);
    int max_dias = 28 + bissexto;
    if (data_aluno.dia_aluno > max_dias) {
      return DATA_ALUNO_ERRO;
    } else {
      int max_dias = dia_por_mes[data_aluno.mes_aluno - 1];
      if (data_aluno.dia_aluno > max_dias) {
        return DATA_ALUNO_ERRO;
      }
    }
  }
  return DATA_ALUNO_SUCESSO;
}
