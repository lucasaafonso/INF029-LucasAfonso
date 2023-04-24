// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome: Lucas de Araújo Afonso
//  email: lucasaafonso103@gmail.com
//  Matrícula: 20201160030
//  Semestre: 2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "LucasAfonso20201160030.h" // Substitua pelo seu arquivo de header renomeado
#include "ctype.h"
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ 
  // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a)
{
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

DataQuebrada quebraData(char data[])
{
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
/*
FEITO
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */

int bissexto(int ano)
{
  return ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0);
}

int q1(char data[])
{
  DataQuebrada dq = quebraData(data);

  if (!dq.valido)
    return 0;

  int dia_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int ano = dq.iAno + 2000;

  if (bissexto(ano))
    dia_mes[2] = 29;

  if (dq.iMes < 1 || dq.iMes > 12)
    return 0;

  if (dq.iDia < 1 || dq.iDia > dia_mes[dq.iMes])
    return 0;

  return 1;
}

/*
FEITO
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;
  DataQuebrada dataI = quebraData(datainicial);
  DataQuebrada dataF = quebraData(datafinal);

  if (q1(datainicial) == 0) {
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3;
    return dma;
  } else if(dataI.iAno > dataF.iAno || dataI.iDia > dataF.iDia || dataI.iMes > dataF.iMes){
      dma.retorno = 4;
      return dma;
    }

    dma.qtdAnos = dataF.iAno - dataI.iAno;
    dma.qtdDias = dataF.iDia - dataI.iDia;
    dma.qtdMeses = dataF.iMes - dataI.iMes;

    // se tudo der certo
    dma.retorno = 1;
    return dma;
}

/*
FEITO
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
  int qtdOcorrencias = 0;

  while (*texto != '\0') {
    if (isCaseSensitive == 1) {
      if (*texto == c) {
        qtdOcorrencias++;
      }
    } else {
      if (tolower(*texto) == tolower(c)) {
        qtdOcorrencias++;
      }
    }

    texto++;
  }

  return qtdOcorrencias;
}

/*
FEITO
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
  int qtdOcorrencias = 0;
  
  int tamTexto = strlen(strTexto);
  int tamBusca = strlen(strBusca);
  int posicaoInicial = 0;
  int posicaoFinal = 0;
  int aux = 0;
  int acento = 0;
  int j;

  for (int i = 0; i < tamTexto; i++)
  {
    if(strTexto[i] < 0)
      {
        acento++;
        acento = acento - (acento - 2);
      }
    if (strTexto[i] == strBusca[0])
    {
      for (j = 0; j < tamBusca;)
      {
        if (strTexto[i] != strBusca[j])
        {
          break;
        }
        i++;
        j++;
      }
      if (j == tamBusca)
      {
        qtdOcorrencias++;
        posicaoInicial = i - j - acento + 1;
        posicaoFinal = i - acento;
        posicoes[aux] = posicaoInicial;
        aux++;
        posicoes[aux] = posicaoFinal;
        aux++;
      } 
    }
  }
  return qtdOcorrencias;
}

/*
FEITO
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
  int aux;
  int reverso = 0;

  while (num != 0)
  {
    aux = num % 10;
    reverso = reverso * 10 + aux;
    num /= 10;
  }

  num = reverso;

  return num;
}

/*
FEITO
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias = 0;

  while (numerobase > 0)
  {
    if (numerobusca == numerobase % 10)
    {
      qtdOcorrencias++;
    } 
    else if (numerobusca == numerobase % 100)
    {
      qtdOcorrencias++;
    }

    numerobase /= 10;
  }

  return qtdOcorrencias;
}
