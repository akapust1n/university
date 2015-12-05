#include <stdio.h>
#include <string.h>
char * strtrim (char *str) //удаление пробелов с конца и начала строки
{
     char * szwcstr=" ";

    char *ptr = str;
    while (strchr (szwcstr, *ptr))
        ++ptr;

    str = ptr;

    for (ptr = str; *ptr; ++ptr);
    --ptr;

    for (--ptr; strchr (szwcstr, *ptr); --ptr)
        *ptr = '\0';

    return str;
}
char * del(char *str)
{
    char *ptr=str;
    while ((*ptr)<33)
        ++ptr;
    str=ptr;
    for (ptr = str; *ptr; ++ptr);
    --ptr;
    for (--ptr; (*ptr)<33; --ptr)

        *ptr = '\0';

    return str;
}

int menu1()
{
    int key;
    printf("Ipnut function\n");
    printf("1)Input line in string\n");
    printf("2)Delete line from table\n");
    printf("3)Change line\n");
    printf("4)Variant task\n>>");
    scanf("%d",&key);
    return key;
}
int menu2()
{
    int key;
    printf("Choose table\n");
    printf("1)Suppliers\n");
    printf("2)Delete line from table\n>>");
    scanf("%d",&key);
    return key;
}

int main()
{
    FILE *Suppliers;
    FILE *Products=fopen("Products.txt","r");
    FILE *Shipments=fopen("Shipments.txt","r");
    FILE *test=fopen("test.txt","w");
    char line[500];
    char h;
    while(1)
    {
        int u1=menu2();
        int u=menu1();
        switch(u1)
        {
         case 1:
            {
                switch (u)
                {
                   case 1:
                    {
                        int SupplierID;

                        char  SupplierName[200];
                        char  SupplierName1[200];
                        int Status;
                        char City[100];

                       // FILE *Suppliers1=fopen("Suppliers_work.txt","w");

                        while(1)
                        {   //считываем два идентефикатоа

                             printf("Input unique identefikator:\n");
                             printf("SupplierName ");
                             fflush(stdin);
                             gets(SupplierName1);
                             //хотим проверить их уникальность
                             Suppliers=fopen("Suppliers.txt","a+");
                             while (!feof(Suppliers))
                             {
                                 fscanf(Suppliers,"%d",&SupplierID);
                                 int y=0;
                                 do
                                 {

                                     ;
                                     fscanf(Suppliers,"%c",&h);
                                     //if (h==' ') continue;
                                      if(h>59||h<47) SupplierName[y++]=h;
                                      else break;

                                 } while(1);
                                  SupplierName[y]='\0';
                                 strcpy(SupplierName,del(strtrim(SupplierName))); //удаление лишних символов
                                SupplierName[strlen(SupplierName)-1]='\0';
                                        // puts(SupplierName);
                                         printf("%s__%s__%d %d\n",SupplierName1,SupplierName,strlen(SupplierName1),strlen(SupplierName));
                                 if(!strcmp(SupplierName,SupplierName1))
                                 {
                                    printf("\nNot unique identifier\n");

                                    break;
                                }
                               if(h)  Status=h-'0';
                                 y=0;
                                 fscanf(Suppliers,"%c",&h);
                                         if (h<58)
                                 {
                                     Status*=10;
                                     Status+=(h-'0');
                                 }
                                 else
                                 { City[y++]=h;}

                                     do
                                     {
                                         fscanf(Suppliers,"%c",&h);
                                          if(h!='\n'&&!feof(Suppliers)) City[y++]=h;
                                          else break;

                                     } while(1);
                                     City[y]='\0';
                                     strcpy(City,del(strtrim(City))); //удаление лишних символов
                                    City[strlen(City)-1]='\0';
                             }

                             if(feof(Suppliers)) break;


                        }
                       // fclose(Suppliers);

                        //считываем ещё два поля
                        do
                        {
                            printf("\nStatus ");
                            scanf("%d",&Status);
                        }while(!(Status>0&&Status<100));

                        printf("City ");
                        fflush(stdin);
                        gets(City);
                        fprintf(Suppliers,"\n%d    ",SupplierID+1);
                        fprintf(Suppliers,"%s ",SupplierName1);
                        fprintf(Suppliers,"%d     ",Status);
                        fprintf(Suppliers,"%s    ",City);
                        fclose(Suppliers);
                        printf("\nLine was added\n");
                     //вносим всё это в файл

                        //printf
                    }

                }
                break;
            }
          case 2:
            {
                break;
            }
        }


    }
return 0;
}
