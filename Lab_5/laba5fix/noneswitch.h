#include <stdlib.h> // ������� system("pause")
#include <stdio.h> // ������� printf , scanf 
#include <math.h> 
#include <Windows.h> // ��� �������� � ������
void laba5_1 () { 
  float x,a,b,f;
  int ind;
  SetConsoleOutputCP(1251);
  printf("      sqrt(5x^2-a) ��� x (-inf;3)\n"); // ���� ������� � �������
  printf("f(x)= bx+8 ��� x=3\n");
  printf("      cos(x) ��� x (3;11)\n");
  printf("\n������ �������� � = "); // ��������� ������� ������ �, � , b  
  scanf_s("%g",&a); //	printf("%g\n",a);
  printf("������ �������� � = ");
  scanf_s("%g",&x); //	printf("%g\n",x); 
  printf("������ �������� b = ");
  scanf_s("%g",&b); //	printf("%g\n",b);
  ind=0; // �true/false�
  if (x<3) 
    if(5*x*x-a>=0){
      f = sqrtf(5*x*x-a);
      ind = 1;
    }
    else 
      printf("\n\t\t�������� ���\n");
  
  else 
    if(x==3) {
      f = b*x+8;
      ind = 1;
    }
    else 
      if (x<11) {
        f = cosf(x);
        ind = 1;
      }
      else 
        printf("\n\t\t������� �������� � ���� ��������\n");
  if (ind)
    printf("\n\t\t�������� ������� � �������� ����������:%g\n",f);
  system("pause"); // �������� ������
} 