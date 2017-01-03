/* Лабораторна робота №13. Обробка двовимірних масивів. 
Батін Олексій Олександрович. ТМ-62. Варіант №3 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define N 100

void processing(int a[N][N], int n, int* counter, int* elements) // Обробка масиву 
{
  int i, j, jr;
  *counter = 0;
  *elements = 0;
  for (i = 0; i < n; i++)
  {
    if (i < (n + 1) / 2) jr = n - i;
    else jr = i;
    for (j = jr; j < n; j++) if ((a[i][j]) % 2 == 0) *counter += 1;
  }
   // Розрахунки в 9-му секторі
    for (i = n/2; i < n; i++)
      for (j = 0; j < n; j++)
      {
        a[i][j] = 0;
        *elements += 1;
      } // заміна елементів на нулі і лічильник
  
}

void randarr(int a[N][N], int n) // Заповнення матриці рандомними значенями 
{
   int i, j; 
  srand(time(0));
  for (i = 0; i < n; i++) // цикл по рядках
  {
    for (j = 0; j < n; j++) // цикл по стовпцях
    {
      a[i][j] = rand() % 101 - 50;
      printf("\tarr[%d][%d] = %d \n", i,j, a[i][j]);
    }
  }
}

void output(int a[N][N], int n) // Виведення матриці
{
  int i, j;
  printf("\n\n");
  for (i = 0; i < n; i++) // цикл по рядках
  {
    for (j = 0; j < n; j++) // цикл по стовпцях
    {
      if (i + j > n - 1 && i - j <= 0) printf("%5d*", a[i][j]);
      else printf("%5d ", a[i][j]); // 5 знаків під елемент масиву
    }
    printf("\n");
  }
  printf("\n\n");
}

void input(int a[N][N], int n) // Самостійний ввід матриці
{
  int i, j;
  for (i = 0; i < n; i++) // цикл по рядках
  {
    for (j = 0; j < n; j++) // цикл по стовпцях
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%d", &a[i][j]);
    }
  }
}

int main()
{
  int a[N][N];
  int n, ind, counter, elements; // n - розмірність , ind - індифікатор , counter&elements - лічильники
  char d[2];
  SetConsoleOutputCP(1251);
  ind = 1;
  while (ind)
  {
    fflush(stdin); // Очищення буферу вводу
    do
    {
      printf("\tВведіть розмір матриці : ");
      scanf("%d", &n);
      if (n > 0 && n < N) ind = 0;
    }
    while (ind);
    do
    {
      printf("\tЗаповнити масив самостійно? y/n (Yes/No): \n");
      scanf("%s", &d);
      printf("————————————————————————————————\n\n");
      if (d[0] == 'y')
      {
        input(a, n);
        ind = 0;
      } // самостійний ввід
      else if (d[0] == 'n')
      {
        randarr(a, n);
        ind = 0;
      } // рандомно
      fflush(stdin);
    }
    while (ind);
    printf("\n \t Початковий вигляд матриці");
    output(a, n); // Вивід елементів матриці
    processing(a, n, &counter, &elements);
    printf("\n \t Вигляд матриці після обробок");
    output(a, n);
    printf("————————————————————————————————\n\n");
    printf("\n Кількість парних елементів у 3 секторі: %d \n", counter);
    printf("\n Кількість елементів у 9 секторі: %d \n", elements);
    printf("————————————————————————————————\n\n");
    printf("\tОбробити іншу матрицю? y (Yes): \n");
    scanf("%s", &d);
    if (d[0] == 'y')
    {
      ind = 1;
      system("cls");
    } // очищує консоль
    else ind = 0;
  }
  system("pause");
  return 0;
}
