#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
        void sortowanie(int [],int );
        int x[10];
        int i;
        randomize();
        printf("\n Wylosowana tablica x przed uporzadkowaniem: \n\n");
        for(i=0;i<10;i++)
        {
                x[i]=random(10);
                printf(" x[%d]=%d",i,x[i]);
        }
        printf("\n\n Wylosowana tablica x po uporzadkowaniu: \n\n");
        sortowanie(x,10);
        for(i=0;i<10;i++)
                printf(" x[%d]=%d",i,x[i]);
        getch();
        return 0;
}
void sortowanie(int x[],int n)
{
        int i,k;
        int pom,info;
        do
        {
                info=0;
                for(i=1;i<n;i++)
                        if(x[i-1]<x[i])
                        {
                                pom=x[i-1];
                                x[i-1]=x[i];
                                x[i]=pom;
                                info=1;
                        }
        }
        while(info==1);
}