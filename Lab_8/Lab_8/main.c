/* Батін Олексій Олександрович. ТМ-62. Варінат №3. Лабораторна робота №8.
 Проектування алгоритмів і програм з вкладеними циклами*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
int main () {
  double x1,x2,h,// Границі проміжка і крок
    n,x, // параметр n , змінна х
    f,sum,an; // Обчислення функції,суми
  double eps = 1e-5;
  char r1[62] = "-------------------------------------------------------------",
    r2[21] = "|   x    |   f(x)   ";
  int ind , // індифікатор 
    i,  // номер обчисленого значенння
    k=3;  // кількість пар колонок
  SetConsoleOutputCP(1251);
  printf("Табулювання функції:\n");
  printf("\tf(x)=sqrt((x+1)/(x-3))*(3^n+x)/(n-1)+ln(x+4), де n=[2,5]\n");
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
  printf("%s\n",r1);
  printf("%s%s%s|\n",r2,r2,r2);
  printf("%s\n",r1);
  x=x1;
  i=0;
  while (x<=x2+eps){+
    i++;
    printf("| %6.2lf",x);
    if ( (x+4)<=eps || fabs(x-3)<eps || ((x+1)/(x-3)<0)  ) printf(" |  не визн ");
    else { 
      sum=0;
      an=3;
      for(n=2;n<=5;n++){
        an*=3;
        sum+=(an+x)/(n-1);
      }
      f=sum*sqrt((x+1)/(x-3))+log(x+4); 
      if(fabs(f)>350) printf(" |  переповн");
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