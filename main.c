#include <stdio.h>
#include <stdlib.h>

struct game
{
    char nama;
    int power;
    int atc;
    int def;
};

int main()
{
    struct game hero[2];
    int i=0,j;
    char a[2],aksi1,aksi2;
    printf("\tGAME PERANG\n");
    printf("---------------------------------------\n");
    printf("|HERO\t|  A  |  B  |  C  |  D  |  E  |\n");
    printf("|power\t| 200 | 200 | 200 | 200 | 200 |\n");
    printf("|attack\t|  50 |  30 |  60 |  70 |  40 |\n");
    printf("|defense|  40 |  60 |  20 |  10 |  70 |\n");
    printf("---------------------------------------\n");
        for(i=0;i<2;i++)
        {
            do
            {   printf("\n");
                if(i==0)
                {
                    fflush(stdin);
                    printf("pilih hero anda:");
                    scanf("%c",&a[i]);
                }
                if(i==1)
                {
                    fflush(stdin);
                    printf("pilih hero lawan:");
                    scanf("%c",&a[i]);
                }
                if (a[i]=='a'||a[i]=='A')
                    {hero[i].nama='A';hero[i].power=200;hero[i].atc=50;hero[i].def=40;}
                else if (a[i]=='b'||a[i]=='B')
                    {hero[i].nama='B';hero[i].power=200;hero[i].atc=30;hero[i].def=60;}
                else if (a[i]=='c'||a[i]=='C')
                    {hero[i].nama='C';hero[i].power=200;hero[i].atc=60;hero[i].def=20;}
                else if (a[i]=='d'||a[i]=='D')
                    {hero[i].nama='D';hero[i].power=200;hero[i].atc=70;hero[i].def=10;}
                else if (a[i]=='e'||a[i]=='E')
                    {hero[i].nama='E';hero[i].power=200;hero[i].atc=40;hero[i].def=70;}
                else
                    {
                        printf("Inputkan Hero anda dengan benar");
                        a[i]='x';
                    }
            }while(a[i]=='x');
        }
    while(hero[0].power>0||hero[1].power>0)
    {
        system("cls");
        printf("\tPLAY GAME\n");
        printf("\n-----------------------------------------\n");
        printf("|Hero\t|\t%c\t|\t%c\t|\n",hero[0].nama,hero[1].nama);
        printf("|power\t|\t%d\t|\t%d\t|\n",hero[0].power,hero[1].power);
        printf("|attack\t|\t%d\t|\t%d\t|\n",hero[0].atc,hero[1].atc);
        printf("|defense|\t%d\t|\t%d\t|\n",hero[0].def,hero[1].def);
        printf("-----------------------------------------\n");
        printf("Pilih aksi\na = attack\nd = defense\n");
        fflush(stdin);
        printf("anda (hero %c)\t:",hero[0].nama);
        scanf("%c",&aksi1);
        fflush(stdin);
        printf("lawan (hero %c)\t:",hero[1].nama);
        scanf("%c",&aksi2);
        if((aksi1=='a'||aksi1=='A')&& (aksi2=='d'||aksi2=='D'))
        {
            if(hero[1].def>hero[0].atc)
            {
                j=hero[1].def-hero[0].atc;
                hero[0].power=(hero[0].power-j)-10;
                hero[1].power=hero[1].power-10;
            }
            else
            {
                j=hero[0].atc-hero[1].def;
                hero[0].power=hero[0].power-10;
                hero[1].power=(hero[1].power-10)-j;
            }
        }
        else if((aksi1=='d'||aksi1=='D')&& (aksi2=='a'||aksi2=='A'))
        {
            if(hero[0].def>hero[1].atc)
            {
                j=hero[0].def-hero[1].atc;
                hero[1].power=(hero[1].power-j)-10;
                hero[0].power=hero[0].power-10;
            }
            else
            {
                j=hero[1].atc-hero[0].def;
                hero[1].power=hero[1].power-10;
                hero[0].power=(hero[0].power-10)-j;
            }
        }
        else if((aksi1=='a'||aksi1=='A')&& (aksi2=='a'||aksi2=='A'))
        {
            hero[0].power=(hero[0].power-hero[1].atc)-10;
            hero[1].power=(hero[1].power-hero[0].atc)-10;
        }
        else if((aksi1=='d'||aksi1=='D')&& (aksi2=='d'||aksi2=='d'))
        {
            hero[0].power=hero[0].power-10;
            hero[1].power=hero[1].power-10;
        }
        else
        {
            printf("Input aksi dengan benar");
        }

        printf("\nSisa power anda\t:%d",hero[0].power);
        printf("\nSisa power lawan:%d\n",hero[1].power);
        system("pause");
    }

    if(hero[0].power<=0&&hero[1].power<=0)
    {
        printf("\nPERMAINAN SERI!!!");
    }
    else if(hero[0].power<=0)
    {
        printf("\nPERMAINAN BERAKHIR, HERO %c MENANG!!!",hero[1].nama);
    }
    else
    {
        printf("\nPERMAINAN BERAKHIR, HERO %c MENANG!!!",hero[0].nama);
    }
    return 0;
}
