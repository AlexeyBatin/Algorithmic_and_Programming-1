/* ���� ������ �������������. ��-62. ������ 3. 
����������� ������ �9.  ������������ ����������� ��������� */
#include <Windows.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
int main () {
  double x,an,s,eps,f,x2;
  int limit,i,ind;
  SetConsoleOutputCP(1251);
  printf("\t\t���������� �������� ������� F(x)\n\n");
  printf("\t ������� f(x) = sin(x)\n");
  printf("\t ��� E(-1)^n*x^2n+1/(2n+1)! ��� ��[-10;10]\n");
  printf("----------------------------------------------------------\n");
  ind = 1;
  while (ind) {
    printf("\t������ �������� � [-10;10]: ");
    scanf_s("%lf",&x);
    if(x<-10 || x>10) printf("\t������� �������� x �� � �������\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind) {
    printf("\t������ �������� eps: ");
    scanf_s("%lf",&eps);
    if(eps<=0 || eps>=1) printf("\t������� �� ��������� �������� eps\n\a");
    else ind = 0;
  }
  ind=1;
  while (ind){
    printf("\t������ �������� ����: ");
    scanf_s("%d",&limit);
    if (limit<=0) printf("\t�������� ������� �������� �� ���� >0\n\a");
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
  printf("----------------------����������------------------\n");
  if (i==limit)printf("\t���� ���������� �� ���� %d �������� ������� = %lf\n",limit,s);
  else printf("\t��������� �������� ������� �� %d �������� = %lf\n",i,s);
  f=sin(x);
  printf("\t����� �������� ������� sin(x)= %lf \n",f);
  printf("\t������� � ����������� = %lf \n",fabs(f-s));
  system("pause");
  return 0;
}

