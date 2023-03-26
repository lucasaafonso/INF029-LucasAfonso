#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "aluno.h"
#include "escola.h"

static int aluno_matricula = 100;

int main_aluno(Aluno lista_aluno[], int quantidade_aluno)
{
  int opcao;
  int sair = 0;

  int retorno;

  while (!sair)
  {
    opcao = menu_aluno();

    switch(opcao)
    {
        case 0:
        {
            sair = 1;
            break;
        }
        case 1:
        {
            retorno = inserir_aluno(lista_aluno, quantidade_aluno);
            if(retorno == ALUNO_SUCESSO)
            {
                system("clear");
                printf("Aluno cadastrado com sucesso\n\n");
                quantidade_aluno++;
            }
            else
            {
                switch(retorno)
                {
                    case ERRO_SEXO_ALUNO:
                    {
                        system("clear");
                        printf("Erro no cadastro do sexo do aluno\n\n");
                        break;
                    }
                    case DATA_ALUNO_ERRO:
                    {
                        system("clear");
                        printf("Erro na validacao da data de nascimento do aluno\n\n");
                        break;
                    }
                    default:
                    {
                        system("clear");
                        printf("Erro no cadastro do aluno\n\n");
                        break;
                    }
                }
            }
            break;
        }
        case 2:
        {
            listar_aluno(lista_aluno, quantidade_aluno);
            break;
        }
        case 3:
        {
            int retorno = excluir_aluno(lista_aluno, quantidade_aluno);
            if(retorno == ALUNO_NAO_ENCONTRADO)
            {
                system("clear");
                printf("Aluno nao encontrado\n\n");
            }
            else
            {
                system("clear");
                printf("Aluno excluido com sucesso\n\n");
                quantidade_aluno--;
            }
            break;
        }
        case 4:
        {
            int retorno = atualizar_aluno(lista_aluno, quantidade_aluno);
            if(retorno == ALUNO_NAO_ENCONTRADO)
            {
                system("clear");
                printf("Aluno nao encrontado\n\n");
            }
            else
            {
                switch(retorno)
                {
                    case ALUNO_ATUALIZADO:
                    {
                        system("clear");
                        printf("Aluno atualizado com sucesso\n\n");
                    }
                    case ERRO_SEXO_ALUNO:
                    {
                        system("clear");
                        printf("Novo sexo invalido\n\n");
                    }
                    case DATA_ALUNO_ERRO:
                    {
                        system("clear");
                        printf("Erro na validacao da data de nascimento do aluno\n\n");
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

  return quantidade_aluno;
}

int menu_aluno()
{
    int opcao;

    printf("Digite a opcao:\n");
    printf("0 - Voltar\n");
    printf("1 - Inserir aluno\n");
    printf("2 - Listar alunos\n");
    printf("3 - Excluir aluno por matricula\n");
    printf("4 - Atualizar aluno\n\n");

    scanf("%d", &opcao);

    system("clear");

    return opcao;
}

int inserir_aluno(Aluno lista_aluno[], int quantidade_aluno)
{
    printf("Cadastro de alunos:\n\n");
    getchar();

    printf("Digite o nome do aluno:\n");
    fgets(lista_aluno[quantidade_aluno].nome_aluno, 50, stdin);
    size_t ln = strlen(lista_aluno[quantidade_aluno].nome_aluno) - 1;
    if(lista_aluno[quantidade_aluno].nome_aluno[ln] == '\n')
    {
        lista_aluno[quantidade_aluno].nome_aluno[ln] = '\0';
    }

    printf("Digite o sexo do aluno:\n");
    scanf("%c", &lista_aluno[quantidade_aluno].sexo_aluno);
    lista_aluno[quantidade_aluno].sexo_aluno = toupper(lista_aluno[quantidade_aluno].sexo_aluno);
    if(lista_aluno[quantidade_aluno].sexo_aluno != 'M' && lista_aluno[quantidade_aluno].sexo_aluno != 'F')
    {
        return ERRO_SEXO_ALUNO;
    }

    printf("\nData de nascimento do aluno:\n");
    printf("Digite o dia de nascimento: ");
    scanf("%d", &lista_aluno[quantidade_aluno].data_de_nascimento_aluno.dia_aluno);
    printf("Digite o mes de nascimento: ");
    scanf("%d", &lista_aluno[quantidade_aluno].data_de_nascimento_aluno.mes_aluno);
    printf("Digite o ano de nascimento: ");
    scanf("%d", &lista_aluno[quantidade_aluno].data_de_nascimento_aluno.ano_aluno);
    int data_valida_aluno = validar_data_aluno(lista_aluno[quantidade_aluno].data_de_nascimento_aluno);
    if(data_valida_aluno == DATA_ALUNO_ERRO)
    {
        return DATA_ALUNO_ERRO;
    }
    

    getchar();

    printf("\nDigite o CPF do aluno:\n");
    fgets(lista_aluno[quantidade_aluno].cpf_aluno, 15, stdin);
    ln = strlen(lista_aluno[quantidade_aluno].cpf_aluno - 1);
    if(lista_aluno[quantidade_aluno].cpf_aluno[ln] == '\n')
    {
        lista_aluno[quantidade_aluno].cpf_aluno[ln] = '\0';
    }

    system("clear");

    lista_aluno[quantidade_aluno].matricula_aluno = matricula_aluno();

    return ALUNO_SUCESSO;
}

int matricula_aluno()
{
    aluno_matricula++;

    return aluno_matricula;
}

void listar_aluno(Aluno lista_aluno[], int quantidade_aluno)
{
    printf("Lista de alunos:\n\n");

    for(int i = 0; i < quantidade_aluno; i++)
    {
        printf("Nome do aluno:\n%s\n", lista_aluno[i].nome_aluno);
        printf("Sexo do aluno:\n%c\n", lista_aluno[i].sexo_aluno);
        printf("CPF do aluno:\n%s\n", lista_aluno[i].cpf_aluno);
        printf("Data de nascimento do aluno:\n%d/%d/%d\n", lista_aluno[i].data_de_nascimento_aluno.dia_aluno, lista_aluno[i].data_de_nascimento_aluno.mes_aluno, lista_aluno[i].data_de_nascimento_aluno.ano_aluno);
        printf("Matricula do aluno:\n%d\n", lista_aluno[i].matricula_aluno);
        printf("\n");
    }
    printf("\n");
}

Aluno get_aluno(Aluno lista_aluno[], int quantidade_aluno, int matricula)
{

    Aluno aux;
    for(int i = 0; i < quantidade_aluno; i++)
    {
        if(lista_aluno[i].matricula_aluno == matricula)
        {
            return lista_aluno[i];
        }
    }

    return aux;
}

int posicao_aluno(Aluno lista_aluno[], int quantidade_aluno, int matricula_aluno)
{
    for(int i = 0; i < quantidade_aluno; i++)
    {
        if(lista_aluno[i].matricula_aluno == matricula_aluno)
        {
            return i;
        }
    }
    return ALUNO_NAO_ENCONTRADO;
}

int excluir_aluno(Aluno lista_aluno[], int quantidade_aluno)
{
    listar_aluno(lista_aluno, quantidade_aluno);

    printf("\nDigite a matricula do aluno que deseja excluir:\n");
    int matricula_aluno;
    scanf("%d", &matricula_aluno);

    int buscar_posicao_aluno = posicao_aluno(lista_aluno, quantidade_aluno, matricula_aluno);

    if(buscar_posicao_aluno == ALUNO_NAO_ENCONTRADO)
    {
        return ALUNO_NAO_ENCONTRADO;
    }
    else
    {
        int i = buscar_posicao_aluno;
        for(; i < quantidade_aluno; i++)
        {
            lista_aluno[i] = lista_aluno[i + 1];
        }
        return SUCESSO_EXCLUSAO_ALUNO;
    }
}

int atualizar_aluno(Aluno lista_aluno[], int quantidade_aluno)
{
    listar_aluno(lista_aluno, quantidade_aluno);

    printf("\nDigite a matricula do aluno que deseja atualizar:\n");
    int matricula;
    scanf("%d", &matricula);

    int posicao = posicao_aluno(lista_aluno, quantidade_aluno, matricula);

    if(posicao == ALUNO_NAO_ENCONTRADO)
    {
        return ALUNO_NAO_ENCONTRADO;
    }
    else
    {
        Aluno aluno_atualizado;
        getchar();

        printf("Digite o nome do aluno:\n");
        fgets(aluno_atualizado.nome_aluno, 50, stdin);
        size_t ln = strlen(aluno_atualizado.nome_aluno) - 1;
        if(aluno_atualizado.nome_aluno[ln] == '\n')
        {
            aluno_atualizado.nome_aluno[ln] = '\0';
        }

        printf("Digite o sexo do aluno:\n");
        scanf("%c", &aluno_atualizado.sexo_aluno);
        aluno_atualizado.sexo_aluno = toupper(aluno_atualizado.sexo_aluno);
        if(aluno_atualizado.sexo_aluno != 'M' &&  aluno_atualizado.sexo_aluno != 'F')
        {
            return ERRO_SEXO_ALUNO;
        }

        printf("\nData de nascimento do aluno:\n");
        printf("Digite o dia de nascimento do aluno:\n");
        scanf("%d", &aluno_atualizado.data_de_nascimento_aluno.dia_aluno);
        printf("Digite o mes de nascimento do aluno:\n");
        scanf("%d", &aluno_atualizado.data_de_nascimento_aluno.mes_aluno);
        printf("Digite o ano de nascimento do aluno:\n");
        scanf("%d", &aluno_atualizado.data_de_nascimento_aluno.ano_aluno);
        scanf("%d", &lista_aluno[quantidade_aluno].data_de_nascimento_aluno.ano_aluno);
        int data_valida_aluno = validar_data_aluno(aluno_atualizado.data_de_nascimento_aluno);
        if(data_valida_aluno == DATA_ALUNO_ERRO)
        {
            return DATA_ALUNO_ERRO;
        }
        getchar();

        printf("Digite o CPF do aluno:\n");
        fgets(aluno_atualizado.cpf_aluno, 15, stdin);
        ln = strlen(aluno_atualizado.cpf_aluno) - 1;
        if(aluno_atualizado.cpf_aluno[ln] == '\n')
        {
            aluno_atualizado.cpf_aluno[ln] = '\0';
        }

        aluno_atualizado.matricula_aluno = lista_aluno[posicao].matricula_aluno;
        lista_aluno[posicao] = aluno_atualizado;

        system("clear");

        return ALUNO_ATUALIZADO;
    }
}
