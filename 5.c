#include <stdio.h>
unsigned long long int liczba_ruchow = 0; 
	/* przy okazji, bêdziemy zliczali wszystkie wykonane przestawienia; 
	w tym celu wygodnie u¿yæ zmiennej globalnej */
 
void hanoi(int n, char lewy, char srodkowy, char prawy)
{
/* zamiast numerowaæ s³upki, tym razem nazwiemy je literami */
 
	if ( n > 0 )
	{
		/* jeœli tylko jest coœ do zrobienia (tzn. wysokoœæ wie¿y jest > 0 */
 
		/* krok 1: najpierw musimy doprowadziæ do sytuacji,
		gdy na lewym zosta³ jeden (najwiêkszy!) kr¹¿ek, 
		a na œrodkowym jest reszta wie¿y */
		hanoi(n-1, lewy, prawy, srodkowy); 
 
		/* krok drugi: teraz po prostu musimy przenieœæ lewy kr¹¿ek na
		prawy s³upek */
 
		liczba_ruchow++; 
		printf("Ruch: %lld. Przenies krazek ze slupka '%c' na slupek '%c'\n", liczba_ruchow, lewy, prawy); 
 
		/* krok 3: teraz musimy przenieœæ ju¿ tylko n-1 kr¹¿ków ze
		œrodkowego na prawy! */
 
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