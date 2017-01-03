/* Батін Олексій Олександрович . ТМ-52. Variant №3.
Laboratorna robota №5. Realizatsia alhorytmiv pozhaluzhenykh protsesiv z vykorystanniam
vkladenykh umovnykh operatoriv I operatora vyboru */
#include <stdlib.h> // функція system("pause")
#include <stdio.h> // функції printf , scanf 
#include <math.h> 
#include <Windows.h> // для кирилиці у консолі
void laba5_1 () { 
  float x,a,b,f;
  int ind;
  SetConsoleOutputCP(1251);
  printf("      sqrt(5x^2-a) при x (-inf;3)\n"); // вивід функцій у консоль
  printf("f(x)= bx+8 при x=3\n");
  printf("      cos(x) при x (3;11)\n");
  printf("\nВведіть значення а = "); // Присвоєння значень змінним а, х , b  
  scanf_s("%g",&a); //	printf("%g\n",a);
  printf("Введіть значення х = ");
  scanf_s("%g",&x); //	printf("%g\n",x); 
  printf("Введіть значення b = ");
  scanf_s("%g",&b); //	printf("%g\n",b);
  ind=0; // “true/false”
  if (x<3) 
    if(5*x*x-a>=0){
      f = sqrtf(5*x*x-a);
      ind = 1;
    }
    else 
      printf("\n\t\tПорушено ОДЗ\n");
  
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
        printf("\n\t\tВведене значення х поза проміжком\n");
  if (ind)
    printf("\n\t\tЗначення функції з заданими значеннями:%g\n",f);
  system("pause"); // затримка екрану
}
// Текст програми з оператором case:
/* Батін Олексій Олександрович . ТМ-52. Variant №3.
Laboratorna robota №5. Realizatsia alhorytmiv pozhaluzhenykh protsesiv z vykorystanniam
vkladenykh umovnykh operatoriv I operatora vyboru */
#include <stdlib.h> // функція system("pause")
#include <stdio.h> // функції printf , scanf 
#include <math.h> 
#include <Windows.h> // для кирилиці у консолі
#include "noneswitch.h"
int main() { 
  float x,a,b,f,v;
  int ind; // “true/false”
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
  ind = 0;
  if (x<3) 
    {
      v = 5*x*x-a;
    if( v >=0)
      f = sqrtf(v);
    else 
      ind=1; // Порушено ОДЗ
  }
  else 
    if(x==3) 
      f = b*x+8;
    else 
      if (x<11) 
        f = cosf(x);
      else 
        ind=2; // поза проміжком

  switch (ind) {
    case 1:
      printf("\n\t\tПорушено ОДЗ\n");
      break;
    case 2:
      printf("\n\t\tВведене значення х поза проміжком\n");
      break;
    default: 
      printf("\n\t\tЗначення функції з заданими значеннями:%g\n",f);
      break;
    }
  printf("\n\n\t\t\t\t--------------Без switch------------\n\n\n");
  laba5_1();
}
