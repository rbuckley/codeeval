#include <stdio.h>
#include <string.h>

#define LINE_SIZE 1024
int main (int argc, char **argv)
{
   FILE *f;
   char line[LINE_SIZE], *p;
   int line_size, word_size = 0;

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
      if (p = strchr(line, '\n'))
      {
         *p = '\0';
      }

      // Skip empty lines
      if (line[0] == '\0')
      {
         continue;
      }

      line_size = strlen(line);
      p = &line[line_size];

      while (line_size >= 0)
      {
         if (*p == ' ')
         {
            *(p) = '\0';
            printf("%s ", p+1);
         }
         else if (line_size == 0)
         {
            printf("%s\n", p);
         }
         else if (*p == '\r')
         {
            *(p) = '\0';
            printf("%s", p+1);
         }

         p--;
         line_size--;
      }
   }

   // Paranoid check
   if (ferror(f))
   {
      perror("I/O Error");
   }

   return 0;
}
