#include <stdio.h>

/* Function prototypes */
int sum(int, int);
int product(int, int);
int difference(int, int);

void main()
{
   int a = 10;            /* Initial value for a               */
   int b = 5;             /* Initial value for b               */
   int result = 0;        /* Storage for results               */
   int (*pfun)(int, int); /* Function pointer declaration      */

   pfun = sum;            /* Points to function sum()          */
   result = pfun(a, b);   /* Call sum() through pointer        */
   printf("\npfun = sum\t\tresult = %d", result );

   pfun = product;        /* Points to function product()      */
   result = pfun(a, b);   /* Call product() through pointer    */
   printf("\npfun = product\t\tresult = %d", result );

   pfun = difference;     /* Points to function difference()   */
   result = pfun(a, b);   /* Call difference() through pointer */
   printf("\npfun = difference\tresult = %d", result );
}

/* Definition of the function sum   */
int sum(int x, int y)
{
   return x + y;
}

/* Definition of the function product   */
int product(int x, int y)
{
   return x * y;
}

/* Definition of the function difference   */
int difference(int x, int y)
{
   return x - y;
}
