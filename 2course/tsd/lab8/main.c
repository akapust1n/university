//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define  maxn 100
int N=6;

int min(int a,int b)
{
 if (a<b)
 return a;
else
return b;
}

int a[maxn][maxn];
int W[maxn][maxn];

void floyd()
{
 for (int i=0;i<N;i++)
  for (int j=0;j<N;j++)
  {
      W[i][j]=a[i][j];
    }
 for (int k=0;k<N;k++)
  for (int i=0;i<N;i++)
   for (int j=0;j<N;j++)
           {
       W[i][j] = min(W[i][j], W[i][k] + W[k][j]);
       //printf("%d",W[i][j]);
   }
return;
}

int main()
{
    char uu[8][20]=
    {
     "goldenrod1" , "red1" ,"blue2","green1","black","sienna4","oranged","orchid3"
    };
     FILE *f=fopen("1.txt","r");
     fscanf(f,"%d",&N);
    printf("Adjacency matrix placed in 1.txt");

 for(int i=0 ;i<N;i++)
 {
    for (int j=0;j<N;j++)
    {fscanf(f,"%d",&a[i][j]);

    }
printf("\n");
 }
fclose(f);
 f=fopen("test2.gv","w");
  fprintf(f,"digraph graphname1{\n");
 for(int i=0;i<N;i++)
 {
     for(int j=0;j<N;j++)
     {
         if(i==j||a[i][j]==1000) continue;
         fprintf(f,"%c -> %c[label=%d color=\"%s\" fontcolor=\"%s\"] ; \n",(65+i),(65+j),a[i][j],uu[i%8],uu[i%8]);
        // fprintf(f,"%c -> %c[label=%d color=\"%s\"] ; \n",(67+i),(67+j),W[i][j],uu[i%8]);
         //fprintf(f, "%c -> %c; \n",(char)(67+i),(char)(67+j));

     }
 }
  fprintf(f,"  }");
  fclose(f);
 system("circo  test2.gv -Tpng -om.png");
 system("m.png");

 floyd();

printf("Table  of ways\n\n");
printf("    ");
for(int i=0;i<N;i++)
    printf("%3c ",(65+i));
printf("\n");
 for (int i=0;i<N;i++)
 {
     printf("%3c ",(65+i));
  for(int j=0;j<N;j++)
  {
      if(i!=j) printf("%3d ",W[i][j]);
      else printf(" -- ");
  }

  printf("\n");
 }
 f=fopen("test.gv","w");
 fprintf(f,"digraph graphname{\n");

 for(int i=0;i<N;i++)
 {
     for(int j=0;j<N;j++)
     {
         if(i==j) continue;
         fprintf(f,"%c -> %c[label=%d color=\"%s\" fontcolor=\"%s\"] ; \n",(65+i),(65+j),W[i][j],uu[i%8],uu[i%8]);
        // fprintf(f,"%c -> %c[label=%d color=\"%s\"] ; \n",(67+i),(67+j),W[i][j],uu[i%8]);
         //fprintf(f, "%c -> %c; \n",(char)(67+i),(char)(67+j));

     }
 }
 fprintf(f,"  }");
 fclose(f);
 system("circo  test.gv -Tpng -og.png");
 system("g.png");
return 0;
}
