/* ���� ������ ������������� . ��-52. Variant �3.
Laboratorna robota �5. Realizatsia alhorytmiv pozhaluzhenykh protsesiv z vykorystanniam
vkladenykh umovnykh operatoriv I operatora vyboru */
#include <stdlib.h> // ������� system("pause")
#include <stdio.h> // ������� printf , scanf 
#include <math.h> 
#include <Windows.h> // ��� �������� � ������
#include "noneswitch.h"
int main() { 
  float x,a,b,f,v;
  int ind; // �true/false�
  SetConsoleOutputCP(1251); // �������� � ������
  printf("      sqrt(5x^2-a) ��� x (-inf;3)\n"); // ���� ������� � �������
  printf("f(x)= bx+8 ��� x=3\n");
  printf("      cos(x) ��� x (3;11)\n");
  printf("\n������ �������� � = "); // ��������� ������� ������ �, � , b  
  scanf_s("%g",&a); //	printf("%g\n",a);
  printf("������ �������� � = ");
  scanf_s("%g",&x); //	printf("%g\n",x); 
  printf("������ �������� b = ");
  scanf_s("%g",&b); //	printf("%g\n",b);
  ind = 0;
  if (x<3) 
    {
      v = 5*x*x-a;
    if( v >=0)
      f = sqrtf(v);
    else 
      ind=1; // �������� ���
  }
  else 
    if(x==3) 
      f = b*x+8;
    else 
      if (x<11) 
        f = cosf(x);
      else 
        ind=2; // ���� ��������

  switch (ind) {
    case 1:
      printf("\n\t\t�������� ���\n");
      break;
    case 2:
      printf("\n\t\t������� �������� � ���� ��������\n");
      break;
    default: 
      printf("\n\t\t�������� ������� � �������� ����������:%g\n",f);
      break;
    }
  printf("\n\n\t\t\t\t--------------��� switch------------\n\n\n");
  laba5_1();
}

