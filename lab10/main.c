#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
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
int isBlackDelivery(int idship[],int id)
{
    for(int i=0;idship[i];i++)
    if (idship[i]==id)
        return 1;
    return 0;

}
int isCitySupplier(int idship[],int id)
{
    for(int i=0;idship[i];i++)
    if (idship[i]==id)
        return 1;
    return 0;

}
int isProductID (int idship[],int id)
{
    for(int i=0;idship[i];i++)
    if (idship[i]==id)
        return i+1;
    return 0;

}
int isSampleID (int idship[],int id)
{
    for(int i=0;idship[i];i++)
    if (idship[i]==id)
        return 1;
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
    if(!strcmp("White",color1)) return 1;
    return 0;

}
struct Shipment1
{

     int ShipmentID ;
    int SupplierID;
    int ProductID;
   int Qty;

} Shipments1;
struct Product1
{

    int ProductID ;
    char ProductName[100] ;
    char Color [100];
    char Weight[20];
    char Price[200];
    char City[100];

} Products1;

struct Supplier1
{

    int SupplierID;
  char  SupplierName[200];
  int Status;
  char City[100];

} Suppliers1;

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
    setlocale(LC_ALL, ".ACP");//разделитель atof -запятая
    //from txt to binary

      FILE *Suppliers2=fopen("Suppliers2.bin","wb");
     Suppliers=fopen("Suppliers.txt","a+");
     int i=0;
     while (!feof(Suppliers))
     {
         fscanf(Suppliers,"%d",&Suppliers1.SupplierID);
         i++;
         int y=0;
         do
         {

             ;
             fscanf(Suppliers,"%c",&h);
             //if (h==' ') continue;
              if(h>59||h<47) Suppliers1.SupplierName[y++]=h;
              else break;

         } while(1);
          Suppliers1.SupplierName[y]='\0';
         strcpy(Suppliers1.SupplierName,del(strtrim(Suppliers1.SupplierName))); //удаление лишних символов
        Suppliers1.SupplierName[strlen(Suppliers1.SupplierName)-1]='\0';
                // puts(SupplierName);
                // printf("%s__%s__%d %d\n",SupplierName1,SupplierName,strlen(SupplierName1),strlen(SupplierName));

       if(h)  Suppliers1.Status=h-'0';
         y=0;
         fscanf(Suppliers,"%c",&h);
                 if (h<58)
         {
             Suppliers1.Status*=10;
             Suppliers1.Status+=(h-'0');
         }
         else
         { Suppliers1.City[y++]=h;}

             do
             {
                 fscanf(Suppliers,"%c",&h);
                  if(h!='\n'&&!feof(Suppliers)) Suppliers1.City[y++]=h;
                  else break;

             } while(1);
            Suppliers1.City[y]='\0';
           // printf("Suppliers1.City[y]%s \n",Suppliers1.City);
             strcpy(Suppliers1.City,del(strtrim(Suppliers1.City))); //удаление лишних символов
            Suppliers1.City[strlen(Suppliers1.City)]='\0';  //а может и -1
            //printf("%d\n", Suppliers1.SupplierID);
            fwrite(&Suppliers1, sizeof(Suppliers1),1,Suppliers2);
            strcpy(Suppliers1.SupplierName,"");
            strcpy(Suppliers1.City,"");

        }
     fclose(Suppliers);
     fclose(Suppliers2);
     ///читаем продукты
     char temp[200];
      FILE *Products2=fopen("Products2.bin","wb");
      Products=fopen("Products.txt","r");;
      while (!feof(Products))
        {
         fscanf(Products,"%d",&Products1.ProductID);
        //  printf("%d\n", Products1.ProductID);
          int y=0;
          do
          {
          fscanf(Products,"%s",&temp);
          if (!isColor(temp)) strcat(Products1.ProductName,temp);
          else
           break;
          } while(1);

            strcpy(Products1.Color,temp);
             fscanf(Products,"%s",&Products1.Weight);
              fscanf(Products,"%s",&Products1.Price);
              y=0;
                do
              {
                fscanf(Products,"%c",&h);
                 if(h!='\n'&&!feof(Products)) Products1.City[y++]=h;
                 else break;
              } while(1);
              Products1.City[y]='\0';
              strcpy(Products1.City,del(strtrim(Products1.City))); //удаление лишних символов
               Products1.City[strlen(Products1.City)]='\0';
               fwrite(&Products1, sizeof(Products1),1,Products2);
               strcpy(Products1. ProductName,"") ;
               strcpy(Products1. Color,"");
               strcpy(Products1. Weight,"");
               strcpy(Products1. Price,"");
               strcpy(Products1. City,"");

                  }
 fclose(Products);
 fclose(Products2);
 /// Поставки
   FILE *Shipments2=fopen("Shipments2.bin","wb");
   Shipments=fopen("Shipments.txt","r");
   while (!feof(Shipments))
   {

       fscanf(Shipments,"%d",&Shipments1.ShipmentID);
      fscanf(Shipments,"%d",&Shipments1.SupplierID);
      fscanf(Shipments,"%d",&Shipments1.ProductID);
     fscanf(Shipments,"%d",&Shipments1.Qty);
     fwrite(&Shipments1, sizeof(Shipments1),1,Shipments2);

   }
   fclose(Shipments);
   fclose(Shipments2);
   while(1)
   {
       int u=menu2();
       int u1;
       if(u!=4) u1=menu1();
       switch (u)
       {
           case 1:
           {
               switch (u1)
               {
                   case 1:
                    {
                         struct Supplier1 Suppliers_wrk;
                         start1:
                       printf("\nInput data for adding:\n");
                       printf("SupplierName ");
                       fflush(stdin);
                       gets(Suppliers_wrk.SupplierName);

                       do{
                           printf("Status ");
                        scanf("%d", &Suppliers_wrk.Status);
                       } while(Suppliers_wrk.Status>100||Suppliers_wrk.Status<1);
                       printf("City ");
                       fflush(stdin);
                       gets(Suppliers_wrk.City);

                       Suppliers2=fopen("Suppliers2.bin","ab+");
                       //fseek(Suppliers2, 0, SEEK_SET);
                       int sch=0;
                       while(!feof(Suppliers2))
                       {
                           sch++;
                           printf("%d", sizeof(Suppliers1));

                          fread(&Suppliers1,sizeof(Suppliers1),1,Suppliers2);
                           if(!strcmp(Suppliers1.SupplierName,Suppliers_wrk.SupplierName)){
                              printf("Isnt unique identifier\n");
                               goto start1;
                           }
                          printf("lol %d\n",Suppliers1.SupplierID );
                       }
                       Suppliers_wrk.SupplierID=Suppliers1.SupplierID+1;
                       fwrite(&Suppliers_wrk, sizeof(Suppliers_wrk),1,Shipments2);
                      fclose(Suppliers2);
                      printf("Element was added to  binary file\n");
                      break;
                   }
                   case 2:
                    {

                       int SupplierID;
                       printf("\nInput data for deleting:\n");
                       printf("SupplierID ");
                       scanf("%d", &SupplierID);
                       Suppliers2=fopen("Suppliers2.bin","ab+");
                       //fseek(Suppliers2, 0, SEEK_SET);
                       int sch=0;

                       FILE *temp=fopen("temp.bin","wb");
                       while(!feof(Suppliers2))
                       {
                           sch++;
                           printf("%d", sizeof(Suppliers1));

                          fread(&Suppliers1,sizeof(Suppliers1),1,Suppliers2);
                           if(Suppliers1.SupplierID==SupplierID) continue;
                          fwrite(&Suppliers1, sizeof(Suppliers1),1,temp);

                       }
                       fclose(Suppliers2);
                       fclose(temp);
                       system("del Suppliers2.bin");
                        system("rename temp.bin Suppliers2.bin");
                        printf("\nIf there had been  this element, element was deleted\n");

                      break;
                   }
                   case 3:
                    {
                       struct Supplier1 Suppliers_wrk;




                       printf("\nInput data for changing:\n");
                       printf("SupplierID ");
                       scanf("%d", &Suppliers_wrk.SupplierID);

                       //fseek(Suppliers2, 0, SEEK_SET);
                       int sch=0;
                       Suppliers2=fopen("Suppliers2.bin","rb");
                       FILE *temp=fopen("temp.bin","wb");
                       int flag=0;
                       while(!feof(Suppliers2))
                       {
                           sch++;
                           printf("%d", sizeof(Suppliers1));

                          fread(&Suppliers1,sizeof(Suppliers1),1,Suppliers2);
                           if(Suppliers1.SupplierID==Suppliers_wrk.SupplierID&&flag==0) {
                               flag--;
                               printf("SupplierName ");
                               fflush(stdin);
                               gets(Suppliers_wrk.SupplierName);

                               do{
                                   printf("Status ");
                                scanf("%d", &Suppliers_wrk.Status);
                               } while(Suppliers_wrk.Status>100||Suppliers_wrk.Status<1);
                               printf("City ");
                               fflush(stdin);
                               gets(Suppliers_wrk.City);
                               fwrite(&Suppliers_wrk, sizeof(Suppliers_wrk),1,temp);
                                printf("\n Element was changed\n");
                               continue;
                           }
                        if(Suppliers_wrk.SupplierID!=Suppliers1.SupplierID)  fwrite(&Suppliers1, sizeof(Suppliers1),1,temp);
                               printf("lol %d\n",Suppliers1.SupplierID );

                       }
                       fclose(Suppliers2);
                       fclose(temp);
                       system("del Suppliers2.bin");
                        system("rename temp.bin Suppliers2.bin");



                      break;
                   }
               }

               break;
           }
           case 2:
           {
               switch (u1)
               {
                  case 1:{ struct Product1 Products_wrk;
                  printf("\nInput data for adding:\n");
                  printf("ProductsName ");
                    fflush(stdin);
                  gets(Products_wrk.ProductName);
               printf("Color ");
                fflush(stdin);
                gets(Products_wrk.Color);
                do
                 {
                    printf("Weight ");
                    scanf("%s",&Products_wrk.Weight);
                    if(!atof(Products_wrk.Weight)) continue;
                      double  u=atof(Products_wrk.Weight);
                       if (u<0) continue;
                     break;
                     } while(1);
                     do
                    {
                     printf("Price ");
                      scanf("%s", &Products_wrk.Price);
                     if(!(atof(Products_wrk.Price))&&(Products_wrk.Price[0]-'0')!=0) continue;
                     double  u=atof(Products_wrk.Price);
                     if (u<0) continue;
                      break;
                     } while(1);
                        printf("City ");
                        fflush(stdin);
                        gets(Products_wrk.City);
                        Products2=fopen("Products2.bin","ab+");
                        while (!feof(Products2))
                        {
                            fread(&Products1,sizeof(Products1),1,Products2);
                             if(feof(Products2)) break;
                        }
                        Products_wrk.ProductID=Products1.ProductID+1;
                        fwrite(&Products_wrk,sizeof(Products_wrk),1,Products2);
                        fclose(Products2);
                           Products2=fopen("Products2.bin","ab+");
                        while (!feof(Products2))
                        {
                            fread(&Products1,sizeof(Products1),1,Products2);
                            printf("%s \n",Products1.ProductName);
                        }
                        fclose(Products2);

                    break;
                   }
                    case 2:
                   {
                       int num;
                       printf("\nInput data for deleting:\n");
                       printf("ProductsID ");
                       scanf("%d",&num);

                       FILE *temp=fopen("temp.bin","wb");
                             Products2=fopen("Products2.bin","ab+");
                             while (!feof(Products2))
                             {

                                 fread(&Products1,sizeof(Products1),1,Products2);
                                 if(feof(Products2)) break;
                                 if(num==Products1.ProductID)continue;
                                 fwrite(&Products1, sizeof(Products1),1,temp);
                             }

                             fclose(Products2);

                             fclose(Products2);
                             fclose(temp);
                             system("del Products2.bin");
                              system("rename temp.bin Products2.bin");
                              printf("\nIf there had been  this element, element was deleted\n");
                              Products2=fopen("Products2.bin","ab+");
                           while (!feof(Products2))
                           {
                               fread(&Products1,sizeof(Products1),1,Products2);
                               printf("%s \n",Products1.ProductName);
                           }

                         break;

                   }
                   case 3:
                   {
                        struct Product1 Products_wrk;
                       int num;
                       printf("\nInput data for changing:\n");
                       printf("ProductsID ");
                       scanf("%d",&num);
                       Products_wrk.ProductID=num;
                       printf("ProductName ");
                        fflush(stdin);
                          gets(Products_wrk.ProductName);
                       printf("Color ");
                        fflush(stdin);
                        gets(Products_wrk.Color);
                        do
                         {
                            printf("Weight ");
                            scanf("%s",&Products_wrk.Weight);
                            if(!atof(Products_wrk.Weight)) continue;
                              double  u=atof(Products_wrk.Weight);
                               if (u<0) continue;
                             break;
                             } while(1);
                             do
                            {
                             printf("Price ");
                              scanf("%s", &Products_wrk.Price);
                             if(!(atof(Products_wrk.Price))&&(Products_wrk.Price[0]-'0')!=0) continue;
                             double  u=atof(Products_wrk.Price);
                             if (u<0) continue;
                              break;
                             } while(1);
                                printf("City ");
                                fflush(stdin);
                                gets(Products_wrk.City);
                                FILE *temp=fopen("temp.bin","wb");
                                      Products2=fopen("Products2.bin","ab+");
                                      while (!feof(Products2))
                                      {

                                          fread(&Products1,sizeof(Products1),1,Products2);
                                          if(feof(Products2)) break;
                                          if(num==Products1.ProductID)
                                          {fwrite(&Products_wrk,sizeof(Products_wrk),1,temp);
                                              continue;
                                          }
                                          fwrite(&Products1, sizeof(Products1),1,temp);
                                      }
                                      fclose(Products2);
                                      fclose(temp);


                                system("del Products2.bin");
                                system("rename temp.bin Products2.bin");
                                printf("\nIf there had been  this element, element was changed\n");
                                Products2=fopen("Products2.bin","ab+");
                                while (!feof(Products2))
                                {
                                    fread(&Products1,sizeof(Products1),1,Products2);
                                    printf("%s \n",Products1.ProductName);
                                }
                           fclose(Products2);
                                break;

                   }
                   }

                       break;
           }
          case 3:
           {
               switch (u1)
               {
                   case 1:
                   {
                       struct Shipment1 Shipment_wrk;
                       start2:
                       printf("\nInput data for adding\n");
                       printf("\nShipmentID ");
                       scanf("%d",&Shipment_wrk.ShipmentID);
                       printf("\nSupplierID ");
                       scanf("%d",&Shipment_wrk.SupplierID);
                       printf("\nProductID ");
                       scanf("%d",&Shipment_wrk.ProductID);
                       printf("\nQty ");
                       scanf("%d",&Shipment_wrk.Qty);
                      Shipments2=fopen("Shipments2.bin","ab+");
                      while(!feof(Shipments2))
                      {
                          fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                          if (feof(Shipments2)) break;
                          if (Shipments1.ShipmentID==Shipment_wrk.ShipmentID) {
                              printf("\bIsnt unique key\n");goto start2;}
                      }
                      fwrite(&Shipment_wrk,sizeof(Shipment_wrk),1,Shipments2);
                      fclose(Shipments2);

                      Shipments2=fopen("Shipments2.bin","ab+");
                      while(!feof(Shipments2))
                      {
                          fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                          printf("%d\n",Shipments1.ProductID);
                      }
                      fclose(Shipments2);
                      break;
                   }
                   case 2:
                   {
                      int ship;
                       printf("\nInput data for deleting\n");
                       printf("\nShipmentID ");
                       scanf("%d",&ship);
                      Shipments2=fopen("Shipments2.bin","ab+");
                       FILE *temp=fopen("temp.bin","wb");
                      while(!feof(Shipments2))
                      {
                          fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                          if (feof(Shipments2)) break;
                          if (Shipments1.ShipmentID==ship) continue;
                          fwrite(&Shipments1,sizeof(Shipments1),1,temp);

                      }

                      fclose(Shipments2);
                      fclose(temp);
                      system("del Shipments2.bin");
                      system("rename temp.bin Shipments2.bin");
                      printf("\nIf there had been  this element, element was deleted\n");
                      Shipments2=fopen("Shipments2.bin","ab+");
                      while(!feof(Shipments2))
                      {
                          fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                          printf("%d\n",Shipments1.ProductID);
                      }
                      fclose(Shipments2);
                      break;
                   }
                   case 3:
                   {

                       printf("\nInput data for changing\n");
                       struct Shipment1 Shipment_wrk;

                       printf("\nInput data for adding\n");
                       printf("\nShipmentID ");
                       scanf("%d",&Shipment_wrk.ShipmentID);
                       printf("\nSupplierID ");
                       scanf("%d",&Shipment_wrk.SupplierID);
                       printf("\nProductID ");
                       scanf("%d",&Shipment_wrk.ProductID);
                       printf("\nQty ");
                       scanf("%d",&Shipment_wrk.Qty);
                      Shipments2=fopen("Shipments2.bin","ab+");
                       FILE *temp=fopen("temp.bin","wb");
                      while(!feof(Shipments2))
                      {
                          fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                          if (feof(Shipments2)) break;
                          if (Shipments1.ShipmentID==Shipment_wrk.ShipmentID){
                              fwrite(&Shipment_wrk,sizeof(Shipment_wrk),1,temp);
                              continue;}
                          fwrite(&Shipments1,sizeof(Shipments1),1,temp);

                      }

                      fclose(Shipments2);
                      fclose(temp);
                      system("del Shipments2.bin");
                      system("rename temp.bin Shipments2.bin");
                      printf("\nIf there had been  this element, element was changed\n");
                      Shipments2=fopen("Shipments2.bin","ab+");
                      while(!feof(Shipments2))
                      {
                          fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                          printf("%d\n",Shipments1.ProductID);
                      }
                      fclose(Shipments2);
                      break;
                   }
               }

               break;
           }
           case 4:
              { //часть один
                  FILE *result=fopen("result.txt","w");

                  char City1[199];
                  int idproduct[100];//продукты, которые поставляют поставщики
                  int idqty[100];  //количество
                  int idship[100]; //id поставщиков из города
                  int index=0;
                  double price1=0.0;
                   for(int i=0;i<100;i++) idproduct[i]=0;
                   for(int i=0;i<100;i++) idqty[i]=0;
                   for(int i=0;i<100;i++) idship[i]=0;
                   printf("\nCity ");
                   fflush(stdin);
                   gets(City1);
                   Suppliers2=fopen("Suppliers2.bin","rb+");

                   while(!feof(Suppliers2))
                   {
                     fread(&Suppliers1,sizeof(Suppliers1),1,Suppliers2);

                     if(!strcmp(Suppliers1.City,City1))
                     {


                         idship[index++]=Suppliers1.SupplierID;

                     }
                   }
                     fclose(Suppliers2);
                       index=0;
                     Shipments2=fopen("Shipments2.bin","rb");
                     while (!feof(Shipments2))
                     {

                         fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                     if(isCitySupplier(idship,Shipments1.SupplierID))
                      {
                         idproduct[index]=Shipments1.ProductID;
                      idqty[index++]=Shipments1.Qty;
                       }
                     }
                    fclose(Shipments2);
                    Products2=fopen("Products2.bin","rb");
                    while(!feof(Products2))
                    {
                      fread(&Products1,sizeof(Products1),1,Products2);
                       if(feof(Products2)) break;
                      if(isProductID(idproduct,Products1.ProductID))
                      {


                                price1+=atof(Products1.Price)*idqty[isProductID(idproduct,Products1.ProductID)-1];
                                //printf("\n %s %d",Products1.Price,idqty[isProductID(idproduct,Products1.ProductID)-1]);
                      }

                    }

                    //printf("\n%lf______", price1);
                    fprintf(result,"Task 1: City %s\n",City1);
                    fprintf(result,"Sum %lf\n",price1);
                    ///----------------------------------------
                    //часть 2
                    ///----------
                    /// общая идея- считаем количество продуктов всего, считаем в поствках у каждого поставщика кол-во продуктов
                    /// и сравниваем
                    for(int i=0;i<50;i++) fprintf(result,"-");
                    fprintf(result,"\nSuppliers all kind of products\n");
                    int dif_prod=0; //считаем сколько всего различных продуктов
                    Products2=fopen("Products2.bin","rb");
                    while (!feof(Products2))
                    {
                        fread(&Products1,sizeof(Products1),1,Products2);
                         if(feof(Products2)) break;
                         dif_prod++;
                    }
                    fclose(Products2);
                    int dif_prod_check=0;
                    int dif_prod_pred=0;
                    Shipments2=fopen("Shipments2.bin","rb");
                    while (!feof(Shipments2))
                    {
                       fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                       if(feof(Products2)) break;
                       if(Shipments1.SupplierID==dif_prod_pred) dif_prod_check++;
                       else
                       {
                           dif_prod_pred=Shipments1.SupplierID;
                           dif_prod_check=0   ;
                       }
                       if (dif_prod==dif_prod_check)
                       {
                           Suppliers2=fopen("Suppliers2.bin","rb");
                           while (!feof(Suppliers2))
                           {
                               fread(&Suppliers1,sizeof(Suppliers1),1,Suppliers2);
                               if(feof(Suppliers)) break;
                               if(Suppliers1.SupplierID==Shipments1.SupplierID)
                                   fprintf(result,"%s\n",Suppliers1.SupplierName);
                           }
                           fclose(Suppliers2);

                       }
                    }
                    fclose(Shipments2);
                    ///---------
                    // часть 3
                    ///-----
                    int black_list[1000];
                    int black_num;
                    index=0;
                    for(int i=0;i<1000;i++ ) black_list[i]=0;
                    for(int i=0;i<50;i++) fprintf(result,"-");
                     printf("\nProduct # isnt delevery ");
                     scanf("%d", &black_num);
                     Shipments2=fopen("Shipments2.bin","rb");
                     while (!feof(Shipments2))
                     {
                         fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                         if(feof(Shipments2)) break;
                         if(Shipments1.ProductID==black_num) black_list[index++]=Shipments1.SupplierID;
                     }
                     fclose(Shipments2);
                     fprintf(result,"\nDont delivery product #%d\n",black_num);
                     Suppliers2=fopen("Suppliers2.bin","rb");
                     while (!feof(Suppliers2))
                     {
                         fread(&Suppliers1,sizeof(Suppliers1),1,Suppliers2);
                         if (feof(Suppliers2)) break;
                         if(!isBlackDelivery(black_list,Suppliers1.SupplierID))
                             fprintf(result,"\n%s",Suppliers1.SupplierName);
                     }
                     fclose(Suppliers2);
                     fprintf(result,"\n\n");
                     ///---------
                     // часть 4
                     ///-----
                     /// заносим в массив продукты поставщика №_. пробегаемся по файлу ещё раз, выписываем Suplid
                     /// которые поставляют эти продукты. Потом из supplires2 по id берем имена
                     int sample_supl[100];
                     int black_sample_supl_list[1000];
                     int number4;
                    for(int i=0;i<50;i++) fprintf(result,"-");
                     for(int i=0;i<100;i++) sample_supl[i]=0;
                     for(int i=0;i<1000;i++) black_sample_supl_list[i]=0;
                     printf("\nNumber for paragraph 4 ");
                     scanf("%d",&number4);
                     fprintf(result,"\nNeeded companises for number #%d\n",number4);
                     index=0;
                     Shipments2=fopen("Shipments2.bin","rb");
                     while (!feof(Shipments2))
                     {
                         fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                         if(feof(Shipments2)) break;
                         if(Shipments1.SupplierID==number4) sample_supl[index++]=Shipments1.ProductID;
                     }
                      fclose(Shipments2);
                      Shipments2=fopen("Shipments2.bin","rb");
                      index=0;
                      while (!feof(Shipments2))
                      {
                          fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                          if(feof(Shipments2)) break;
                          if(isSampleID(sample_supl,Shipments1.ProductID) ) black_sample_supl_list[index++]=Shipments1.SupplierID;
                      }
                      fclose(Shipments2);
                      Suppliers2=fopen("Suppliers2.bin","rb");
                      while (!feof(Suppliers2))
                      {
                          fread(&Suppliers1,sizeof(Suppliers1),1,Suppliers2);
                          if (feof(Suppliers2)) break;
                          if(isSampleID(black_sample_supl_list,Suppliers1.SupplierID))
                                  fprintf(result,"\n%s",Suppliers1.SupplierName);
                      }
                      fclose(Suppliers2);
                      fprintf(result,"\n");
                      for(int i=0;i<50;i++) fprintf(result,"-");
                      ///---------
                      // часть 5
                      ///-----
                      /// Выписываем в массив все продукты из города, потом смотрим поставляются ли они
                      char town[100];
                      int products_city[100];
                      double products_city_price[100];
                      double price2=0.0;
                      for(int i=0;i<100;i++) products_city[i]=0;
                      for(int i=0;i<100;i++) products_city_price[i]=0;
                      index=0;
                      printf("\n City for parahraph 5 ");
                      fflush(stdin);
                      gets(town);
                      Products2=fopen("Products2.bin","rb");
                      while (!feof(Products2))
                      {
                          fread(&Products1,sizeof(Products1),1,Products2);
                           if(feof(Products2)) break;
                           if (!strcmp(town,Products1.City))
                           { products_city[index]=Products1.ProductID;
                               products_city_price[index++]=atof(Products1.Price);
                           }

                      }
                    fclose(Products2);
                    Shipments2=fopen("Shipments2.bin","rb");
                    while (!feof(Shipments2))
                    {
                        fread(&Shipments1,sizeof(Shipments1),1,Shipments2);
                        if(feof(Shipments2)) break;
                        if(isProductID(products_city,Shipments1.ProductID) )
                           {
                            printf("%lf\n",products_city_price[isProductID(products_city,Shipments1.ProductID)-1]);
                            price2+=Shipments1.Qty*products_city_price[isProductID(products_city,Shipments1.ProductID)-1];
                        }
                    }
                    fclose(Shipments2);
                    fprintf(result,"\nSum %lf",price2);
                    fclose(result);
                     break;
                   }





       }

   }


return 0;
}
