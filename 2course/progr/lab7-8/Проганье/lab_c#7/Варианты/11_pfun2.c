#include <stdio.h>

/* Function prototypes   */
int sum(int, int);
int product(int, int);
int difference(int, int);

void main()
{
   int i = 0;                 /* Loop counter                       */
   int a = 10;                /* Initial value for a                */
   int b = 5;                 /* Initial value for b                */
   int result = 0;            /* Storage for results                */
   int (*pfun[3])(int, int);  /* Function pointer array declaration */

   /* Initialize pointers */
   pfun[0] = sum;
   pfun[1] = product;
   pfun[2] = difference;

   /* Execute each function pointed to */
   for( i = 0 ; i < 3 ; i++)
   {
     result = pfun[i](a, b);  /* Call the function through a pointer */
     printf("\nresult = %d", result);        /* Display the result   */
   }

   /* Call all three functions through pointers in an expression */
   result = pfun[1](pfun[0](a, b), pfun[2](a, b));
   printf("\n\nThe product of the sum and the difference = %d", result );
}

/* Definition of the function sum        */
int sum(int x, int y)
{
   return x + y;
}

/* Definition of the function product    */
int product(int x, int y)
{
   return x * y;
}

/* Definition of the function difference */
int difference(int x, int y)
{
   return x - y;
}
