#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
int main(){
	int k,ind;
	double a,res;
	SetConsoleOutputCP(1251);
	printf("\t\tАлгоритм Ньютона\n");
	printf("Введіть степінь кореня");
	scanf("%d",&k);
	printf("Введіть число а");
	scanf("%lf",&a);
	if (k==0) printf("Помилка при введені значень");
	else if ((a<0 && k%2==0) || (a==0) && (k<0) ) printf("Корінь не існує");
	else if (k==1 && a==0) printf("Корінь = %lf",res);
	else if (k==-1) { res = 1/a; printf("Корінь = %lf",res); }
	else {
		do
		{
			res = (a/pow(1,k - 1) + (k - 1)*1)/k;
		}
		while(fabs(a/pow(1,k) - 1.) > 0.1e-5);
		printf("Корінь = %lf",res);
	}
	system("pause");
}
