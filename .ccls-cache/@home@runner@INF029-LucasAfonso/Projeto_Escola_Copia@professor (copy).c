#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "professor.h"
#include "escola.h"

static int professor_matricula = 1000;

int menu_professor();
int inserir_professor(Professor lista_professor[], int quantidade_professor);
int matricula_professor();
void listar_professor(Professor lista_professor[], int quantidade_professor);
int posicao_professor(Professor lista_professor[], int quantidade_professor, int matricula);
int excluir_professor(Professor lista_professor[], int quantidade_professor);
int atualizar_professor(Professor lista_professor[], int quantidade_professor);

int main_professor(Professor lista_professor[], int quantidade_professor)
{
  int opcao;
  int sair = 0;

  int retorno;

  while (!sair)
  {
    opcao = menu_professor();

    switch(opcao)
    {
        case 0:
        {
            sair = 1;
            break;
        }
        case 1:
        {
            retorno = inserir_professor(lista_professor, quantidade_professor);
            if(retorno == PROFESSOR_SUCESSO)
            {
                system("clear");
                printf("Professor cadastrado com sucesso\n\n");
                quantidade_professor++;
            }
            else
            {
                switch(retorno)
                {
                    case ERRO_SEXO_PROFESSOR:
                    {
                        system("clear");
                        printf("Erro no cadastro do sexo do professor\n\n");
                        break;
                    }
                    case DATA_PROFESSOR_ERRO:
                    {
                        system("clear");
                        printf("Erro na validacao da data de nascimento do professor\n\n");
                        break;
                    }
                    default:
                    {
                        system("clear");
                        printf("Erro no cadastro do professor\n\n");
                        break;
                    }
                }
            }
            break;
        }
        case 2:
        {
            listar_professor(lista_professor, quantidade_professor);
            break;
        }
        case 3:
        {
            int retorno = excluir_professor(lista_professor, quantidade_professor);
            if(retorno == PROFESSOR_NAO_ENCONTRADO)
            {
                system("clear");
                printf("Professor nao encontrado\n\n");
            }
            else
            {
                system("clear");
                printf("Professor excluido com sucesso\n\n");
                quantidade_professor--;
            }
            break;
        }
        case 4:
        {
            int retorno = atualizar_professor(lista_professor, quantidade_professor);
            if(retorno == PROFESSOR_NAO_ENCONTRADO)
            {
                system("clear");
                printf("Professor nao encrontado\n\n");
            }
            else
            {
                switch(retorno)
                {
                    case PROFESSOR_ATUALIZADO:
                    {
                        system("clear");
                        printf("Professor atualizado com sucesso\n\n");
                    }
                    case ERRO_SEXO_PROFESSOR:
                    {
                       system("clear");
                        printf("Novo sexo invalido\n\n");
                    }
                    case DATA_PROFESSOR_ERRO:
                    {
                        system("clear");
                        printf("Erro na validacao da data de nascimento do professor\n\n");
                        break;
                    }
                    default:
                    {
                        system("clear");
                        printf("Atualizacao nao funcionou\n\n");
                    }
                }
            }
        }
        default:
        {
            system("clear");
            printf("\nOpcao invalida\n\n");
            break;
        }
    }
  }
}

int menu_professor()
{
    int opcao;

    printf("Digite a opcao:\n");
    printf("0 - Voltar\n");
    printf("1 - Inserir professor\n");
    printf("2 - Listar professores\n");
    printf("3 - Excluir professor por matricula\n");
    printf("4 - Atualizar professor\n\n");

    scanf("%d", &opcao);

    system("clear");

    return opcao;
}

int inserir_professor(Professor lista_professor[], int quantidade_professor)
{
    printf("Cadastro de professor:\n\n");
    getchar();

    printf("Digite o nome do professor:\n");
    fgets(lista_professor[quantidade_professor].nome_professor, 50, stdin);
    size_t ln = strlen(lista_professor[quantidade_professor].nome_professor) - 1;
    if(lista_professor[quantidade_professor].nome_professor[ln] == '\n')
    {
        lista_professor[quantidade_professor].nome_professor[ln] = '\0';
    }

    printf("Digite o sexo do professor:\n");
    scanf("%c", &lista_professor[quantidade_professor].sexo_professor);
    lista_professor[quantidade_professor].sexo_professor = toupper(lista_professor[quantidade_professor].sexo_professor);
    if(lista_professor[quantidade_professor].sexo_professor != 'M' && lista_professor[quantidade_professor].sexo_professor != 'F')
    {
        return ERRO_SEXO_PROFESSOR;
    }

    printf("\nData de nascimento do professor:\n");
    printf("Digite o dia de nascimento:\n");
    scanf("%d", &lista_professor[quantidade_professor].data_de_nascimento_professor.dia_professor);
    printf("Digite o mes de nascimento:\n");
    scanf("%d", &lista_professor[quantidade_professor].data_de_nascimento_professor.mes_professor);
    printf("Digite o ano de nascimento:\n");
    scanf("%d", &lista_professor[quantidade_professor].data_de_nascimento_professor.ano_professor);
    int data_valida_professor = validar_data_professor(lista_professor[quantidade_professor].data_de_nascimento_professor);
    if(data_valida_professor == DATA_PROFESSOR_ERRO)
    {
        return DATA_PROFESSOR_ERRO;
    }

    getchar();

    printf("\nDigite o CPF do professor:\n");
    fgets(lista_professor[quantidade_professor].cpf_professor, 15, stdin);
    ln = strlen(lista_professor[quantidade_professor].cpf_professor - 1);
    if(lista_professor[quantidade_professor].cpf_professor[ln] == '\n')
    {
        lista_professor[quantidade_professor].cpf_professor[ln] = '\0';
    }

    system("clear");

    lista_professor[quantidade_professor].matricula_professor = matricula_professor();

    return PROFESSOR_SUCESSO;
}

