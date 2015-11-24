#include <stdio.h>
#include <stdlib.h> /* prototyp dla abs() */
 
#define N 10	/* rozmiar tablicy */
 
int main(void)
{
	/* deklaracja tablicy i jej inicjalizacja */
	int A[N] = {10, -1, 2, 1, 3, 4, 5, 6, 7, 8}; 
	int min, min_idx; /* szukane minimum i jego wspó³rzêdna */
	int i; /* zmienne pomocnicze */
 
	/* na pocz¹tek nie mamy lepszego kandydata */
	min_idx = 0; min = abs(A[min_idx]); 
 
	for(i = 1; i < N; i++)
	{
		if( abs(A[i]) < min )
		{
			/* gdy napotkany element jest mniejszy, 
			wybieramy go jako bie¿¹ce minimum */
 
			min_idx = i; 
			min = abs(A[min_idx]); 
		}
	}
 
	printf("Najmniejszy co do modu³u element tablicy to A[%d]=%d.\n",
		min_idx, min);
 
	return(0);
}