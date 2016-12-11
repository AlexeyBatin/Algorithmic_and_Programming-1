#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#define N 100

void processing(int a[N][N],int n,int *counter,int *elements) // ������� ������ 
{
  int i,j;
  *counter = 0;
  *elements = 0;
  for (i=0; i<n; i++) // ���������� � 3-�� ������
    for (j=0; j<n; j++)
      if (i+j>n-1 && i-j<=0 && (a[i][j])%2==0 ) *counter+=1;
  if(n%2) {  // ���������� � 9-�� ������
    for (i=n/2; i<n; i++)
      for (j=0; j<n; j++) {a[i][j]=0;*elements+=1;} // ����� �������� �� ��� � ��������
  }
  else {
    for (i=(n+1)/2; i<n; i++)
      for (j=0; j<n; j++)  {a[i][j]=0;*elements+=1;} // ����� �������� �� ��� � ��������
  }
}
void randarr (int a[N][N],int n) // ���������� ������� ���������� ��������� 
{
  int i,j;
  srand(time(0));
  for(i=0; i<n; i++)  // ���� �� ������
  {
    for(j=0; j<n; j++)  // ���� �� ��������
    {
      a[i][j]=rand()%101-50;
      printf("\tarr[%d] = %d \n", i, a[i][j]);
    }
  }
} 
void output(int a[N][N],int n)  // ��������� �������
{
  int i,j;
  printf("\n\n");
  for(i=0; i<n; i++)  // ���� �� ������
  {
    for(j=0; j<n; j++)  // ���� �� ��������
    {
     if (i+j>n-1 && i-j<=0 ) printf("%5d*",a[i][j]);
       else printf("%5d ", a[i][j]); // 5 ����� �� ������� ������
    }
    printf("\n");

  }

  printf("\n\n");
}
void input (int a[N][N],int n) // ���������� ��� �������
{
  int i,j;
  for(i=0; i<n; i++)  // ���� �� ������
  {
    for(j=0; j<n; j++)  // ���� �� ��������
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%d", &a[i][j]);
    }
  }
}

int main() {
  int a[N][N];  // �������� �� �������� �� �����
  int n,ind,counter,elements; // n - ��������� , ind - ����������� , counter&elements - ���������
  char d[2];
  SetConsoleOutputCP(1251);
  ind = 1;
  while (ind) {
    fflush(stdin);
    do {
      printf("\t������ ����� ������� : ");
      scanf("%d", &n);
      if(n>0 && n<N)  ind = 0; }
    while (ind);
    // �������� ���'�� �� �������� �� �����
    do { printf( "\t��������� ����� ���������? y/n (Yes/No): \n");
    scanf("%s",&d);
    printf("��������������������������������\n\n");
    if(d[0] == 'y'){ 
      input(a,n); ind = 0;
    } // ���������� ���
    else if(d[0] == 'n'){  
      randarr(a,n); ind = 0;
    } // ��������
    fflush(stdin);
    } while (ind);
    printf("\n \t ���������� ������ �������");
    output(a,n);  // ���� �������� �������
    processing(a,n,&counter,&elements);
    printf("\n \t ������ ������� ���� �������");
    output(a,n);
    printf("��������������������������������\n\n");
    printf("\n ʳ������ ������ �������� � 3 ������: %d \n",counter);
    printf("\n ʳ������ �������� � 9 ������: %d \n",elements);
    printf("��������������������������������\n\n");
    printf("\t�������� ���� �������? y (Yes): \n");
    scanf("%s",&d);
    if(d[0] =='y' ) { ind = 1; system("cls");} // ������� ���� � ���'�� , ����� �������
    else ind = 0;
  }
  system("pause");
  return 0;
}
