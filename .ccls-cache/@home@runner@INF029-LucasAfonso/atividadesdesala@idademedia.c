#include <stdio.h>

int main ()
{
  int n;
  float media;
  int soma = 0;

  printf("Digite a quantidade de idades que deseja inserir:\n");
  scanf("%d", &n);

  int idade[n];

  for (int i = 0; i < n; i++)
    {
      printf("Digite uma idade:\n");
      scanf("%d", &idade[i]);
    }
  for (int i = 0; i < n; i++)
    {
      soma = soma + idade[i];
    }
  media = soma / n;

  printf("Media: %f\n", media);

  printf("Idades maiores que a media:\n");

  for (int i = 0; i < n; i++)
    {
      if(idade[i] > media)
      {
        printf("%d\n", idade[i]);
      }
    }
}
