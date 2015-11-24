#include <stdio.h>
#define N 4	/* rozmiar permutowanej tablicy */
 
int A[N]; /* tablica, zawieraj¹ca liczby do spermutowania;
	wygodniej bêdzie nam u¿yæ tablicy globalnej */
 
unsigned int perm_count; /* bêdziemy liczyli wszystkie wykonane permutacje; 
	powinno ich na koñcu byæ N! nie przewidujemy du¿ych N, 
	dlatego wystarczy nam typ "int" */
 
void swap(int i, int j)
{
	/* zamienia ze sob¹ elementy "i" i "j" tablicy "A" */
 
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
 
void drukuj(void)
{
	/* Drukuje zawartoœæ tablicy "A".
	Poniewa¿ drukowanie oznacza, ¿e znaleŸliœmy now¹ permutacjê,
	przy okazji zwiêkszamy licznik wykonanych permutacji o 1 */
	int i;
 
	printf("%4d | ", perm_count++);
	for(i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}
 
void permutuj(int n)
{
	/* szuka wszystkich permutacji pocz¹tkowych n elementów tablicy "A" */
 
	int i;
 
	if ( n > 1 )
		for (i = 0; i < n; i++)
		{
			/* wystarczy zamieniæ ostatni element 
			z ka¿dym z poprzedzaj¹cych... */
			swap(i,n-1); 
 
			/* ...nastêpnie spermutowaæ wszystkie poprzedzaj¹ce... */
			permutuj(n-1);
 
			/* a na koniec - odwróciæ wykonane zamiany! */
			swap(i,n-1);
		}
	else
		/* skoro dotarliœmy do pocz¹tku tablicy, 
		mo¿emy wydrukowaæ gotow¹ permutacjê */
		drukuj();		
}
 
int main(void)
{
 
	/* inicjalizacja tablicy "A" kolejnymi liczbami naturalnymi */
	{
	int i;
	for( i = 0; i < N; i++)
		A[i] = i+1;
	}
 
	perm_count=0;drukuj(); /* drukujemy pocz¹tkowe ustawienie tablicy */
 
	/* wyznaczamy wszystkie permutacje */
	printf("===============\n");
	permutuj(N);
	printf("===============\n");
 
	perm_count=0;drukuj();	 /* drukujemy koñcowe ustawienie tablicy */	
	return(0);
}
 