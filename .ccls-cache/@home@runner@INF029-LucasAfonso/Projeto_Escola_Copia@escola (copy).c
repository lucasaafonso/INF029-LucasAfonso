#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "escola.h"
#include "aluno.h"
#include "professor.h"
#include "disciplina.h"

int menuprincipal();

Aluno aluno;
Aluno lista_aluno[TAM_ALUNO];
int quantidade_aluno = 0;   

Professor professor;
Professor lista_professor[TAM_PROFESSOR];
int quantidade_professor = 0;

Disciplina disciplina;
Disciplina lista_disciplina[TAM_DISICPLINA];
int quantidade_disciplina = 0;

int main()
{
  int opcao;
  int sair = 0;

  Professor get_professor(int matricula)
  {
      return get_professor(lista_professor, quatidade_professor, matricula);
  }

  while(!sair)
  {
    opcao = menuprincipal();

    switch(opcao)
    {
      case 0:
      {
        printf("Finalizando Escola\n");
        sair = 1;
        break;
      }
      case 1:
      {
        quantidade_aluno = main_aluno(lista_aluno, quantidade_aluno);
        break;
      }
      case 2:
      {
        quantidade_professor = main_professor(lista_professor, quantidade_professor);
        break;
      }
      case 3:
      {
        quantidade_disciplina = main_disciplina(lista_disciplina, quantidade_disciplina);  
        break;
      }
      default:
      {
        printf("Opcao invalida!");
        break;
      }
    }
  }
}

int menuprincipal()
{
  int opcao;

  printf("Digite a opcao:\n");
  printf("0 - Sair\n");
  printf("1 - Aluno\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n\n");

  scanf("%d", &opcao);

  system("clear");
  
  return opcao;
}
