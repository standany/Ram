unsigned int silnia(unsigned int n)
{
	int s = 1; /* zwracana warto�� silni */
	int i;
 
	/* implementacja nierekurencyjna */
	for(i = 2; i <= n; i++) 
		s *= i;
	return(s);
}
 
#ifdef DEBUG
/* 
skompiluj 
	gcc -DDEBUG -o silnia silnia.c, 
aby wygenerowa� program testuj�cy funkcj� silnia() 
*/
 
	#include <stdio.h>
 
	int main(void)
	{
		int k;
 
		printf("Test funkcji silnia():\n");
		for(k=0; k <= 10; k++)
			printf("\t%2d! = %d\n",k,silnia(k));
 
		return(0);
	}
#endif
 