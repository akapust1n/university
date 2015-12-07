#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
int isCitySupplier(int idship[],int id)
{
    for(int i=0;idship[i];i++)
    if (idship[i]==id)
        return 1;
    return 0;

}
int isProductID
(int idpor[],int id)
{
    for(int i=0;idship[i];i++)
    if (idship[i]==id)
        return idship[i];
    return 0;

}

int isColor(char *color)
{
    char color1[100];
    strcpy(color1,color);
    if(!strcmp("Silver",color1)) return 1;
    if(!strcmp("Black",color1)) return 1;
    if(!strcmp("Red",color1)) return 1;
    if(!strcmp("Yellow",color1)) return 1;
    if(!strcmp("Silver",color1)) return 1;
    if(!strcmp("Grey",color1)) return 1;
    if(!strcmp("NULL",color1)) return 1;
    if(!strcmp("Multi",color1)) return 1;
    if(!strcmp("Blue",color1)) return 1;
    return 0;

}

int menu1()
{
    int key;
    printf("Ipnut function\n");
    printf("1)Input line in string\n");
    printf("2)Delete line from table\n");
    printf("3)Change line\n>>");
    scanf("%d",&key);
    return key;
}
int menu2()
{
    int key;
    printf("\nChoose table\n");
    printf("1)Suppliers\n");
    printf("2)Products\n");
    printf("3)Shipments\n");
    printf("4)Variant task\n>>");
    scanf("%d",&key);
    return key;
}

