/* ���� ������ �������������. ��-62. ������ �3. ����������� ������ �7.
 ������������ ��������� � ������� ������� ��������� (����������� � ����������).*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
int main () {
  double x1,x2,h,// ������� ������� � ����
    a,b,x, // ��������� � � � , ����� �
    f; // ���������� �������
  double eps = 1e-5;
  char r1[62] = "-------------------------------------------------------------",
       r2[21] = "|   x    |   f(x)   ";
  int ind , // ����������� 
    i,  // ����� ����������� ���������
    k=3;  // ������� ��� �������
  SetConsoleOutputCP(1251);
  printf("����������� �������:\n");
  printf("\tf(x)=sqrt(x+a)/sin(x-b)+cos(|x|)\n");
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
  printf("������ �������� ��������� a i b (�������� ��������� ����� �����):");
  scanf("%lf %lf",&a,&b);
  printf("%s\n",r1);
  printf("%s%s%s|\n",r2,r2,r2);
  printf("%s\n",r1);
  x=x1;
  i=0;
  while (x<=x2+eps){
    i++;ind=1;
    printf("| %6.2lf",x);
    if (x+a<0 || fabsl(sin(x-b))<eps) printf(" |  �� ���� ");
    else { f=(sqrt(x+a)/sin(x-b))+cos(fabs(x)); 
    if(fabs(f)>10) printf(" |  ��������");
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