#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h> // ��������� ������� 
void input(double *x,double *eps,int *limit); //  �� ��������� ������ ������
double variety(double x,double eps,int limit,int *i); // i - ������ 
double function(double x); // �� ��������� ������
void output(int limit,double s,double f,int i); // �� ��������� ������
int main(int argc, char* argv[])
{
  double x,eps,s,f; // �������
  int limit,i; 
  SetConsoleOutputCP(1251);
  printf("\t������� f(x) = sin(x)\n");
  printf("\t ��� E(-1)^n*x^2n+1/(2n+1)! ��� ��[-10;10]\n");
  printf("---------------------- ��� ����� ------------------\n");
  input(&x,&eps,&limit);// ��� ����� ������ ������ x,eps,limit
  s=variety(x,eps,limit,&i);// ���������� ���� , ������ ������ i
  f=function(x); // ��������� �������� ����� f
  output(limit,s,f,i); // ���� ���������� �� ���������� limit,s,f,i
  printf("\n\n");
  system("pause");
  return 0;
}
void input(double *x,double *eps,int *limit){ // ���������� ��� ������
  int ind; // �������� ����� �� ����������� �����
  ind = 1;
  while (ind) {
    fflush(stdin);
    printf("\t������ �������� � [-10;10]:");
    scanf_s("%lf",x);
    if(*x<-10 || *x>10) printf("\t������� �������� x �� � �������\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind) {
    fflush(stdin);
    printf("\t������ �������� eps: ");
    scanf_s("%lf",eps);
    if(*eps<=0 || *eps>=1) printf("\t������� �� ��������� �������� eps\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind){
    fflush(stdin);
    printf("\t������ �������� ����: ");
    scanf_s("%d",limit);
    if (*limit<=0) printf("\t�������� ������� �������� �� ���� >0\n\a");
    else ind = 0;
  }
}
double variety(double x,double eps,int limit,int *i) // ������� ���������� ���� , ������� �������� s
{ double an,s,x2;// ������� ����
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
double function(double x){ // ���������� ������� �������� �������, ������� �������� f
  double f; // �������� �����
  if (x==0) f=0;
  else f=sin(x);
  return f;
}
void output(int limit,double s,double f,int i){
  printf("----------------------����������------------------\n");
  if (i==limit)printf("\t���� ���������� �� ���� %d �������� ������� = %lf\n",limit,s);
  else printf("\t��������� �������� ������� �� %d �������� = %lf\n",i,s);
  printf("\t����� �������� ������� sin(x)= %lf \n",f);
  printf("\t������� � ����������� = %lf \n",fabs(f-s));
}