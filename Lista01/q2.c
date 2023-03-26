#include <stdio.h>

int sub (int a, int b)
{
  int subtracao;

  subtracao = a - b;

  return subtracao;
}

int main ()
{
  int num1, num2;
  int resultado;

  printf("Digite o numero que deseja subtrair:\n");
  scanf("%d", &num1);
  printf("Digite outro numero que deseja subtrair:\n");
  scanf("%d", &num2);

  resultado = sub(num1, num2);

  printf("A subtracao é: %d", resultado);
}