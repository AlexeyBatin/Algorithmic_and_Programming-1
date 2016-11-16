#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
const int c1=2 , c2=3;
int main ()
{ 
  float a, x, z, t, y, change;
  printf("f1= (2x-a)/(3-sqrt(x-1))-3cos(abs(x))\n");
  printf("f2= 3/2-3/10x+7e^(-2*tg(x))\n");
  printf("f3=4/5 *x^6,8\n");
  printf("Vvedit znachennia A = ");  
  scanf("%g",&a);
  printf("%g\n",a);
  printf("Vvedit znachennia X = ");
  scanf("%g",&x);
  printf("%g\n",x); 
  y = (c1*x-a)/(c2-sqrtf(x-1))-c2*cosf(fabs(x)); // y - перше рівняння
  z = 1.5 -0.3*x + 7*exp(-2*tanf(x)); // z - друге рівняння
  t = 4./5*powf(x,6.8); // t - третє рівняння
  printf("f1= %0.3g\n",y);
  printf("f2= %g\n",z);
  printf("f3= %g\n",t);
  change = y; 
  y = z;   
  z = t;
  t = change;   
  printf("y= %g\n",y);
  printf("z= %g\n",z); 
  printf("t= %g\n",t);
  system("pause");
}
