/* Batin Oleksiy Oleksandrovych , hrupa TM-62 , variant №3
* Labaratorna robota № 4 . Realizatsia alhorytmiv pozhalu-zhenykh protsesiv 
* z vykorystanniam poslidovnykh umovhykh operatoriv */
#include <stdlib.h> // функція system("pause")
#include <stdio.h> // функції printf , scanf 
#include <math.h> 
#include <Windows.h> // для кирилиці у консолі
int main() { 
	float x,a,b,f;
	int ind=0; // “true/false”
	//SetConsoleCP(1251);
  SetConsoleOutputCP(1251); // Кирилиця у консолі
	printf("      sqrt(5x^2-a) при x (-inf;3)\n"); // вивід функцій у консоль
	printf("f(x)= bx+8 при x=3\n");
	printf("      cos(x) при x (3;11)\n");
	printf("\nВведіть значення а = "); // Присвоєння значень змінним а, х , b  
	scanf_s("%g",&a); //	printf("%g\n",a);
	printf("Введіть значення х = ");
	scanf_s("%g",&x); //	printf("%g\n",x); 
	printf("Введіть значення b = ");
	scanf_s("%g",&b); //	printf("%g\n",b);
	if (x<3 && 5*x*x-a>=0 ){ // Перший проміжок , ОДЗ не пору-шено
		f = sqrtf(5*x*x-a);
		ind = 1; // true
	}
	if ( x<3 && 5*x*x-a<0) { // Перший проміжок, ОДЗ порушено
		printf("Порушено ОДЗ\n");
		
	}
	if ( x == 3) { // Другий проміжок без особливостей
	f = b*x+8;
	ind = 1; // true
	}
	if (x>3 && x<11) { // Третій проміжок
		f = cosf(x);
		ind = 1; // true
	}
	if (x>=11){ // Значення х поза проміжком
		printf("Введене значення х поза проміжком\n");
		
	} // Перевірка чи потрібно виводити значення функції 
	if (ind){
		printf("\n\t\tЗначення функції з заданими значеннями:%0.3g\n",f);
	}
	system("pause"); // затримка екрану 
}

 