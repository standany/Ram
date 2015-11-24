#include <stdio.h>
unsigned long long int liczba_ruchow = 0; 
	/* przy okazji, b�dziemy zliczali wszystkie wykonane przestawienia; 
	w tym celu wygodnie u�y� zmiennej globalnej */
 
void hanoi(int n, char lewy, char srodkowy, char prawy)
{
/* zamiast numerowa� s�upki, tym razem nazwiemy je literami */
 
	if ( n > 0 )
	{
		/* je�li tylko jest co� do zrobienia (tzn. wysoko�� wie�y jest > 0 */
 
		/* krok 1: najpierw musimy doprowadzi� do sytuacji,
		gdy na lewym zosta� jeden (najwi�kszy!) kr��ek, 
		a na �rodkowym jest reszta wie�y */
		hanoi(n-1, lewy, prawy, srodkowy); 
 
		/* krok drugi: teraz po prostu musimy przenie�� lewy kr��ek na
		prawy s�upek */
 
		liczba_ruchow++; 
		printf("Ruch: %lld. Przenies krazek ze slupka '%c' na slupek '%c'\n", liczba_ruchow, lewy, prawy); 
 
		/* krok 3: teraz musimy przenie�� ju� tylko n-1 kr��k�w ze
		�rodkowego na prawy! */
 
		hanoi(n-1, srodkowy, lewy, prawy);
	}
}
 
int main(void)
{
	int n;
 
	printf("Podaj wysokosc lewej wiezy\n");
	scanf("%d", &n);
 
	/* slupki: Lewy, Srodkowy, Prawy oznaczamy literami, 
	odpowiednio 'L', 'S', 'P' */
 
	hanoi(n, 'L', 'S', 'P');
 
	return(0);
}