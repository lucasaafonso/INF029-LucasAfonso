#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct data_aluno
{
  	int dia_aluno;
  	int mes_aluno;
	  int ano_aluno; 
}Data_Aluno; 

int validar_data_aluno(Data_Aluno data_aluno);
