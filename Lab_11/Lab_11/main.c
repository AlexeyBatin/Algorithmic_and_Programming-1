#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#define limit 1000
void input (int *arr,int lenght){ // ���������� ���
  int i;
  for(i=1;i<=lenght;i++){
    printf("\tarr[%d] = ", i);
    scanf_s("%d", &arr[i]); // &a[i] - ����� i-�� �������� ������
  }
}
void randarr(int *arr,int lenght){ // ��������� ��� ��������
  int i;
  srand(time(0));
  for(i=1;i<=lenght;i++){
    arr[i]=rand()%101-50;
    printf("\tarr[%d] = %d \n", i, arr[i]);
  }
}
void output (int *arr,int lenght){ // ��������� ������
  int i;
  for(i=1;i<=lenght;i++){
    printf(" %d ", arr[i]);
  }
  printf("\n\n");
}
void processing(int *arr,int *min,int *n,int lenght,int *ind){ // ������� ������
  int i;
  *min = arr[1];
  for (i = 1; i <lenght; i++) {
    if (arr[i] <= *min) {*min = arr[i];*n=i;}
  }
}
int main () { 
  char d[2];
  int lenght,ind,min,n;
  int arr[limit];
  SetConsoleOutputCP(1251);
  printf("������ ������� �������� ������ (>0): \n");
  scanf_s("%d",&lenght);
  do { printf( "��������� ����� ���������? Y/N (Yes/No): \n");
  scanf("%s",&d);
  printf("��������������������������������\n\n");
  if(d[0] == 'y'){ 
    input(arr,lenght); ind = 0;
  } // ���������� ���
  else if(d[0] == 'n'){  
    randarr(arr,lenght); ind = 0;
  } // ��������
  else ind = 1;
  fflush(stdin);
  } while (ind);
  output(arr,lenght);
  processing(arr,&min,&n,lenght,&ind);
  printf("��������� ��������� ������� = %d , ����� �������� = %d \n\n",min,n);
  if (ind) // ������� 
    system("pause");
}
