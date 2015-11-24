#include <stdio.h>
#include <conio.h>
main()
{
        FILE *wskaznik_pliku;
        int liczba,i,ilosc;
        char wybor;
        wskaznik_pliku=fopen("plik","w+b");
        do
        {
                //clrscr(); // dzia³a tylko pod system Linux (usun komentarz przed poleceniem
                printf("\n Wybierz wariant:");
                printf("\n 1. Zapisanie wartosci liczbowej do pliku");
                printf("\n 2. Odczytanie  wartosci liczbowych z pliku");
                printf("\n 0. Wyjscie \n ");
                wybor=getch();
                if(wybor=='1')
                {
                        fseek(wskaznik_pliku,0,SEEK_END);
                        printf("\n Podaj liczbe do zapisu w pliku:");
                        printf("\n liczba = ");
                        scanf("%d",&liczba);
                        fwrite(&liczba,sizeof(int),1,wskaznik_pliku);
                }
                if(wybor=='2')
                {
                        printf("\n Liczby zapisane w pliku:");
                        fseek(wskaznik_pliku,0,SEEK_END);
                        ilosc=ftell(wskaznik_pliku)/sizeof(int);
                        fseek(wskaznik_pliku,0,SEEK_SET);
                       for(i=0;i<ilosc;i++)
                        {
                                fread(&liczba,sizeof(int),1,wskaznik_pliku);
                                printf("\n liczba[%d] = %d",i,liczba);
                        }
                        printf("\n\n Wcisnij klawisz...");
                        getch();
                }
        }
        while(wybor!='0');
        fclose(wskaznik_pliku);
        return 0;
}