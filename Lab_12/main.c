#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#define limit 1000
void input (int *arr,int lenght){ // Самостійний ввід
  int i;
  for(i=0;i<lenght;i++){
    printf("\tarr[%d] = ", i);
    scanf_s("%d", &arr[i]); // &a[i] - адрес i-го елемента масиву
  }
  printf("\n");
}
void randarr(int *arr,int lenght){ // Рандомний ввід елементів
  int i;
  srand(time(0));
  for(i=0;i<lenght;i++){
    arr[i]=rand()%101-50;
    printf("\tarr[%d] = %d \n", i, arr[i]);
  }
  printf("\n");
}
void output (int *arr,int lenght){ // Виведення масиву
  int i;
  printf("\n\t\t------------------------------------------\n\t\t");
  for(i=0;i<lenght;i++){
    printf(" %d ", arr[i]);
  }
  printf("\n\t\t------------------------------------------\n");
}

void sort(int *arr, int length, int *ind) // сортування вставками
{
  int temp, // тимчасова змінна для зберігання значення елемента сортованого масиву
    item, // елемент масиву
    i; // лічильник
  for (i = 1; i < length; i++)
  {
    temp = arr[i]; // ініціалізуємо тимчасову змінну поточним значенням елемента масиву
    item = i-1; // запам'ятовуємо індекс попереднього елемента масиву
    while(item >= 0 && arr[item] < temp) // поки індекси не дорівнює 0 і попередній елемент масиву менше поточного
    {
      arr[item + 1] = arr[item]; // перестановка елементів масиву
      arr[item] = temp;
      item--;
    }
    output(arr,length);
  }
  *ind=1;
}
int main () { 
  char d[2];
  int lenght,ind;
  int arr[limit]; 
  SetConsoleOutputCP(1251);
  ind = 1;
  while (ind) {
    fflush(stdin);
    do { printf("\tВведіть кількість елементів масиву (>0): \n");
    scanf_s("%d",&lenght);
    if (lenght>0 && lenght<limit) ind = 0; }
    while (ind);
    do { printf( "\tЗаповнити масив самостійно? y/n (Yes/No): \n");
    scanf("%s",&d);
    printf("————————————————————————————————\n\n");
    if(d[0] == 'y'){ 
      input(arr,lenght); ind = 0;
    } // самостійний ввід
    else if(d[0] == 'n'){  
      randarr(arr,lenght); ind = 0;
    } // рандомно
    fflush(stdin);
    } while (ind);
    output(arr,lenght);
    sort(arr,lenght,&ind);
    // обробка 
    if (ind) {printf("\tОбробку масиву виконано \n "); output(arr,lenght);}
    else printf("\tОбробку не виконано\n");
    printf("Обробити інший масив? y (Yes): \n");
    scanf("%s",&d);
    if(d[0] =='y' ) ind = 1;
    else ind = 0;}
  system("pause");
}
