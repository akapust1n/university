#include <stdio.h>
#include <time.h>
void main()
{
   char* Day[7] = {
                    "Sunday"  , "Monday", "Tuesday", "Wednesday",
                    "Thursday", "Friday", "Saturday"
                  };
   char* Month[12] = {
                      "January",   "February", "March",    "April",
                      "May",       "June",     "July",     "August",
                      "September", "October",  "November", "December"
                     };
   char* Suffix[4] = { "st", "nd", "rd", "th" };

   int i = 3;                        /* Day suffix index               */
   struct tm *OurT = NULL;           /* Pointer for the time structure */
   time_t Tval = 0;                  /* Calendar time                  */

   Tval = time(NULL);                /* Get calendar time              */
   OurT = localtime(&Tval);          /* Generate time structure        */

   switch( OurT->tm_mday )
   {
     case 1: case 21: case 31:
       i = 0;                        /* Select "st" */
       break;
     case 2: case 22: 
       i = 1;                        /* Select "nd" */
       break;
     case 3: case 23:
       i = 2;                        /* Select "rd" */
       break;
     default:
       i = 3;                        /* Select "th" */
       break;
   }

   printf("\nToday is %s the %d%s %s %d", Day[OurT->tm_wday],
               OurT->tm_mday, Suffix[i], Month[OurT->tm_mon], 
                                        1900 + OurT->tm_year);
   printf("\nThe time is %d : %d : %d\n",
                  OurT->tm_hour, OurT->tm_min, OurT->tm_sec );
}
