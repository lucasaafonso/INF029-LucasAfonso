#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "data_professor.h"
#include "escola.h"

int validar_data_professor(Data_Professor data_professor)
{
    int dia_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if(data_professor.ano_professor <= 0 || data_professor.mes_professor < 1 || data_professor.mes_professor > 12 || data_professor.dia_professor < 1)
    {
        return DATA_PROFESSOR_ERRO;
    }

    if (data_professor.mes_professor == 2)
    {
        int bissexto = (data_professor.ano_professor % 4 == 0 && data_professor.ano_professor % 100 != 0) || (data_professor.ano_professor % 400 == 0);
        int max_dias = 28 + bissexto;
        if (data_professor.dia_professor > max_dias)
        {
            return DATA_PROFESSOR_ERRO;
        }
        else
        {
            int max_dias = dia_por_mes[data_professor.mes_professor - 1];
            if (data_professor.dia_professor > max_dias)
            {
                return DATA_PROFESSOR_ERRO;
            }
        }
    }
    return DATA_PROFESSOR_SUCESSO;
}
