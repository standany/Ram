#include <stdio.h>
#define K 45
 
/* u¿ywamy unsigned, bo wszystkie nasze liczby s¹ dodatnie 
i tym samym dwukrotnie zwiêkszamy zakres dostêpnych wartoœci */
 
/* u¿ywamy long int, aby zwiêkszyæ zakres dostêpnych wartoœci 
w porównaniu z int */
 
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
 
	/* zwróæ uwagê na format wydruku: 
 
		=> muszê podaæ "%ld", aby zaznczyæ, ¿e 
		drukowana liczba jest typu long int 
 
		=> muszê podaæ "%lld", aby zaznczyæ, ¿e 
		drukowana liczba jest typu long long int 
	*/	
 
	/* sprawdzenie, czy dzia³a */
 
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