/* Батін Олексій Олександрович, ТЕФ, ТМ-62, варіант №3. 
Лабораторна робота №11. Обробка одновимірних масивів*/
#define  _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h> // робота с Кирилицею
#include <time.h>
#define limit 1000 // ліміт елементів у масиві
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
void output (int *arr,int lenght){ // Виведення масиву 
  int i;
  printf("\n\t\t------------------------------------------\n\t\t");
  for(i=1;i<=lenght;i++){
    printf(" %d ", arr[i]); 
  }
  printf("\n\t\t------------------------------------------\n");
}
void processing(int *arr,int *min,int *n,int lenght,int *ind){ // Обробка масиву всі пар-и за адресою крім довжини
  int i,num=0,j=1; // Мінімальне значення
  // мінімальне значення 2ої половини
  if (lenght%2==0) i=(lenght/2)+1;
  else i=(lenght/2)+2;
  *min = arr[i];
  for(i;i<=lenght;i++){  
    if(arr[i]<= *min) {*min = arr[i]; *n=i;}
  }
  
  if(num%2==0 && *min<0){ // Обробка масиву
    for (i = 1; i <= lenght; i++) {
      if (arr[i]%2 == 0) { arr[j]=arr[i]; j++;} // спочатку масиву парні елемнти
    }
    for (j;j<=lenght;j++){arr[j]=0;} // заповнення масиву нулями
    *ind = 1;
  }

}
int main () { 
  char d[2]; // Підтвердження на другу обробку Так або Ні
  int lenght,ind,min,n;
  int arr[limit]; // Оголошення масиву
  SetConsoleOutputCP(1251); // Робота с Кирилицею
  ind = 1; // true/false
  while (ind){
    fflush(stdin); // Очищення буферу вводу 
    do { printf("\tВведіть кількість елементів масиву (>0): \n");
    scanf_s("%d",&lenght); 
    if (lenght>0 && lenght<limit) ind = 0; } // Перевірка правильності вводу
    while (ind);
    do { printf( "\tЗаповнити масив самостійно? y/n (Yes/No): \n");
    scanf("%s",&d);
    printf("————————————————————————————————\n\n");
    if(d[0] == 'y'){ // Самостійний чи рандомний ввід елементів
      input(arr,lenght); ind = 0;
    } // самостійний ввід
    else if(d[0] == 'n'){  
      randarr(arr,lenght); ind = 0;
    } // рандомно
    fflush(stdin);
    } while (ind);
    output(arr,lenght); // функція для виведення масиву
    processing(arr,&min,&n,lenght,&ind); // обробка масиву
    printf("\tЗнайдений мінімальний елемент = %d , номер елемента = %d \n\n",min,n);
    if (ind) {printf("\tОбробку масиву виконано \n "); output(arr,lenght);} // Перевірка чи було виконано обробку масиву 
    else printf("\tОбробку не виконано\n");
    printf("Обробити інший масив? y (Yes): \n"); // Повторна обробка
    scanf("%s",&d);
    if(d[0] =='y' ) ind = 1;
    else ind = 0;}
    system("pause");
  }
