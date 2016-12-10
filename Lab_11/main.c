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
  printf("\n");
}
void randarr(int *arr,int lenght){ // Рандомний ввід елементів
  int i;
  srand(time(0));
  for(i=1;i<=lenght;i++){
    arr[i]=rand()%101-50;
    printf("\tarr[%d] = %d \n", i, arr[i]);
  }
  printf("\n");
}
void output (int *arr,int lenght){ // Виведення масиву (масив за ад)
  int i;
  printf("\n\t\t------------------------------------------\n\t\t");
  for(i=1;i<=lenght;i++){
    printf(" %d ", arr[i]);
  }
  printf("\n\t\t------------------------------------------\n");
}
void processing(int *arr,int *min,int *n,int lenght,int *ind){ // Обробка масиву всі пар-и за адресою крім довжини
  int i,num=0,j=1; // Мінімальне значення
  /**min = arr[1];
  for (i = 1; i <=lenght; i++) {
    if (arr[i] <= *min) {*min = arr[i];*n=i;}
  }*/
  // мінімальне значення 2ої половини
  if (lenght%2==0) i=(lenght/2)+1;
  else i=(lenght/2)+2;
  *min = arr[i];
  for(i;i<=lenght;i++){  
    if(arr[i]<= *min) {*min = arr[i]; *n=i;}
  }
  
  if(num%2==0 && *min<0){ // Обробка масиву
    for (i = 1; i <= lenght; i++) {
      if (arr[i]%2 == 0) { arr[j]=arr[i]; j++;}
    }
    for (j;j<=lenght;j++){arr[j]=0;}
    *ind = 1;
  }

}
int main () { 
  char d[2];
  int lenght,ind,min,n;
  int arr[limit];
  SetConsoleOutputCP(1251);
  ind = 1;
  while (ind){
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
    processing(arr,&min,&n,lenght,&ind);
    printf("\tЗнайдений мінімальний елемент = %d , номер елемента = %d \n\n",min,n);
    // обробка 
    if (ind) {printf("\tОбробку масиву виконано \n "); output(arr,lenght);}
    else printf("\tОбробку не виконано\n");
    printf("Обробити інший масив? y (Yes): \n");
    scanf("%s",&d);
    if(d[0] =='y' ) ind = 1;
    else ind = 0;}
    system("pause");
  }
