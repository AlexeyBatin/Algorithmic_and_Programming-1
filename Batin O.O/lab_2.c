//
///* Batin Oleksiy Oleksandrovych , hrupa TM-62 , variant №3
//* Labaratorna robota № 2 . Oformlennia zvitiv z labaratornyx
//* robit zasobamy tekstovoho redaktora Word */
//#include <stdio.h> /* pidmykannia biblioteky stdio.h;
//	u prohrami  vykorystovuiut'sia funktsii XXX, ... XXX */
//#include <stdlib.h> /* pidmykannia stdlib.h; u prohrami
//	vykorystovuiut'sia funktsii XXX, ... XXX */ 
///* Za vvedenym korystuvachem chyslovym kodom vid 32 do 255
//	(koduvannia ASCII) vyvodyt' symvol */
//int main ()
//{
//	int kod; /* kod symvola */
//	 /* symvoly z kodamy 0-31 ye sluzhbovymy; probil maie kod 32; kod
//	13 vvodyt'sia pry natyskanni na klavishy Enter, 27 - na Esc */ 
//	printf("vvedit ASCII-kod symvola vid 32 do 255\n");
//	scanf("%d",&kod);
//	if ((kod<32) || (kod>255))
//		printf("neverniy kod\n");
//	else printf("symvol  %c\n",/* (char)*/ kod);
//	fflush(stdin);getchar(); /* stdin- standartnyi potik vvodu;
//	abo zamist' dvokh ostannikh funktsii - system("pause") */
//	return 0;
//}

/* Batin Oleksiy Oleksandrovych , hrupa TM-62 , variant №3
* Labaratorna robota № 2 . Oformlennia zvitiv z labara-tornyx
* robit zasobamy tekstovoho redaktora Word */
#include <stdio.h> /* pidmykannia biblioteky stdio.h;
	u prohrami  vykorystovuiut'sia funktsii XXX, ... XXX */
#include <stdlib.h> /* pidmykannia stdlib.h; u prohrami
	vykorystovuiut'sia funktsii XXX, ... XXX */ 
/* Za vvedenym korystuvachem chyslovym kodom vid 32 do 255
	(koduvannia ASCII) vyvodyt' symvol */
int main ()
{
	int kod; /* kod symvola */
	 /* symvoly z kodamy 0-31 ye sluzhbovymy; probil maie kod 32; kod
	  13 vvodyt'sia pry natyskanni na klavishy Enter, 27 - na Esc */ 
	printf("vvedit ASCII-kod symvola vid 32 do 255\n");
	scanf("%d",&kod);
	if ((kod<32) || (kod>255))
	  printf("neverniy kod\n");
	  else printf("symvol  %c\n",/* (char)*/ kod);
	fflush(stdin);getchar(); /* stdin- standartnyi potik vvodu;
	abo zamist' dvokh ostannikh funktsii - sys-tem("pause") */
	return 0;
}
