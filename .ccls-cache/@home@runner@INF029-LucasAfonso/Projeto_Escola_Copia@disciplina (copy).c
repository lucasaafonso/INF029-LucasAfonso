#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "disciplina.h"
#include "escola.h"
#include "professsor.h"

static int codigo_disciplina = 10000;

int menu_disciplina();
int adicionar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int codigo();
void listar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int posicao_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina, int codigo);
int excluir_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas);
int incluir_aluno_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina);
int menu_disciplina_aluno();
int atualizar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina);

int main_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas)
{
    int opcao;
    int sair = 0;

    int retorno;

    while(!sair)
    {
        opcao = menu_disciplina();

        switch(opcao)
        {
            case 0:
            {
                sair = 1;
                break;
            }
            case 1:
            {
                retorno = adicionar_disciplina(lista_disciplina, quantidade_disciplinas);
                if(retorno == DISCIPLINA_SUCESSO)
                {
                    system("clear");
                    printf("Disciplina registrada com sucesso\n\n");
                    quantidade_disciplinas++;
                }
                break;
            }
            case 2:
            {
                system("clear");
                listar_disciplina(lista_disciplina, quantidade_disciplinas);
                break;
            }
            case 3:
            {
                int retorno = excluir_disciplina(lista_disciplina, quantidade_disciplinas);
                if(retorno == DISCIPLINA_NAO_ENCONTRADA)
                {
                    system("clear");
                    printf("Disciplina nao encontrada\n\n");
                }
                else
                {
                    system("clear");
                    printf("Disciplina excluida com sucesso\n\n");
                    quantidade_disciplinas--;
                }
                break;
            }
            case 4:
            {
                incluir_aluno_disciplina(lista_disciplina, quantidade_disciplinas);
                system("clear");
                break;
            }
            case 5:
            {
                int retorno = atualizar_disciplina(lista_disciplina, quantidade_disciplinas);
                if(retorno == DISCIPLINA_NAO_ENCONTRADA)
                {
                    system("clear");
                    printf("Disciplina nao encrontada\n\n");
                }
                else
                {
                  system("clear");
                  printf("Disciplina atualizada com sucesso\n\n");
                }
                system("clear");
                break;
            }
            default:
            {
                system("clear");
                printf("Opcao invalida\n\n");
                break;
            }
        }
    }
}

int menu_disciplina()
{
    int opcao;

    printf("Digite a opcao:\n");
    printf("0 - Voltar\n");
    printf("1 - Adicionar disciplina\n");
    printf("2 - Listar disciplinas\n");
    printf("3 - Excluir disciplina por codigo\n");
    printf("4 - Incluir Aluno na disciplina\n");
    printf("5 - Atualizar disciplina\n\n");

    scanf("%d", &opcao);

    system("clear");

    return opcao;
}

int adicionar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas)
{
    printf("Adicionar Disciplina:\n\n");
    getchar();

    printf("Digite o nome da disciplina:\n");
    fgets(lista_disciplina[quantidade_disciplinas].nome_disciplina, 50, stdin);
    size_t ln = strlen(lista_disciplina[quantidade_disciplinas].nome_disciplina) - 1;
    if(lista_disciplina[quantidade_disciplinas].nome_disciplina[ln] == '\n')
    {
        lista_disciplina[quantidade_disciplinas].nome_disciplina[ln] = '\0';
    }

    printf("Digite o semestre da disciplina:\n");
    scanf("%d", &lista_disciplina[quantidade_disciplinas].semestre);

    printf("Digite a matricula do professor que vai ministrar a disciplina:\n");
    scanf("%d", &lista_disciplina[quantidade_disciplinas].professor_matricula);

    lista_disciplina[quantidade_disciplinas].codigo = codigo();

    return DISCIPLINA_SUCESSO;
}

int codigo()
{
    codigo_disciplina++;

    return codigo_disciplina;
}

void listar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas)
{
    printf("Lista de disciplinas:\n\n");

    
    
    for(int i = 0; i < quantidade_disciplinas; i++)
    {
        printf("\nNome da disciplina:\n%s", lista_disciplina[i].nome_disciplina);
        printf("\nSemestre da disciplina:\n%d", lista_disciplina[i].semestre);
        printf("\nCodigo da disciplina:\n%d", lista_disciplina[i].codigo);
        char professor_posicao = get_professor(lista_disciplina[i].professor_matricula);
        printf("\nProfessor da disciplina(matricula):\n%s", professor_posicao);
        printf("\n");
    }
    printf("\n");
}

