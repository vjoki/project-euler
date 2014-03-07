#include <stdio.h>

int main(void)
{
   unsigned year = 1900;
   unsigned endyear = 2000;
   
   printf("start %u, end %u\n",year,endyear);
   
   unsigned sundaycounter = 1;
   
   unsigned month = 1;
   unsigned day = 1;
   unsigned dayofweek = 1; // 1=mon, 7=sun
   unsigned dayofyear = 1;
   unsigned isleap = 0;
   
   while (year<=endyear) {
            
      if (dayofweek == 7) {
         if (day == 1 && year > 1900 && year <= endyear)
            sundaycounter++;
         dayofweek = 1;
      } else dayofweek++;
      
      if (day == 30 && (month == 6 || month == 4 || month == 9 || month == 11)) {
         month++;
         day = 1;
      } else if (month == 3 && day > 27) {
         if (isleap == 1) {
            if (day == 29) {
               month++;
               day = 1;
            } else day++;
         } else {
            if (day == 28) {
               month++;
               day = 1;
            }
         }
      } else if (day == 31 && month != 12) {
         month++;
         day = 1;
      } else if (day == 31 && month == 12) {
         year++;
         
         if (year % 400 == 0)
            isleap = 1;
         else if (year % 100 == 0)
            isleap = 0;
         else if (year % 4 == 0)
            isleap = 1;
         else
            isleap = 0;
         
         month = 1;
         day = 1;
      } else day++;
      
      if (month == 1 && day == 1)
         dayofyear = 1;
      else dayofyear++;

      //if (day == 31 && dayofyear >= 366)
      //   printf("leap %u/%u/%u, sundays on 1st so far %u\n",day,month,year,sundaycounter);
   }
   printf("%u\n",sundaycounter);
   
   return 0;
}