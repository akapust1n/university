
///для первого задания переменная
int idproduct[100];//продукты, которые поставляют поставщики
int idqty[100];  //количество
int idship[20]; //id поставщиков из города
int index=0;
int sum_1=0;
printf("Intput city ");
fflush(stdin);
gets(City1);
Suppliers=fopen("Suppliers.txt","r"); //получаем id поставщиков из этого года
// FILE *Suppliers1=fopen("Suppliers_work.txt","w");
for(int i=0;i<20;i++) idship[i]=0;
for(int i=0;i<100;i++) idproduct[i]=0;
//считываем два идентефикатоа


    //хотим проверить их уникальность

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
           if(!strcmp(City,City1))
           {
               idship[index++]=SupplierID;

           }
    }

for(int i=0;idship[i];i++) printf("%d_", idship[i]);
Shipments=fopen("Shipments.txt","r");
index=0;
while (!feof(Shipments))
{
    char City[100];
   int ShipmentID_sp; // идентификатор поставки
  int   SupplierID_sp; //идентификатор поставщика
    int ProductID_sp; // идентификатор продукта
    int Qty_sp; //ко
    fscanf(Shipments,"%d", &ShipmentID_sp);
    fscanf(Shipments,"%d", &SupplierID_sp);
    fscanf(Shipments,"%d", &ProductID_sp);
    fscanf(Shipments,"%d", &Qty_sp);
            if(isCitySupplier(idship,SupplierID_sp))
             {idproduct[index]=ProductID_sp;
             idqty[index++]=Qty_sp;
              }
}
for(int i=0;idproduct[i];i++) printf("%d*",idproduct[i]);
//все продацы из этого города в idship
//все товары, которые поставляют эти поставщики- в idproduct
//цены этих товаров в idqty
fclose(Shipments);
flose(Suppliers);
Product=fopen("Products.txt", "r");
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












