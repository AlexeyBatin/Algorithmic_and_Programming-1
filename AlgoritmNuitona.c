#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
int main(){
	int k,ind;
	double a,res=1;
	SetConsoleOutputCP(1251);
	printf("\t\tАлгоритм Ньютона\n");
	while(printf("Введіть степінь кореня: "),scanf("%d",&k)){
	if (k==0) printf("Помилка при введені значень\n"); 
	else { 
		printf("Введіть число а: ");
		scanf("%lf",&a);
		if ((a<0 && k%2==0) || (a==0) && (k<0) ) printf("Корінь не існує\n");
		else if (k==1 && a==0) {res = a; printf("Корінь степеня %d з %g = %g\n",k,a,res); }
		else if (k==-1) { res = 1/a; printf("Корінь степеня %d з %g = %g\n",k,a,res); }
		else {
			do
			{
			res = (a/pow(res,k - 1) + (k - 1)*res)/k;
			}
			while(fabs(a/pow(res, k) - 1.) > 0.1e-5); 
		printf("Корінь степеня %d з %g = %g\n",k,a,res);
		}
	}
	printf("Якщо бажаєте вийти з програми , то введіть будь-яку букву або символ.\n----------------------------------------------------\n");
	}
	system("pause");
}