int matricula_professor()
{
    professor_matricula++;

    return professor_matricula;
}

void listar_professor(Professor lista_professor[], int quantidade_professor)
{
    printf("Lista de professores:\n\n");

    for(int i = 0; i < quantidade_professor; i++)
    {
        printf("Nome do professor:\n%s\n", lista_professor[i].nome_professor);
        printf("Sexo do professor:\n%c\n", lista_professor[i].sexo_professor);
        printf("CPF do professor:\n%s\n", lista_professor[i].cpf_professor);
        printf("Data de nascimento do professor:\n%d/%d/%d\n", lista_professor[i].data_de_nascimento_professor.dia_professor, lista_professor[i].data_de_nascimento_professor.mes_professor, lista_professor[i].data_de_nascimento_professor.ano_professor);
        printf("Matricula do professor:\n%d\n", lista_professor[i].matricula_professor);
        printf("\n");
    }
    printf("\n");
}

Professor get_professor(Professor lista_professor[], int quantidade_professor, int matricula)
{
    for(int p = 0; p < quantidade_professor; p++)
    {
        if(lista_professor[p].matricula_professor == matricula)
        {
            return p;
        }
    }
}

int posicao_professor(Professor lista_professor[], int quantidade_professor, int matricula_professor)
{
    for(int i = 0; i < quantidade_professor; i++)
    {
        if(lista_professor[i].matricula_professor == matricula_professor)
        {
            return i;
        }
    }
    return PROFESSOR_NAO_ENCONTRADO;
}

int excluir_professor(Professor lista_professor[], int quantidade_professor)
{
    listar_professor(lista_professor, quantidade_professor);

    printf("\nDigite a matricula do professor que deseja excluir:\n");
    int matricula_professor;
    scanf("%d", &matricula_professor);

    int buscar_posicao_professor = posicao_professor(lista_professor, quantidade_professor, matricula_professor);

    if(buscar_posicao_professor == PROFESSOR_NAO_ENCONTRADO)
    {
        return PROFESSOR_NAO_ENCONTRADO;
    }
    else
    {
        int i = buscar_posicao_professor;
        for(; i < quantidade_professor; i++)
        {
            lista_professor[i] = lista_professor[i + 1];
        }
        return SUCESSO_EXCLUSAO_PROFESSOR;
    }
}

int atualizar_professor(Professor lista_professor[], int quantidade_professor)
{
    listar_professor(lista_professor, quantidade_professor);

    printf("\nDigite a matricula do professor que deseja atualizar:\n");
    int matricula;
    scanf("%d", &matricula);

    int posicao = posicao_professor(lista_professor, quantidade_professor, matricula);

    if(posicao == PROFESSOR_NAO_ENCONTRADO)
    {
        return PROFESSOR_NAO_ENCONTRADO;
    }
    else
    {
        Professor professor_atualizado;
        getchar();

        printf("Digite o nome do professor:\n");
        fgets(professor_atualizado.nome_professor, 50, stdin);
        size_t ln = strlen(professor_atualizado.nome_professor) - 1;
        if(professor_atualizado.nome_professor[ln] == '\n')
        {
            professor_atualizado.nome_professor[ln] = '\0';
        }

        printf("Digite o sexo do professor:\n");
        scanf("%c", &professor_atualizado.sexo_professor);
        professor_atualizado.sexo_professor = toupper(professor_atualizado.sexo_professor);
        if(professor_atualizado.sexo_professor != 'M' &&  professor_atualizado.sexo_professor != 'F')
        {
            return ERRO_SEXO_PROFESSOR;
        }

        printf("\nData de nascimento do professir:\n");
        printf("Digite o dia de nascimento do professor:\n");
        scanf("%d", &professor_atualizado.data_de_nascimento_professor.dia_professor);
        printf("Digite o mes de nascimento do professor:\n");
        scanf("%d", &professor_atualizado.data_de_nascimento_professor.mes_professor);
        printf("Digite o ano de nascimento do professor:\n");
        scanf("%d", &professor_atualizado.data_de_nascimento_professor.ano_professor);
        int data_valida_professor = validar_data_professor(professor_atualizado.data_de_nascimento_professor);
        if(data_valida_professor == DATA_PROFESSOR_ERRO)
        {
            return DATA_PROFESSOR_ERRO;
        }
        getchar();

        printf("Digite o CPF do professor:\n");
        fgets(professor_atualizado.cpf_professor, 15, stdin);
        ln = strlen(professor_atualizado.cpf_professor) - 1;
        if(professor_atualizado.cpf_professor[ln] == '\n')
        {
            professor_atualizado.cpf_professor[ln] = '\0';
        }

        professor_atualizado.matricula_professor = lista_professor[posicao].matricula_professor;
        lista_professor[posicao] = professor_atualizado;

        system("clear");

        return PROFESSOR_ATUALIZADO;
    }
}
