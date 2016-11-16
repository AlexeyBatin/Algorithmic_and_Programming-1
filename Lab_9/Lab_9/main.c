/* Батін Олексій Олександрович. ТМ-62. Варіант 3. 
Лабораторна робота №9.  Проектування ітераційних алгоритмів */
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int main () {
  double x,an,s,eps,f,x2;
  int limit,i,ind;
  SetConsoleOutputCP(1251);
  printf("\t\tОбчислення значення функції F(x)\n\n");
  printf("\t Функція f(x) = sin(x)\n");
  printf("\t Ряд E(-1)^n*x^2n+1/(2n+1)! при хє[-10;10]\n");
  printf("----------------------------------------------------------\n");
  ind = 1;
  while (ind) {
    printf("\tВкажіть значення х [-10;10]: ");
    scanf_s("%lf",&x);
    if(x<-10 || x>10) printf("\tВказали значення x не з проміжку\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind) {
    printf("\tВкажіть значення eps: ");
    scanf_s("%lf",&eps);
    if(eps<=0 || eps>=1) printf("\tВказано не правильне значення eps\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind){
    printf("\tВкажіть значення ліміту: ");
    scanf_s("%d",&limit);
    if (limit<=0) printf("\tГранична кількість ітерацій має бути >0\n\a");
    else ind = 0;
  }
  i=0;
  an=x;
  s=an;
  x2=x*x/2;
  do {
    i++;  
    an*=-x2/(i*(i*2+1));
    s+=an; 
  } while (fabs(an)>eps && i<limit); 
  printf("----------------------Результати------------------\n");
  if (i==limit)printf("\tЦикл заверешено по ліміту %d значення функції = %lf\n",limit,s);
  else printf("\tОбчислене значення функції за %d ітерацій = %lf\n",i,s);
  f=sin(x);
  printf("\tТочне значення функції sin(x)= %lf \n",f);
  printf("\tПохибка у вимірюваннях = %lf \n",fabs(f-s));
  system("pause");
  return 0;
}

