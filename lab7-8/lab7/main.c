#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <D:\13\Progr\lab7-8\lab7\types.c>

int ka(char p[],int * pos,char name[])
{
    int state=0;
    while (1)
    {

        char s=p[*pos];
        switch(state)
        {
           case 0:
            {
                if (s>64&&s<91||s>95&&s<123||s==95) state=1;
                if (s)
             break;
             }
           case 1:
            {

                char st[40];
                int z=0;
                while (s>64&&s<91||s>95&&s<123||s==95||s>47&&s<58)
                {
                    st[z++]=s;
                    s=p[++(*pos)];
                }
                st[z]='\0';
                int u=0;
                for(;u<37;u++) if (!strcmp(st,KeywordsName[u])) break;
                strcpy(name,st);
                printf("%d",*pos);
                if(u==37)
                    return -1; //идентификатор
                else
                    return -2; //ключевое слово
            }
            }


    }

}

int main()
{
    FILE *f=fopen("1.txt","r");
    int number=1;
    int pos=0;
    char p[10000];
    char name[40];
    while (!feof(f))
    {

       fgets(p,10000,f);

        while(pos<strlen(p))
        {
            printf("start");
            ka( p,&pos, name);
            printf("%s",name);



        }

    }

    return 0;
}
