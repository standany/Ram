#include <stdio.h>
#include <conio.h>

int main()
{
        int liczba,n;
        int maksimum,minimum;
        int i=0;
        printf("\n Podaj ilosc liczb: \n n = ");
        scanf("%d",&n);
        do
        {
                printf("\n Podaj liczbe: ");
                scanf("%d",&liczba);
                if(i==0)
                {
                        maksimum=liczba;
                        minimum=liczba;
                }
                if(liczba>maksimum)
                        maksimum=liczba;
                if(liczba<minimum)
                        minimum=liczba;
                i++;
        }
        while(i<n);
        printf("\n Najwieksza wczytana wartosc liczbowa wynosi: %d",maksimum);
        printf("\n Najmiejsza wczytana wartosc liczbowa wynosi: %d",minimum);
        getch();
        return 0;
}
