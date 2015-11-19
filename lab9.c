#include <stdio.h>
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
    FILE *f=fopen("SalesOrderDetails.xml","r");
    while (pch != NULL)                         // пока есть лексемы
     {
         pch = strtok (NULL, "<>");
         pch = strtok (NULL, " ,.-");
     }

    do
    {
        int u=menu2();
        printf("");

    }while (1);
    return 0;
}
