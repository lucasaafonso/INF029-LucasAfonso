#include <stdio.h>

int ler3Numeros()
{
  int num[2];

  for(int i = 0; i < 3; i++)
  {
    printf("Digite o numero que deseja inserir:\n");
    scanf("%d", &num[i]);
  }
}

int main()
{
  int num[2];
  ler3Numeros();

  for(int i = 0; i < 3; i++)
  {
    printf("O numero inserido:/n%d", num[i]);
  }
}