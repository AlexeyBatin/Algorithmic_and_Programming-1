/* ���� ������ �������������. ��-62. ������ �3. ����������� ������ �8.
 ������������ ��������� � ������� � ���������� �������*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
int main () {
  double x1,x2,h,// ������� ������� � ����
    n,x, // �������� n , ����� �
    f,sum,an; // ���������� �������,����
  double eps = 1e-5;
  char r1[62] = "-------------------------------------------------------------",
    r2[21] = "|   x    |   f(x)   ";
  int ind , // ����������� 
    i,  // ����� ����������� ���������
    k=3;  // ������� ��� �������
  SetConsoleOutputCP(1251);
  printf("����������� �������:\n");
  printf("\tf(x)=sqrt((x+1)/(x-3))*(3^n+x)/(n-1)+ln(x+4), �� n=[2,5]\n");
  do {
    fflush(stdin);
    printf("������ ������� �1,�2:");
    scanf("%lf,%lf",&x1,&x2);
    if(x1>x2) {
      printf("������� �� ����� �������  (x1>x2) \n\a ");
      printf("[%g , %g]\n",x1,x2);
      ind = 1;
    }
    else {
      printf("������ ���� h:");
      scanf("%lf",&h);
      if (h>x2-x1 || h<=0) {
        printf("������� h>x2-x1 ��� h<=0 \n\a");
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
    if ( (x+4)<=eps || fabs(x-3)<eps || ((x+1)/(x-3)<0)  ) printf(" |  �� ���� ");
    else { 
      sum=0;
      an=3;
      for(n=2;n<=5;n++){
        an*=3;
        sum+=(an+x)/(n-1);
      }
      f=sum*sqrt((x+1)/(x-3))+log(x+4); 
      if(fabs(f)>350) printf(" |  ��������");
      else printf(" | %8.2lf ",f);
    } // else
    if (i%k==0) printf("|\n");
    x+=h;
  }// while
  if (i%k!=0) { // �������� ������� 
    while (i%k != 0) {
      printf("|        |          ");
      i++;
    } // while � if
    printf("|\n");
  }
  printf("%s\n\n",r1); 
  system("pause");
  return 0;
}