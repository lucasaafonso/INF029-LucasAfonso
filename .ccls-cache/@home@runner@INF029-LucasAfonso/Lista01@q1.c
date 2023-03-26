#include <stdio.h>

int soma (int a, int b)
{
  int soma;

  soma = a + b;

  return soma;
}

int main ()
{
  int num1, num2;
  int resultado;

  printf("Digite o numero que deseja somar:\n");
  scanf("%d", &num1);
  printf("Digite outro numero que deseja somar:\n");
  scanf("%d", &num2);

  resultado = soma(num1, num2);

  printf("A soma é: %d", resultado);
}