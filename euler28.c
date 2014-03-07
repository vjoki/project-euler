// orz
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   unsigned long sum = 0;
   
   enum Direction { D_LEFT, D_RIGHT, D_UP, D_DOWN };
   enum Direction direction = D_LEFT;
   
   const unsigned size = 1001;
   unsigned **ulam;
   ulam = malloc(size*sizeof(unsigned*));
   unsigned i;
   for(i=0;i<size;i++)
      ulam[i] = malloc(size*sizeof(unsigned));

   unsigned row = 0, col = size-1, offset = col;
   for(i=size*size;i>0;i--) {
      ulam[row][col] = i;
      
      if (direction == D_LEFT) {
         if (col == offset && i != 1)
            sum += i;
            
         if (col > (size-1)-offset)
            col--;
         else {
            sum += i;
            direction = D_DOWN;
            row++;
         }
      } else if (direction == D_DOWN) {
         if (row < offset)
            row++;
         else {
            sum += i;
            direction = D_RIGHT;
            col++;
         }
      } else if (direction == D_RIGHT) {
         if (col < offset)
            col++;
         else {
            if (offset > 0) offset--;
            sum += i;
            direction = D_UP;
            row--;
         }
      } else if (direction == D_UP) {
         if (row > (size-1)-offset)
            row--;
         else {
            direction = D_LEFT;
            col--;
         }
      }
   }
   
   if (size<11) {
      for(row=0;row<size;row++) {
         for(col=0;col<size;col++)
            printf("%.2u ",ulam[row][col]);
         printf("\n");
      }
   }
   
   printf("%lu\n",sum);
   return 0;
}