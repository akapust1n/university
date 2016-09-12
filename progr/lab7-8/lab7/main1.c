#include <stdio.h>


int main()
{
    FILE *f=fopen("1.txt","rb");
    char p[1000];
    int number=0;
    while(!feof(f))
    {
        fgets(p,1000,f);

        printf("number %d",number++);
       puts(p);
    }
    return 0;
}
