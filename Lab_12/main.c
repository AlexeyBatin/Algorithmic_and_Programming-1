#define  _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#define limit 1000
void input (int *arr,int lenght){ // ���������� ���
  int i;
  for(i=0;i<lenght;i++){
    printf("\tarr[%d] = ", i);
    scanf_s("%d", &arr[i]); // &a[i] - ����� i-�� �������� ������
  }
  printf("\n");
}
void randarr(int *arr,int lenght){ // ��������� ��� ��������
  int i;
  srand(time(0));
  for(i=0;i<lenght;i++){
    arr[i]=rand()%101-50;
    printf("\tarr[%d] = %d \n", i, arr[i]);
  }
  printf("\n");
}
void output (int *arr,int lenght){ // ��������� ������
  int i;
  printf("\n\t\t------------------------------------------\n\t\t");
  for(i=0;i<lenght;i++){
    printf(" %d ", arr[i]);
  }
  printf("\n\t\t------------------------------------------\n");
}

void sort(int *arr, int length, int *ind) // ���������� ���������
{
  int temp, // ��������� ����� ��� ��������� �������� �������� ����������� ������
    item, // ������� ������
    i; // ��������
  for (i = 1; i < length; i++)
  {
    temp = arr[i]; // ���������� ��������� ����� �������� ��������� �������� ������
    item = i-1; // �����'������� ������ ������������ �������� ������
    while(item >= 0 && arr[item] < temp) // ���� ������� �� ������� 0 � ��������� ������� ������ ����� ���������
    {
      arr[item + 1] = arr[item]; // ������������ �������� ������
      arr[item] = temp;
      item--;
    }
    output(arr,length);
  }
  *ind=1;
}
int main () { 
  char d[2];
  int lenght,ind;
  int arr[limit]; 
  SetConsoleOutputCP(1251);
  ind = 1;
  while (ind) {
    fflush(stdin);
    do { printf("\t������ ������� �������� ������ (>0): \n");
    scanf_s("%d",&lenght);
    if (lenght>0 && lenght<limit) ind = 0; }
    while (ind);
    do { printf( "\t��������� ����� ���������? y/n (Yes/No): \n");
    scanf("%s",&d);
    printf("��������������������������������\n\n");
    if(d[0] == 'y'){ 
      input(arr,lenght); ind = 0;
    } // ���������� ���
    else if(d[0] == 'n'){  
      randarr(arr,lenght); ind = 0;
    } // ��������
    fflush(stdin);
    } while (ind);
    output(arr,lenght);
    sort(arr,lenght,&ind);
    // ������� 
    if (ind) {printf("\t������� ������ �������� \n "); output(arr,lenght);}
    else printf("\t������� �� ��������\n");
    printf("�������� ����� �����? y (Yes): \n");
    scanf("%s",&d);
    if(d[0] =='y' ) ind = 1;
    else ind = 0;}
  system("pause");
}
