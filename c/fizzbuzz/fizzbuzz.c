#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024
#define FIZZ "F"
#define BUZZ "B"
#define FIZZ_BUZZ FIZZ BUZZ

int main (int argc, char **argv)
{
   FILE *f;
   char line[LINE_SIZE], *p;
   int A, B, N, i;
   char fb = 0;

   // Open file passed as argument
   if (argc < 2 || !(f = fopen(argv[1], "r")))
   {
      fprintf(stderr, "Unable to open file argument\n");
      return 1;
   }

   // Read lines from file
   while (fgets(line, LINE_SIZE, f))
   {
      // You may want to remove the trailing '\n'
      //if ((p = strchr(line, '\n')))
      {
       //  *p = '\0';
      }

      // Skip empty lines
      if (line[0] == '\0')
      {
         continue;
      }

      sscanf(line, "%d %d %d", &A, &B, &N);
      // Do something with the line

      for (i = 1; i <= N; i++)
      {
         fb = 0;
         if (i % A == 0)
         {
            fb = 1;
            printf("%s", FIZZ);
         }
         if (i % B == 0)
         {
            fb = 1;
            printf("%s", BUZZ);
         }
         if (!fb)
         {
            printf("%d", i);
         }
         if (i != N)
         {
            printf(" ");
         }
      }
      printf("\n");
   }

   // Paranoid check
   if (ferror(f))
   {
      perror("I/O Error");
   }

   return 0;
}
