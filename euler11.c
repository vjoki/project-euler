#include <stdio.h>

int max_si(int a, int b)
{
   if (a > b)
      return a;
   return b;
}

int main (int argc, char* argv[])
{
   if (argc!=2) {
      printf("Usage: %s <input file>",argv[0]);
      return 1;
   }
   
   FILE *f;
   f = fopen(argv[1], "rb");
   int ch;
   int grid[21][21] = {0};
   unsigned short row = 1; 
   unsigned short col = 1;
   
   int tmp = 0;
   unsigned char first = 0;
   if (f != NULL) {
      while ( ch != EOF ) {
         ch = fgetc(f);
         if (ch == EOF) {
            break;
         } else if (ch == ' ' || ch == '\r') {
            continue;
         } else if (ch == '\n') {
            row++;
            col = 1;
            continue;
         } else {
            if (first == 1) {
               first = 0;
               grid[row][col] = (tmp * 10);
               if ((ch - '0') != 0)
                  grid[row][col] += (ch - '0');
               col++;
            } else {
               tmp = (ch - '0');
               first = 1;
            }
         }
      }
      if (fclose(f) != 0)
         return 1;
   }
   
   int rowmax = 0;
   int colmax = 0;
   int ldiagmax = 0;
   int rdiagmax = 0;
   int colflag = 0;
   
   unsigned short i,j;
   for (i=1;i<21;i++) {
      if (i>3) colflag = 1;
      else if (colflag == 1) colflag = 0;
      
      for (j=1;j<21;j++) {
         if (colflag == 1)
            colmax = max_si(grid[i][j]   * grid[i-1][j] 
                          * grid[i-2][j] * grid[i-3][j], colmax);
         if (j>3) {
            rowmax = max_si(grid[i][j]   * grid[i][j-1] 
                          * grid[i][j-2] * grid[i][j-3], rowmax);
            
            if (colflag == 1) {
               rdiagmax = max_si(grid[i][j]     * grid[i-1][j-1] 
                               * grid[i-2][j-2] * grid[i-3][j-3], rdiagmax);
               ldiagmax = max_si(grid[i][j-3]   * grid[i-1][j-2] 
                               * grid[i-2][j-1] * grid[i-3][j], ldiagmax);
            }
         }
      }
   }
   printf("%d\n", max_si(rowmax, max_si(colmax, max_si(rdiagmax, ldiagmax))));
   return 0;
}