#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
struct SalesOrderDetail {
    int SalesOrderID;
    int SalesOrderDetailID;
    int OrderQty;
    int ProductID;
    float UnitPrice;
    float UnitPriceDiscount;
    char ModifiedDate[20];
} S[1000];
int comp (struct SalesOrderDetail  *ch, struct SalesOrderDetail  *s)
{
return ch->SalesOrderID - s->SalesOrderID;

}
///-----------------
void siftDown( struct SalesOrderDetail *numbers, int root, int bottom) { //по SalesOrderID
  int done, maxChild;
  struct SalesOrderDetail temp;
  done = 0;
  while ((root*2 <= bottom) && (!done)) {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2].SalesOrderID > numbers[root * 2 + 1].SalesOrderID)
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (numbers[root].SalesOrderID < numbers[maxChild].SalesOrderID) {
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }  else
      done = 1;
  }
}
void heapSort(struct SalesOrderDetail *numbers, int array_size) {
  int i;
  struct SalesOrderDetail temp;
  for (i = (array_size / 2)-1; i >= 0; i--)
    siftDown(numbers, i, array_size);
  for (i = array_size-1; i >= 1; i--) {
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i-1);
  }
}
///-------
void siftDown2( struct SalesOrderDetail *numbers, int root, int bottom) { //по UnitPrice
  int done, maxChild;
  struct SalesOrderDetail temp;
  done = 0;
  while ((root*2 <= bottom) && (!done)) {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2].UnitPrice > numbers[root * 2 + 1].UnitPrice)
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (numbers[root].UnitPrice< numbers[maxChild].UnitPrice) {
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }  else
      done = 1;
  }
}
void heapSort2(struct SalesOrderDetail *numbers, int array_size) {
  int i;
  struct SalesOrderDetail temp;
  for (i = (array_size / 2)-1; i >= 0; i--)
    siftDown2(numbers, i, array_size);
  for (i = array_size-1; i >= 1; i--) {
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown2(numbers, 0, i-1);
  }
}
///-------
///-----
void siftDown3( struct SalesOrderDetail *numbers, int root, int bottom) { //по SalesOrderID
  int done, maxChild;
  struct SalesOrderDetail temp;
  done = 0;
  while ((root*2 <= bottom) && (!done)) {
    if (root*2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2].SalesOrderID > numbers[root * 2 + 1].SalesOrderID)
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    if (numbers[root].SalesOrderID < numbers[maxChild].SalesOrderID) {
      temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }  else
      done = 1;
  }
}
void heapSort3(struct SalesOrderDetail *numbers, int array_size) {
  int i;
  struct SalesOrderDetail temp;
  for (i = (array_size / 2)-1; i >= 0; i--)
    siftDown3(numbers, i, array_size);
  for (i = array_size-1; i >= 1; i--) {
    temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown3(numbers, 0, i-1);
  }
}
/// ----

int main()
{
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
     strcpy(s,"");
   // }
   fclose(fp);
   printf("File was sorted by SalesOrderID, SalesOrderDetailID and UnitPrice\n");
   printf("You can see retults in 1_out.txt, 2_out.txt,3_out.txt");

    // hh1(&S,i); // сортируем по 2 полю
   heapSort2(S,i);
    FILE *fp2=fopen("2_out.txt","w");
      for(int z=0;z<i-1;z++)
      {
          fprintf(fp2,"#%d %d ",z, S[z].SalesOrderID);
          fprintf(fp2,"%d %d %d %lf %lf %s\n",S[z].SalesOrderDetailID,S[z].OrderQty,S[z].ProductID,S[z].UnitPrice, S[z].UnitPriceDiscount,S[z].ModifiedDate);
      }
      fclose(fp2);
    heapSort3(S,i);//(&S,i); // сортируем по 3полю
     FILE *fp3=fopen("3_out.txt","w");
       for(int z=0;z<i;z++)
       {
           fprintf(fp3,"#%d %d ",z, S[z].SalesOrderID);
           fprintf(fp3,"%d %d %d %lf %lf %s\n",S[z].SalesOrderDetailID,S[z].OrderQty,S[z].ProductID,S[z].UnitPrice, S[z].UnitPriceDiscount,S[z].ModifiedDate);
       }
       fclose(fp2);

      // hh(&S,i); // сортируем по первому полю
       heapSort(S,i);
      FILE *fp1=fopen("1_out.txt","w");
        for(int z=0;z<i;z++)
        {
            fprintf(fp1,"#%d %d ",z, S[z].SalesOrderID);
            fprintf(fp1,"%d %d %d %lf %lf %s\n",S[z].SalesOrderDetailID,S[z].OrderQty,S[z].ProductID,S[z].UnitPrice, S[z].UnitPriceDiscount,S[z].ModifiedDate);
        }
        fclose(fp1);
       printf("\nInput SalesOrderID for search:");
      struct SalesOrderDetail z;
      int u;
        scanf("%d",&u);

        z.SalesOrderID=u;

        struct SalesOrderDetail *p;


p = (struct SalesOrderDetail  *) bsearch(&z,S, i, sizeof(S[0]), comp); //сравнивает по первому элементу
printf("\nStruct:\n");
printf("%d\n",p->SalesOrderID);
printf("%d\n",p->SalesOrderDetailID);
printf("%d\n",p->OrderQty);
printf("%d\n",p->ProductID);
printf("%f\n",p->UnitPrice);
printf("%f\n",p->UnitPriceDiscount);
printf("%\n",p->ModifiedDate[20]);


    return 0;
}
