#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

#define LINE_SIZE 1024
int main (int argc, char **argv)
{
   FILE *f;
   char line[LINE_SIZE], *p, *rest_of_line;
   double sort_next = 0;
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

      p = line;
      while(*p != '\0')
      {
         errno=0;
         printf("line to strtod: %s\n", p);
         sort_next = strtol(p, &rest_of_line, 10);

         if (errno == ERANGE && ((sort_next == LONG_MAX) || sort_next == LONG_MIN) || (errno != 0 && sort_next ==0))
         {
            perror("strtol");
            break;
         }
         printf("%f\n", sort_next);
         p = rest_of_line;
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
