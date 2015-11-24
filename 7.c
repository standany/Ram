#include <stdio.h>
#define K 45
 
/* u�ywamy unsigned, bo wszystkie nasze liczby s� dodatnie 
i tym samym dwukrotnie zwi�kszamy zakres dost�pnych warto�ci */
 
/* u�ywamy long int, aby zwi�kszy� zakres dost�pnych warto�ci 
w por�wnaniu z int */
 
unsigned long int FibonacciRec(unsigned int n)
{
	if( n < 2 )
		return(n);
	else
		return(FibonacciRec(n-1) + FibonacciRec(n-2));
 
}
 
unsigned long long int Fibonacci(unsigned int n)
{
	unsigned long long int F0 = 0; 
	unsigned long long int F1 = 1; 
	unsigned long long int F = 1; 
	unsigned int i;
 
	if( n < 2 )
		return(n);
 
	for( i = 2; i <= n; i++ )
	{
		F = F0 + F1;
		F0 = F1; F1 = F;
	}
	return(F);	
}
 
int main(void)
{
unsigned int k;
 
	/* zwr�� uwag� na format wydruku: 
 
		=> musz� poda� "%ld", aby zaznczy�, �e 
		drukowana liczba jest typu long int 
 
		=> musz� poda� "%lld", aby zaznczy�, �e 
		drukowana liczba jest typu long long int 
	*/	
 
	/* sprawdzenie, czy dzia�a */
 
	for ( k = 0; k < 4; k++)
	{
		printf("F(%d) = %lld = %ld\n", \
			k, Fibonacci(k), FibonacciRec(k));
	}
 
	/* wykonanie zadania */
 
	k = K;	
	printf("F(%d) = %ld\n",  k, FibonacciRec(k));	
	printf("F(%d) = %lld\n", k, Fibonacci(k));	
 
	return(0);
}