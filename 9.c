#include <stdio.h>
#include <conio.h>
main()
{
        FILE *fp;
        int i,ilosc;
        struct studenci
        {
                char imie[20];
                char nazwisko[20];
        }student;
        printf("\n Podaj ilosc studentow: ");
        scanf("%d",&ilosc);
        fp=fopen("studenci.dat","w+b");
        for(i=0;i<ilosc;i++)
        {
                fflush(stdin);
                printf("\n Podaj imie studenta: ");
                scanf("%s",student.imie);
                printf("\n Podaj nazwisko studenta: ");
                fflush(stdin);
                scanf("%s",student.nazwisko);
                fwrite(&student,sizeof(struct studenci),1,fp);
        }
        fclose(fp);
        printf("\n Odczytana z pliku lista studentow:\n");
        fp=fopen("studenci.dat","r+b");
        for(i=0;i<ilosc;i++)
        {
                fread(&student,sizeof(struct studenci),1,fp);//odczyt z pliku studenci.dat
                printf("\n %s %s",student.imie,student.nazwisko);
        }
        fclose(fp);
        getch();
        return 0;
}