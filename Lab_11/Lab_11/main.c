#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#define limit 1000
void input (int *arr,int lenght){ // Самостійний ввід
  int i;
  for(i=1;i<=lenght;i++){
    printf("\tarr[%d] = ", i);
    scanf_s("%d", &arr[i]); // &a[i] - адрес i-го елемента масиву
  }
}
void randarr(int *arr,int lenght){ // Рандомний ввід елементів
  int i;
  srand(time(0));
  for(i=1;i<=lenght;i++){
    arr[i]=rand()%101-50;
    printf("\tarr[%d] = %d \n", i, arr[i]);
  }
}
void output (int *arr,int lenght){ // Виведення масиву
  int i;
  for(i=1;i<=lenght;i++){
    printf(" %d ", arr[i]);
  }
  printf("\n\n");
}
void processing(int *arr,int *min,int *n,int lenght,int *ind){ // Обробка масиву
  int i;
  *min = arr[1];
  for (i = 1; i <lenght; i++) {
    if (arr[i] <= *min) {*min = arr[i];*n=i;}
  }
}
int main () { 
  char d[2];
  int lenght,ind,min,n;
  int arr[limit];
  SetConsoleOutputCP(1251);
  printf("Введіть кількість елементів масиву (>0): \n");
  scanf_s("%d",&lenght);
  do { printf( "Заповнити масив самостійно? Y/N (Yes/No): \n");
  scanf("%s",&d);
  printf("————————————————————————————————\n\n");
  if(d[0] == 'y'){ 
    input(arr,lenght); ind = 0;
  } // самостійний ввід
  else if(d[0] == 'n'){  
    randarr(arr,lenght); ind = 0;
  } // рандомно
  else ind = 1;
  fflush(stdin);
  } while (ind);
  output(arr,lenght);
  processing(arr,&min,&n,lenght,&ind);
  printf("Знайдений мінімальний елемент = %d , номер елемента = %d \n\n",min,n);
  if (ind) // обробка 
    system("pause");
}
