#include <stdio.h>
#include <time.h>

double CPU_Timer(void);            /* CPU timer function prototype */
long ElapsedTimer(void);           /* Elapsedtimer function prototype */

int main(void)
{

   long i=0;                      /* Loop counter */
   double CPU=0.0;                 /* Store for CPU time used */
   double x = 0.0;                 /* Result of multiply */

   CPU_Timer();                    /* Initialize processor timing */
   ElapsedTimer();                 /* Initialize elapsed timing */

   for(i=0L;i<10000000;i++)
      x=3.4567 * 4.5678;           /* Multiply 10m times */

   CPU=CPU_Timer();                /* Get time after 10m multiplies */

   printf("\nCPU time for ten million multiplies is %.2f seconds", CPU );

   for(i=0L;i<5000000;i++)
      x = 3.4567 * 4.5678;         /* Multiply another 5m times */

   /* Output total time elapsed */
   printf("\nTotal elapsed time is %d seconds", ElapsedTimer() );
   return 0;
}

/* Timer function */
double CPU_Timer(void)
{
   static clock_t CPU_Last = 0;    /* Holds clock value from last call */
   clock_t CPU_This = 0;
   double CPU_Used=0.0;

   if(CPU_Last)
   {
      CPU_This=clock();            /* Get current processor time */
      CPU_Used=(CPU_This-CPU_Last)/(double)CLOCKS_PER_SEC;
      CPU_Last=CPU_This;
      return CPU_Used;
   }
   /* Only do this first time through */
   CPU_Last=clock();
   return 0.0;
} 

long ElapsedTimer(void)
{
   static time_t El_Last=  0;     /* Holds calendar time from last call */
   time_t El_This = 0;
   long Elapsed=0;
   if(El_Last)                    /* If its not the first time */
   {
      El_This=time(NULL);         /* Get current time value */
      /* Get elapsed clock time  */
      Elapsed=(long)difftime( El_This, El_Last );

      El_Last=El_This;            /* Save the current clock time */

      return Elapsed;             /* Return the time intervals */
   }

   /* We do this only the first time around */
   El_Last=time(NULL);            /* Initialize clock time */
   return 0;                     /* Return zero intervals */
}