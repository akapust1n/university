#include <stdio.h>
#include <string.h>
char b[100][100];
/*void uu()
{
    char s='2';
    printf("%c\nyy",s);
}*/

char X[10];
char Y[10];

   /*     void     PRINT_LCS(char b[10][10], char X[], int i, int j)
     {   if( (i ==0) || (j ==0))
                   return;
                if( b[i][j] =="\\")
                   {  PRINT_LCS(b, X, i-1, j-1);
                     printf( "%c",X[i]);}
                else if (b[i][j] == '|')
                     PRINT_LCS(b, X, i-1, j);
                else	PRINT_LCS(b, X, i, j-1);
                return;
                }*/
int lsc(void)
{
            puts("lol");

            int 	m = strlen(X) ;
           int  n = strlen(Y) ;
          int c[1002][1002];
            for (int i= 0 ;i<= m;i++)
             c[i][0] = 0 ;
              for (int j= 0 ;j<= n;j++)
                c[0][j] = 0;
            for (int i= 1 ;i<= m;i++)
                  for (int j= 1 ;j<= n;j++)
                     if (X[i] == Y[j])
                        {c[i][j] = c[i-1][j-1] + 1;
                            b[i][j]= '\\';}
                        else if (c[i-1][j] >= c[i][j-1])
                              {  c[i][j] = c[i-1][ j];
                                b[i][j] = '|';}
                            else	{c[i][j] = c[i][j-1];
                                b[i][j] = '-';}
            return 0  ;
        }

 int main()
{

     strcpy(X,"ABCBDAB");
    strcpy(Y,"BDCABA");

 //uu();
  lsc();

  //PRINT_LCS(b, X, strlen(X) ,strlen(Y));
return 0;
     }

