#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024
int main (int argc, char **argv)
{
   FILE *f;
   char line[LINE_SIZE], *p;
   int i;
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
      if ((p = strchr(line, '\n')))
      {
         *p = '\0';
      }

      // Skip empty lines
      if (line[0] == '\0')
      {
         continue;
      }

      i = 0;
      while(line[i] != '\0')
      {
         if (line[i] >= 'A' && line[i] <= 'Z')
         {

            line[i] += 32;
         }
         i++;
      }
      // Do something with the line
      printf("%s\n", line);
   }

   // Paranoid check
   if (ferror(f))
   {
      perror("I/O Error");
   }

   return 0;
}
