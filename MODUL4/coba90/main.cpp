#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
   int myNumber[] = {1, 2, 3, 4, 5};
   myNumber[1]=4;
   myNumber[2]=3;
   for(int i=0;i<5;i++)
   {
       printf("%d ", myNumber[i]);
   }
   return 0;
}
