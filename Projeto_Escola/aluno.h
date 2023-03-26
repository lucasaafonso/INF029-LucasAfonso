#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "data_aluno.h"

typedef struct aluno
{
    int matricula_aluno;
    char nome_aluno[50];
    char sexo_aluno;
    Data_Aluno data_de_nascimento_aluno;
    char cpf_aluno[15];
}Aluno;

int main_aluno(Aluno lista_aluno[], int quantidade_aluno);
int menu_aluno();
int inserir_aluno(Aluno lista_aluno[], int quantidade_aluno);
int matricula_aluno();
void listar_aluno(Aluno lista_aluno[], int quantidade_aluno);
Aluno get_aluno(Aluno lista_aluno[], int quantidade_aluno, int matricula);
int posicao_aluno(Aluno lista_aluno[], int quantidade_aluno, int matricula_aluno);
int excluir_aluno(Aluno lista_aluno[], int quantidade_aluno);
int atualizar_aluno(Aluno lista_aluno[], int quantidade_aluno);
Aluno get_aluno_aux(int matricula);
Aluno get_aluno(Aluno lista_aluno[], int quantidade_aluno, int matricula);