int main()
{
    FILE *Suppliers;
    FILE *Products;
    FILE *Shipments;
    FILE *test=fopen("test.txt","w");
    char line[500];
    char h;
    while(1)
    {
        int u1=menu2();
        int u;
        if(u1!=4) u=menu1();
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
                                    City[strlen(City)]='\0';  //а может и -1
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
                         break;
                        //printf
                    }
                    case 2:
                      {
                          int SupplierID1;
                          int SupplierID;
                          char  SupplierName[200];
                          char  SupplierName1[200];
                          int Status;
                          char City[100];

                          printf("Input SupplierID ");
                          scanf("%d",&SupplierID1);
                          FILE *f=fopen("temp.txt","w");
                          Suppliers=fopen("Suppliers.txt","r");
                          while (!feof(Suppliers))
                          {
                              fscanf(Suppliers,"%d",&SupplierID);

                              int y=0;
                              do
                              {


                                  fscanf(Suppliers,"%c",&h);
                                  //if (h==' ') continue;
                                   if(h>59||h<47) SupplierName[y++]=h;
                                   else break;

                              } while(1);
                               SupplierName[y]='\0';
                              strcpy(SupplierName,del(strtrim(SupplierName))); //удаление лишних символов
                             SupplierName[strlen(SupplierName)-1]='\0';
                                     // puts(SupplierName);

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
                                 City[strlen(City)]='\0';
                                 if (SupplierID==SupplierID1) continue;
                                 fprintf(f,"\n%d    ",SupplierID);
                                 fprintf(f,"%s ",SupplierName);
                                 fprintf(f,"%d     ",Status);
                                 fprintf(f,"%s    ",City);

                          }
                           fclose(Suppliers);
                         fclose(f);
                         system("del Suppliers.txt");
                         system("rename temp.txt Suppliers.txt");
                          printf("\nIf there was an element, element was deleted\n");
                          break;
                      }
                    case 3:
                     {
                        int SupplierID1;
                        int SupplierID;
                        char  SupplierName[200];
                        char  SupplierName1[200];
                        int Status;
                        char City[100];
                        int flag=0;

                        printf("Input SupplierID ");
                        scanf("%d",&SupplierID1);
                        FILE *f=fopen("temp.txt","w");
                        Suppliers=fopen("Suppliers.txt","r");
                        while (!feof(Suppliers))
                        {
                            fscanf(Suppliers,"%d",&SupplierID);
                             if(SupplierID==SupplierID1) flag=1;
                             else
                                 flag=0;
                            int y=0;
                            do
                            {


                                fscanf(Suppliers,"%c",&h);

                                //if (h==' ') continue;
                                 if(h>59||h<47) SupplierName[y++]=h;
                                 else break;

                            } while(1);
                             SupplierName[y]='\0';
                            strcpy(SupplierName,del(strtrim(SupplierName))); //удаление лишних символов
                           SupplierName[strlen(SupplierName)-1]='\0';
                                   // puts(SupplierName);

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
                               City[strlen(City)]='\0';
                               if (!flag) {
                               fprintf(f,"\n%d    ",SupplierID);
                               fprintf(f,"%s ",SupplierName);
                               fprintf(f,"%d     ",Status);
                               fprintf(f,"%s    ",City);
                               }
                               else
                               {
                                   printf("SupplierName ");
                                   fflush(stdin);
                                   gets(SupplierName);
                                   do
                                   {
                                       printf("\nStatus ");
                                       scanf("%d",&Status);
                                   }while(!(Status>0&&Status<100));

                                   printf("City ");
                                   fflush(stdin);
                                   gets(City);
                                   fprintf(f,"\n%d    ",SupplierID);
                                   fprintf(f,"%s ",SupplierName);
                                   fprintf(f,"%d     ",Status);
                                   fprintf(f,"%s    ",City);
                               }


                        }
                         fclose(Suppliers);
                       fclose(f);
                       system("del Suppliers.txt");
                       system("rename temp.txt Suppliers.txt");
                        printf("\nIf there was an element, element was changed\n");
                         break;
                     }

                }
                break;
            }
         case 2:
            {
                switch (u)
                {
                    case 1:
                    {
                        int ProductID;
                        char  ProductName[200]="";
                        char  ProductName1[200];
                        char  Color[200];
                         char h;
                        char Weight[20];
                        char Price[200];
                        char City[100];
                        char temp[100];
                        Products=fopen("Products.txt","a+");
                        ///-------------
                        while (!feof(Products))
                        {
                            fscanf(Products,"%d",&ProductID);
                            printf("%d\n", ProductID);
                            int y=0;
                            do
                            {
                              fscanf(Products,"%s",&temp);

                              if (!isColor(temp)) strcat(ProductName,temp);
                              else
                                  break;

                            } while(1);

                             strcpy(Color,temp);
                             fscanf(Products,"%s",&Weight);
                              fscanf(Products,"%s",&Price);
                               y=0;
                                do
                                {
                                    fscanf(Products,"%c",&h);
                                     if(h!='\n'&&!feof(Products)) City[y++]=h;
                                     else break;

                                } while(1);
                                City[y]='\0';
                                strcpy(City,del(strtrim(City))); //удаление лишних символов
                               City[strlen(City)]='\0';

                        }
                        ///------------------------------------------------------
                        printf("Input :\n");
                        printf("ProductName ");
                        fflush(stdin);
                        gets(ProductName1);
                        //хотим проверить их уникальность-а тут уже не надо проверять
                        printf("Color ");
                        gets(Color);
                        do
                        {
                        printf("Weight ");
                        scanf("%s",& Weight);
                        if(!atof(Weight)) continue;
                            double  u=atof(Weight);
                            if (u<0) continue;
                        break;
                        } while(1);
                        do
                        {
                        printf("Price ");
                        scanf("%s", &Price);
                        if(!(atof(Price))&&(Price[0]-'0')!=0) continue;

                            double  u=atof(Price);
                            if (u<0) continue;

                        break;
                        } while(1);

                        printf("City ");
                        fflush(stdin);
                        gets(City);
                        fprintf(Products,"\n%d    ",ProductID+1);
                        fprintf(Products,"%s ",ProductName1);
                        fprintf(Products,"%s    ",Color);
                        fprintf(Products,"%s    ",Weight);
                        fprintf(Products,"%s    ",Price);
                        fprintf(Products,"%s    ",City);
                        fclose(Products);
                         printf("\nLine was added\n");
                        fclose(Products);
                                              //вносим всё это в файл
                                        break;
                    }
                //printf
                    case 2:
                    {
                        int ProductID;
                        int ProductID1;
                        char  ProductName1[200];
                        char  ProductName[200];
                        char  Color[200];
                         char h;
                        char Weight[20];
                        char Price[200];
                        char City[100];
                        char temp[100];
                        int flag=0;
                       // char temp[100];
                        Products=fopen("Products.txt","r");
                        FILE *temp1=fopen("temp.txt","w");
                        printf("\nProductID ");
                        scanf("%d",&ProductID1);

                        ///-------------
                        while (!feof(Products))
                        {
                            fscanf(Products,"%d",&ProductID);
                            //printf("%d\n", ProductID);
                            if (ProductID1==ProductID) flag=1;
                            else
                                flag=0;
                            int y=0;
                            strcpy(ProductName,"");
                            do
                            {
                              fscanf(Products,"%s",&temp);

                              if (!isColor(temp)) strcat(ProductName,temp);
                              else
                                  break;

                            } while(1);

                             strcpy(Color,temp);
                             fscanf(Products,"%s",&Weight);
                              fscanf(Products,"%s",&Price);

                               y=0;
                                do
                                {
                                    fscanf(Products,"%c",&h);
                                     if(h!='\n'&&!feof(Products)) City[y++]=h;
                                     else break;

                                } while(1);
                                City[y]='\0';
                                strcpy(City,del(strtrim(City))); //удаление лишних символов
                               City[strlen(City)]='\0';

                              if(!flag){
                                  fprintf(temp1,"\n%d    ",ProductID);
                               fprintf(temp1,"%s ",ProductName);

                               fprintf(temp1,"%s    ",Color);
                               fprintf(temp1,"%s    ",Weight);
                               fprintf(temp1,"%s    ",Price);
                               fprintf(temp1,"%s    ",City);
                              }
                        }

                        ///------------------------------------------------------
                        fclose(temp1);
                        fclose(Products);
                        system("del Products.txt");
                        system("rename temp.txt Products.txt");
                        printf("\nIf there was an element, element was deleted\n");
                               break;
                           }
                    case 3:
                    {
                        int ProductID;
                        int ProductID1;
                        char  ProductName1[200];
                        char  ProductName[200];
                        char  Color[200];
                         char h;
                        char Weight[20];
                        char Price[200];
                        char City[100];
                        char temp[100];
                        int flag=0;
                       // char temp[100];
                        Products=fopen("Products.txt","r");
                        FILE *temp1=fopen("temp.txt","w");
                        printf("\nProductID ");
                        scanf("%d",&ProductID1);

                        ///-------------
                        while (!feof(Products))
                        {
                            fscanf(Products,"%d",&ProductID);
                            //printf("%d\n", ProductID);
                            if (ProductID1==ProductID) flag=1;
                            else
                                flag=0;
                            int y=0;
                            strcpy(ProductName,"");
                            do
                            {
                              fscanf(Products,"%s",&temp);

                              if (!isColor(temp)) strcat(ProductName,temp);
                              else
                                  break;

                            } while(1);

                             strcpy(Color,temp);
                             fscanf(Products,"%s",&Weight);
                              fscanf(Products,"%s",&Price);

                               y=0;
                                do
                                {
                                    fscanf(Products,"%c",&h);
                                     if(h!='\n'&&!feof(Products)) City[y++]=h;
                                     else break;

                                } while(1);
                                City[y]='\0';
                                strcpy(City,del(strtrim(City))); //удаление лишних символов
                               City[strlen(City)]='\0';

                              if(!flag){
                                  fprintf(temp1,"\n%d    ",ProductID);
                               fprintf(temp1,"%s ",ProductName);

                               fprintf(temp1,"%s    ",Color);
                               fprintf(temp1,"%s    ",Weight);
                               fprintf(temp1,"%s    ",Price);
                               fprintf(temp1,"%s    ",City);
                              }
                              else
                              {
                                  printf("ProductName ");
                                  fflush(stdin);
                                  gets(ProductName);
                                  //хотим проверить их уникальность-а тут уже не надо проверять
                                  printf("Color ");
                                  gets(Color);
                                  do
                                  {
                                  printf("Weight ");
                                  scanf("%s", &Weight);
                                  if(!atof(Weight)) continue;
                                      double  u=atof(Weight);
                                      if (u<0) continue;
                                  break;
                                  } while(1);
                                  do
                                  {
                                  printf("Price ");
                                  scanf("%s", &Price);
                                  if(!(atof(Price))&&(Price[0]-'0')!=0) continue;

                                      double  u=atof(Price);
                                      if (u<0) continue;

                                  break;
                                  } while(1);

                                  printf("City ");
                                  fflush(stdin);
                                  gets(City);
                                  fprintf(temp1,"\n%d    ",ProductID);
                               fprintf(temp1,"%s ",ProductName);
                               fprintf(temp1,"%s    ",Color);
                               fprintf(temp1,"%s    ",Weight);
                               fprintf(temp1,"%s    ",Price);
                               fprintf(temp1,"%s    ",City);
                              }
                        }

                        ///------------------------------------------------------
                        fclose(temp1);
                        fclose(Products);
                        system("del Products.txt");
                        system("rename temp.txt Products.txt");
                        printf("\nIf there was an element, element was changed\n");
                               break;
                           }
                    }
                break;
             }
         case 3:
            {
                break; //неинтересно, потом
            }

          case 4:
          { ///задание часть 1
                FILE *otvet=fopen("otvet","a+");
                char City1[200]; ///первый блок


                int SupplierID;

                char  SupplierName[200];
                char  SupplierName1[200];
                int Status;
                char City[100];
               int ShipmentID_sp; // идентификатор поставки
              int   SupplierID_sp; //идентификатор поставщика
                int ProductID_sp; // идентификатор продукта
                int Qty_sp; //количество

                int ProductID; //продукты
                int ProductID1;
                char  ProductName1[200];
                char  ProductName[200];
                char  Color[200];
                 char h;
                char Weight[20];
                char Price[200];
                char City[100];
                char temp[100];
           #include <D:\13\Progr\lab10\variant1.c>

                break;
            }
        }
     }




return 0;
}