int posicao_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina, int codigo)
{
    for(int i = 0; i < quantidade_disciplina; i++)
    {
        if(lista_disciplina[i].codigo == codigo)
        {
            return i;
        }
    }
    return DISCIPLINA_NAO_ENCONTRADA;
}

int excluir_disciplina(Disciplina lista_disciplina[], int quantidade_disciplinas)
{
    listar_disciplina(lista_disciplina, quantidade_disciplinas);

    printf("\nDigite o codigo da disciplina que deseja excluir:\n");
    int codigo;
    scanf("%d", &codigo);

    int buscar_posicao_disciplina = posicao_disciplina(lista_disciplina, quantidade_disciplinas, codigo);

    if(buscar_posicao_disciplina == DISCIPLINA_NAO_ENCONTRADA)
    {
        return DISCIPLINA_NAO_ENCONTRADA;
    }
    else
    {
        int i = buscar_posicao_disciplina;
        for(; i < quantidade_disciplinas; i++)
        {
            lista_disciplina[i] = lista_disciplina[i + 1];
        }
        return SUCESSO_EXCLUSAO_DICIPLINA;
    }
}

int incluir_aluno_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina)
{
    int qtd = 0;
    
    printf("Adicionar alunos na disciplina:\n\n");

    printf("Digite a disciplina que deseja adicionar alunos usando o codigo dela:\n");
    int codigo;
    scanf("%d", &codigo);

    int posicao = posicao_disciplina(lista_disciplina, quantidade_disciplina, codigo);

    if(posicao == DISCIPLINA_NAO_ENCONTRADA)
    {
        return DISCIPLINA_NAO_ENCONTRADA;
    }
    else
    {
        printf("A disciplina é:\n%s\n", lista_disciplina[posicao].nome_disciplina);
        printf("Adicionar alunos:\n\n");

        int sair = 0;
        int opcao;
        
        while(!sair)
        {
            opcao = menu_disciplina_aluno();
          
            switch(opcao)
            {
                case 0:
                {
                    sair = 1;
                    break;
                }
                case 1:
                {
                    printf("Digite a matricula do aluno que deseja inserir:\n");
                    scanf("%d", &lista_disciplina[quantidade_disciplina].matricula_aluno);
                    system("clear");
                    printf("Aluno adicionado com sucesso\n");
                    qtd++;
                    break;
                }
                default:
                {
                    printf("opcao invalida");
                    break;
                }
            }

        }
    }
}

int menu_disciplina_aluno()
{
    int sair = 0;
    int opcao;

    printf("Digite a opcao:\n");
    printf("0 - Voltar\n");
    printf("1 - Adicionar aluno\n\n");

    printf("Opcao:");
    scanf("%d", &opcao);

    system("clear");

    return opcao;
}

int atualizar_disciplina(Disciplina lista_disciplina[], int quantidade_disciplina)
{
    listar_disciplina(lista_disciplina, quantidade_disciplina);

    printf("Digite o codigo da disciplina que deseja atualizar:\n");
    int codigo;
    scanf("%d", &codigo);

    int posicao_d = posicao_disciplina(lista_disciplina, quantidade_disciplina, codigo);

    if(posicao_d == DISCIPLINA_NAO_ENCONTRADA)
    {
        return DISCIPLINA_NAO_ENCONTRADA;
    }
    else
    {
        Disciplina disciplina_atualizada;
        getchar();

        printf("Dgite o novo nome da disciplina:\n");
        fgets(disciplina_atualizada.nome_disciplina, 50, stdin);

        size_t ln = strlen(disciplina_atualizada.nome_disciplina) - 1;
        if(disciplina_atualizada.nome_disciplina[ln] == '\n')
        {
            disciplina_atualizada.nome_disciplina[ln] = '\0';
        }

        printf("Digite o novo semestre da disciplina:\n");
        scanf("%d", &disciplina_atualizada.semestre);

        printf("Digite a nova matricula do professor que vai ministrar a disciplina:\n");
        scanf("%d", &disciplina_atualizada.professor_matricula);

        disciplina_atualizada.codigo = lista_disciplina[posicao_d].codigo;
        lista_disciplina[posicao_d] = disciplina_atualizada;

        system("clear");
    }

    return DISCIPLINA_ATUALIZADA_SUCESSO;
}
