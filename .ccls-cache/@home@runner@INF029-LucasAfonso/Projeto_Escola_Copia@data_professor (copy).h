#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct data_professor
{
  	int dia_professor;
  	int mes_professor;
	int ano_professor; 
}Data_Professor; 

int validar_data_professor(Data_Professor data_professor);
