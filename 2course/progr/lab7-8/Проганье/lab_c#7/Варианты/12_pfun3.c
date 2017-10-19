#include <stdio.h>

/* Function prototypes */
int sum(int,int);
int product(int,int);
int difference(int,int);
int any_function(int(*pfun)(int, int), int x, int y);

void main()
{
   int a = 10;                  /* Initial value for a */
   int b = 5;                   /* Initial value for b */
   int result = 0;              /* Storage for results */
   int (*pf)(int, int) = sum;   /* Pointer to function */

   /* Passing a pointer to a function */
   result = any_function(pf, a, b); 

   printf("\nresult = %d", result );

   /* Passing the address of a function      */
   result = any_function(product,a, b);   

   printf("\nresult = %d", result );

   printf("\nresult = %d", any_function(difference, a, b));
}

/* Definition of a function to call a function */
int any_function(int(*pfun)(int, int), int x, int y)
{
   return pfun(x, y);
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
