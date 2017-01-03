/* Лабораторна робота №14. Обробка рядків. 
Батін Олексій Олександрович. ТМ-62. Варіант №3 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#define N 250
void input (char str[],int *i)
{
  *i = -1;
  while (*i<N-1 && str[(*i)]!='!'){
    (*i)++;
    str[(*i)] = getchar();
  }
  str[(*i)] = ' ';
  str[(*i)+1] = '\0';
}
void new_text (char str[],int i)
{
  int j=1,k,p;
  char symbols[] = {'б','в','г','ґ','д','ж','з','й','к','л','м','н','п','р','с','т','ф','х','ц','ч','ш','щ','й'};
  while (j<i+1)
  {
    for(k=0;k<sizeof(symbols);k++)
    {
      if (str[j-1] == ' ' || str[j-1] == '\n' || str[j-1] == '"') ;
      else if((str[j] == '"') && str[j+1] == symbols[k]) {
        for (p = j; p < i+1 ; p++)
          str[p] = str[p + 1];
      }
    }
    j++;
  }

}
int main () {


  char d[2];
  char str[N+1];
  int i,j,ind=1;
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  while (ind) {
    printf("Введіть початковий текст:\n\t");
    input(str,&i);
    new_text(str,i);
    printf("\nТекст після обробки:\n");
    printf("\t");
    for (j=0;j<i+1;j++)
      printf("%c",str[j]);
    printf("\n");
    fflush(stdin);
    printf("\n\tБажаєте обробити ще один рядок? y (Yes): \n");
    scanf("%s", &d);
    if (d[0] == 'y')
    {
      ind = 1;
      system("cls");
      fflush(stdin);
    } // очищує консоль
    else ind = 0;
  }
  system("pause");
  return 0;

}
