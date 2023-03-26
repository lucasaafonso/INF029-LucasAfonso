#include <stdio.h>

int fat(int a)
{
  int fat;

  if(a < 0)
  {
    return -1;
  }

  if (a == 0 || a == 1)
  {
    return 1;
  }

  else
  {
    for (fat = 1; a > 1; a = a - 1)
    {
      fat = fat * a;
    }
    return fat;
  }
}

int main()
{
  int num;
  int resultado;

  printf("Digite o numero que deseja:\n");
  scanf("%d", &num);

  resultado = fat(num);

  if(resultado == -1)
  {
    printf("Nao e possivel calcular esse fatorial");
  }
  else
  {
    printf("O fatorial é: %d", resultado);
  }
}