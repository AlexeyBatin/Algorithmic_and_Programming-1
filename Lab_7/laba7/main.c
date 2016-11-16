/* Батін Олексій Олександрович. ТМ-62. Варінат №3. Лабораторна робота №7.
 Проектування алгоритмів і програм циклічної структури (передумовою і післяумовою).*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
int main () {
  double x1,x2,h,// Границі проміжка і крок
    a,b,x, // параметри а і б , змінна х
    f; // Обчислення функції
  double eps = 1e-5;
  char r1[62] = "-------------------------------------------------------------",
       r2[21] = "|   x    |   f(x)   ";
  int ind , // індифікатор 
    i,  // номер обчисленого значенння
    k=3;  // кількість пар колонок
  SetConsoleOutputCP(1251);
  printf("Табулювання функції:\n");
  printf("\tf(x)=sqrt(x+a)/sin(x-b)+cos(|x|)\n");
  do {
    fflush(stdin);
    printf("Вкажіть проміжок х1,х2:");
    scanf("%lf,%lf",&x1,&x2);
    if(x1>x2) {
      printf("Введено не вірний проміжок  (x1>x2) \n\a ");
      printf("[%g , %g]\n",x1,x2);
      ind = 1;
    }
    else {
      printf("Вкажіть крок h:");
      scanf("%lf",&h);
      if (h>x2-x1 || h<=0) {
        printf("Помилка h>x2-x1 або h<=0 \n\a");
        ind = 1;}
      else ind = 0;
    }
  } while (ind);
  printf("Введіть значення параметрів a i b (Значення вводяться через пробіл):");
  scanf("%lf %lf",&a,&b);
  printf("%s\n",r1);
  printf("%s%s%s|\n",r2,r2,r2);
  printf("%s\n",r1);
  x=x1;
  i=0;
  while (x<=x2+eps){
    i++;ind=1;
    printf("| %6.2lf",x);
    if (x+a<0 || fabsl(sin(x-b))<eps) printf(" |  не визн ");
    else { f=(sqrt(x+a)/sin(x-b))+cos(fabs(x)); 
    if(fabs(f)>10) printf(" |  переповн");
    else printf(" | %8.2lf ",f);
    } // else
    if (i%k==0) printf("|\n");
    x+=h;
  }// while
  if (i%k!=0) { // Закінчуємо таблицю 
    while (i%k != 0) {
      printf("|        |          ");
      i++;
    } // while в if
    printf("|\n");
  }
  printf("%s\n\n",r1); 
  system("pause");
  return 0;
}