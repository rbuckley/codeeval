#include <stdio.h>

int main (int argc, char **argv)
{
   int prime_sum = 2;
   int prime = 0, i = 3, j;
   int found_primes = 1;

   /** start at 3 since 2 is prime */
   while (found_primes < 1000)
   {
      /** can easily throw out even numbers */
      if (i % 2 != 0)
      {
         for (j = 3; j < i; j++)
         {
            if (i % j == 0)
            {
               break;
            }
         }
         /** if we modulo'd everything and didnt break its a prime */
         if (j == i)
         {
            prime_sum += i;
            found_primes++;
         }
      }
      i++;
   }

   printf("%d\n", prime_sum);
   return 0;
}
