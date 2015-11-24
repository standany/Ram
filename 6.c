#include <stdio.h>
#define N 4	/* rozmiar permutowanej tablicy */
 
int A[N]; /* tablica, zawieraj�ca liczby do spermutowania;
	wygodniej b�dzie nam u�y� tablicy globalnej */
 
unsigned int perm_count; /* b�dziemy liczyli wszystkie wykonane permutacje; 
	powinno ich na ko�cu by� N! nie przewidujemy du�ych N, 
	dlatego wystarczy nam typ "int" */
 
void swap(int i, int j)
{
	/* zamienia ze sob� elementy "i" i "j" tablicy "A" */
 
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
 
void drukuj(void)
{
	/* Drukuje zawarto�� tablicy "A".
	Poniewa� drukowanie oznacza, �e znale�li�my now� permutacj�,
	przy okazji zwi�kszamy licznik wykonanych permutacji o 1 */
	int i;
 
	printf("%4d | ", perm_count++);
	for(i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}
 
void permutuj(int n)
{
	/* szuka wszystkich permutacji pocz�tkowych n element�w tablicy "A" */
 
	int i;
 
	if ( n > 1 )
		for (i = 0; i < n; i++)
		{
			/* wystarczy zamieni� ostatni element 
			z ka�dym z poprzedzaj�cych... */
			swap(i,n-1); 
 
			/* ...nast�pnie spermutowa� wszystkie poprzedzaj�ce... */
			permutuj(n-1);
 
			/* a na koniec - odwr�ci� wykonane zamiany! */
			swap(i,n-1);
		}
	else
		/* skoro dotarli�my do pocz�tku tablicy, 
		mo�emy wydrukowa� gotow� permutacj� */
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
 
	perm_count=0;drukuj(); /* drukujemy pocz�tkowe ustawienie tablicy */
 
	/* wyznaczamy wszystkie permutacje */
	printf("===============\n");
	permutuj(N);
	printf("===============\n");
 
	perm_count=0;drukuj();	 /* drukujemy ko�cowe ustawienie tablicy */	
	return(0);
}
 