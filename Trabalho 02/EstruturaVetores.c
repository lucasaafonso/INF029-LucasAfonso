#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct vetores
{
int *vetorAuxiliar;
int qtd;
int tamanho;
}Vetores;

Vetores vetorPrincipal[TAM];

typedef struct i
{
    int indice;
}i;

i tamanhoEstruturaTodos;

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    // se posição é um valor válido {entre 1 e 10}
    if(posicao < 1 || posicao > 10)
      return POSICAO_INVALIDA;
    // a posicao pode já existir estrutura auxiliar
    if(vetorPrincipal[posicao].vetorAuxiliar != NULL)
      return JA_TEM_ESTRUTURA_AUXILIAR;
    // o tamanho nao pode ser menor que 1
    if(tamanho < 1)
      return TAMANHO_INVALIDO;
    // o tamanho ser muito grande
    vetorPrincipal[posicao].vetorAuxiliar = malloc(tamanho * sizeof(int));
    if(vetorPrincipal[posicao].vetorAuxiliar == NULL)
      return SEM_ESPACO_DE_MEMORIA;
    // deu tudo certo, crie
    vetorPrincipal[posicao].tamanho = tamanho;
    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int temEspaco = 0;
    int posicao_invalida = ehPosicaoValida(posicao);

    if (posicao_invalida == POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (vetorPrincipal[posicao].vetorAuxiliar != NULL)
        {
            if (vetorPrincipal[posicao].qtd < vetorPrincipal[posicao].tamanho)
            {
                //insere
                vetorPrincipal[posicao].vetorAuxiliar[vetorPrincipal[posicao].qtd] = valor;
                vetorPrincipal[posicao].qtd++;
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    if(posicao < 1 || posicao > 10)
      return POSICAO_INVALIDA;
  
    if(vetorPrincipal[posicao].vetorAuxiliar == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

    if(vetorPrincipal[posicao].qtd == 0)
      return ESTRUTURA_AUXILIAR_VAZIA;
    
    vetorPrincipal[posicao].qtd--;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if(posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    if(vetorPrincipal[posicao].vetorAuxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if(vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    int numeroEncontrado = 0;
    int tamanho = vetorPrincipal[posicao].qtd;

    for(int i = 0; i < tamanho; i++)
    {
        if(vetorPrincipal[posicao].vetorAuxiliar[i] == valor)
        {
            numeroEncontrado = 1;
            break;
        }
    }

    if(!numeroEncontrado)
        return NUMERO_INEXISTENTE;

    int i;
    for(i = 0; i < tamanho; i++)
    {
        if(vetorPrincipal[posicao].vetorAuxiliar[i] == valor)
            break;
    }

    for(int j = i; j < tamanho - 1; j++)
    {
        vetorPrincipal[posicao].vetorAuxiliar[j] = vetorPrincipal[posicao].vetorAuxiliar[j + 1];
    }

    vetorPrincipal[posicao].qtd--;

    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(posicao < 1 || posicao > 10)
      return POSICAO_INVALIDA;

    if(vetorPrincipal[posicao].vetorAuxiliar == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

    for(int i = 0; i < vetorPrincipal[posicao].qtd; i++)
    {
        vetorAux[i] = vetorPrincipal[posicao].vetorAuxiliar[i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    if(posicao < 1 || posicao > 10)
      return POSICAO_INVALIDA;

    if(vetorPrincipal[posicao].vetorAuxiliar == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

    for(int i = 0; i < vetorPrincipal[posicao].qtd; i++)
    {
        vetorAux[i] = vetorPrincipal[posicao].vetorAuxiliar[i];
    }

    for(int i = 0; i < vetorPrincipal[posicao].qtd; i++)
    {
        for(int j = 0; j < vetorPrincipal[posicao].qtd - 1; j++)
        {
            if(vetorAux[j] > vetorAux[j + 1])
            {
                int aux = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = aux;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int indice = 0;
    int todasVazias = 1;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vetorAuxiliar != NULL && vetorPrincipal[i].qtd > 0)
        {
            todasVazias = 0;

            for (int j = 0; j < vetorPrincipal[i].qtd; j++)
            {
                vetorAux[indice] = vetorPrincipal[i].vetorAuxiliar[j];
                indice++;
            }
        }
    }

    tamanhoEstruturaTodos.indice = indice;

    if (todasVazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else
        return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
    int indice = 0;
    int todasVazias = 1;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i].vetorAuxiliar != NULL && vetorPrincipal[i].qtd > 0)
        {
            todasVazias = 0;

            for (int j = 0; j < vetorPrincipal[i].qtd; j++)
            {
                vetorAux[indice] = vetorPrincipal[i].vetorAuxiliar[j];
                indice++;
            }
        }
    }

    if (todasVazias)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    for (int i = 0; i < indice - 1; i++)
    {
        for (int j = 0; j < indice - 1 - i; j++)
        {
            if (vetorAux[j] > vetorAux[j + 1])
            {
                int aux = vetorAux[j];
                vetorAux[j] = vetorAux[j + 1];
                vetorAux[j + 1] = aux;
            }
        }
    }

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao].vetorAuxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoAtual = vetorPrincipal[posicao].tamanho;
    int tamanhoNovo = tamanhoAtual + novoTamanho;

    if (tamanhoNovo <= 0)
        return NOVO_TAMANHO_INVALIDO;

    int *novoVetor = realloc(vetorPrincipal[posicao].vetorAuxiliar, tamanhoNovo * sizeof(int));
    if (novoVetor == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao].vetorAuxiliar = novoVetor;
    vetorPrincipal[posicao].tamanho = tamanhoNovo;

    if(tamanhoNovo < vetorPrincipal[posicao].qtd)
    {
        vetorPrincipal[posicao].qtd = tamanhoNovo;
    }

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
    if (posicao < 1 || posicao > 10)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao].vetorAuxiliar == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao].qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return vetorPrincipal[posicao].qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    int j = tamanhoEstruturaTodos.indice;

    int vetoraux[j];

    getDadosDeTodasEstruturasAuxiliares(vetoraux);                                                                                                                                  

    No *inicio = (No*) malloc(sizeof(No));
    inicio->prox = NULL;

    No *atual = inicio;

    for(int i = 0; i <= j; i++)
    {
        No *novo = (No*) malloc(sizeof(No));
        novo->conteudo = vetoraux[i];
        novo->prox = NULL;
        atual->prox = novo;
        atual = novo;
    }

    return inicio;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    No *atual = inicio->prox;
    int i = 0;
    while (atual != NULL)
    {
        vetorAux[i] = atual->conteudo;
        atual = atual->prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No* atual = *inicio;
    while (atual != NULL)
    {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for(int i = 0; i < TAM; i++)
  {   
    vetorPrincipal[i].vetorAuxiliar = NULL;
    vetorPrincipal[i].qtd = 0;
    vetorPrincipal[i].tamanho = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    free(vetorPrincipal->vetorAuxiliar);
}
