#include <stdio.h>
#include <string.h>

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
                        int Status;
                        char City[100];
                       // FILE *Suppliers1=fopen("Suppliers_work.txt","w");

                        while(1)
                        {   //считываем два идентефикатоа

                             printf("Input unique identefikators:\n"); /
                             printf("");
                             //хотим проверить их уникальность
                             Supplires=fopen("Suppliers.txt","r");
                             while (!feof(Suppliers))
                             {

                                 fscanf(f,"%d",&SupplierID);
                                 int y=0;
                                 do
                                 {

                                     ;
                                     fscanf(f,"%c",&h);
                                      if(h>59&&h!=' ') SupplierName[y++]=h;
                                      else break;

                                 } while(1);
                                 SupplierName[y]='\0';
                                 status=h-'0';
                                 fscanf("%c",&h;)
                                         if (h<58)
                                 {
                                     status*=10;
                                     status+=(h-'0');
                                 }
                                 else
                                 {
                                     y=0;
                                     do
                                     {
                                         fscanf(f,"%c",&h);
                                          if(h>59 &&h!=' ') City[y++]=h;
                                          else break;

                                     } while(1);

                                 }

                             }
                        }

                        printf
                    }
                }
                break;
            }
        }


    }
return 0;
}
