#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h> // Прототипи функцій 
void input(double *x,double *eps,int *limit); //  всі параметри адреси змінних
double variety(double x,double eps,int limit,int *i); // i - адреса 
double function(double x); // за значенням змінних
void output(int limit,double s,double f,int i); // за значенням змінних
int main(int argc, char* argv[])
{
  double x,eps,s,f; // локальні
  int limit,i; 
  SetConsoleOutputCP(1251);
  printf("\tФункція f(x) = sin(x)\n");
  printf("\t Ряд E(-1)^n*x^2n+1/(2n+1)! при хє[-10;10]\n");
  printf("---------------------- Ввід даних ------------------\n");
  input(&x,&eps,&limit);// Ввід даних беремо адресу x,eps,limit
  s=variety(x,eps,limit,&i);// Обчислення ряду , беремо адресу i
  f=function(x); // Присвоєння значенню змінної f
  output(limit,s,f,i); // Вивід результатів за значеннями limit,s,f,i
  printf("\n\n");
  system("pause");
  return 0;
}
void input(double *x,double *eps,int *limit){ // Правильний ввід данних
  int ind; // локальна змінна на правильність вводу
  ind = 1;
  while (ind) {
    fflush(stdin);
    printf("\tВкажіть значення х [-10;10]:");
    scanf_s("%lf",x);
    if(*x<-10 || *x>10) printf("\tВказали значення x не з проміжку\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind) {
    fflush(stdin);
    printf("\tВкажіть значення eps: ");
    scanf_s("%lf",eps);
    if(*eps<=0 || *eps>=1) printf("\tВказано не правильне значення eps\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind){
    fflush(stdin);
    printf("\tВкажіть значення ліміту: ");
    scanf_s("%d",limit);
    if (*limit<=0) printf("\tГранична кількість ітерацій має бути >0\n\a");
    else ind = 0;
  }
}
double variety(double x,double eps,int limit,int *i) // Функція обчислення ряду , повертає значення s
{ double an,s,x2;// локальні змінні
*i=0;
an=x;
s=an;
x2=x*x/2;
do {
  (*i)++;  
  an*=-x2/((*i)*((*i)*2+1));
  s+=an; 
} while (fabs(an)>eps && *i<limit); 
return s;
}
double function(double x){ // Обчислення точного значення функції, повертає значення f
  double f; // локальна змінна
  if (x==0) f=0;
  else f=sin(x);
  return f;
}
void output(int limit,double s,double f,int i){
  printf("----------------------Результати------------------\n");
  if (i==limit)printf("\tЦикл заверешено по ліміту %d значення функції = %lf\n",limit,s);
  else printf("\tОбчислене значення функції за %d ітерацій = %lf\n",i,s);
  printf("\tТочне значення функції sin(x)= %lf \n",f);
  printf("\tПохибка у вимірюваннях = %lf \n",fabs(f-s));
}