#include <stdio.h>
#include <string.h>
struct SalesOrderDetail {
    int SalesOrderID;
    int SalesOrderDetailID;
    int OrderQty;
    int ProductID;
    float UnitPrice;
    float UnitPriceDiscount;
    char ModifiedDate[20];
} S[1000];
int menu()
{
    int i=0;
    printf("Choose number of paragraph for working:\n");
    printf("1)SalesOrderID\n");
    printf("2)SalesOrderDetailID\n");
    printf("3)OrderQty\n");
    printf("4)ProductID\n");
    printf("5)UnitPrice\n");
    printf("6)UnitPriceDiscount\n");
    printf("7)ModifiedDate\n");
    scanf("%d",&i);

    return i;
}

int menu2()
{
    int i=0;
    printf("Choose function:\n");
    printf("1)Print:\n");
    printf("2)Min:\n");
    printf("3)Max:\n");
    printf("4)Successor:\n");
    printf("5)PREDECESSOR\n");
    printf("6)Delete\n");
    scanf("%d",&i);

    return i;

}

int main()
{
    int par=menu();
    char * pch;
    switch(par)
    {
    case 1:{
         pch = strtok (str,"SalesOrderID>");

    }
    }
    FILE *fp=fopen("SalesOrderDetails.xml","r");
        char s[100];
        char * pch;
        fgets(s,99,fp);
        strcpy(s,"");
        int i=0;
        while(1)
        {
         fgets(s,99,fp);
         if (!strcmp(s,"</ROOT>")) break;
         strcpy(s,"");
          fgets(s,99,fp);//первый
           pch = strtok (s,"<SalesOrderID>");
           pch = strtok (NULL,"<\SalesOrderID>");
           S[i].SalesOrderID=atoi(pch);
           strcpy(s,"");
           fgets(s,99,fp); //второй
           pch = strtok (s,"<SalesOrderDetailID>");
           pch = strtok (NULL,"<\\SalesOrderDetailID>");
           S[i].SalesOrderDetailID=atoi(pch);
           strcpy(s,"");
           fgets(s,99,fp); //третий
           pch = strtok (s,"<OrderQty>");
           pch = strtok (NULL,"<\\OrderQty>");
           S[i].OrderQty=atoi(pch);

           strcpy(s,"");
           fgets(s,99,fp); //четвертый
           pch = strtok (s,"<ProductID>");
           pch = strtok (NULL,"<\\ProductID>");
           S[i].ProductID=atoi(pch);
           strcpy(s,"");
           fgets(s,99,fp); //пятый
           pch = strtok (s,"<UnitPrice>");
           pch = strtok (NULL,"<\\UnitPrice>");
           S[i].UnitPrice=atof(pch);

           //printf("%lf\n",atof(pch));
           strcpy(s,"");
           fgets(s,99,fp); //шестой
           pch = strtok (s,"<UnitPriceDiscount>");
           pch = strtok (NULL,"<\\UnitPriceDiscount>");
           S[i].UnitPriceDiscount=atof(pch);
           // printf("%sH %lf \n",pch,atof(pch));
           strcpy(s,"");
           fgets(s,99,fp); //седьмой
           pch = strtok (s,"<ModifiedDate>");
           pch = strtok (NULL,"<\\ModifiedDate>");
            strcpy(S[i].ModifiedDate,pch);
           strcpy(s,"");
           fgets(s,99,fp);
           strcpy(s,"");
           i++;
    }
    do
    {
        int u=menu2();
        printf("");

    }while (1);
    return 0;
}
