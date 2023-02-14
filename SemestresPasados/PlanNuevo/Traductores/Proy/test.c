#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int heapsize;
char *filter_string;
FILE *input_file, *output_file;

void display_usage(char *name)
{
   printf("usage: %s [-i input filename] [-o output filename] [-h heapsize, default 512]\n", name);
}

int process_args(int argc, char **argv)
{
   int ch;

   // Deal with the command line arguments here
   // return 1 on success, 0 on failure
   // (failure meaning malformed parameters or anything)

   heapsize = 512;
   input_file = stdin;
   output_file = stdout;

   while ((ch = getopt(argc, argv, "i:o:h:")) != -1)
   { // look at all the args + -heap
      // getopt returns -1 once it's finished
      if (ch == '?')
         return 0;

      switch (ch)
      {
      case 'i':
         input_file = fopen(optarg, "r");
         if (!input_file)
         {
            printf("Could not open input file \"%s\"\n", optarg);
            return 0;
         }
         break;
      case 'o':
         output_file = fopen(optarg, "w");
         if (!output_file)
         {
            printf("Could not open output file \"%s\"\n", optarg);
            return 0;
         }
         break;
      case 'h':
         heapsize = atoi(optarg);
         break;
      }
   }

   return 1;
}

// Heres the first version:
int main(int argc, char **argv)
{
   int ch;
   if (!process_args(argc, argv))
   {
      display_usage(argv[0]); // ammendment, argv[0] is the program name
                              // we shall display this in usage
      return EXIT_FAILURE;
   }

   filter_string = ".,+-<>[]";
   fputs("#include <stdio.h>\n", output_file);
   fputs("#include <stdlib.h>\n", output_file);
   fprintf(output_file, "static int heap[%d];\n", heapsize);
   fprintf(output_file, "int main(void) {int * p = heap+%d;", heapsize / 2);
   while ((ch = fgetc(input_file)) != EOF)
      switch (ch)
      {
      case '>':
         break;
      case '<':
         fputs("--p;", output_file);
         break;
      case '+':
         fputs("++*p;", output_file);
         break;
      case '-':
         fputs("--*p;", output_file);
         break;
      case '.':
         fputs("putchar(*p);", output_file);
         break;
      case ',':
         fputs("*p = getchar();", output_file);
         break;
      case '[':
         fputs("while (*p) {", output_file);
         break;
      case ']':
         fputs("}", output_file);
         break;
      }
   fputs("return EXIT_SUCCESS;}\n", output_file);
   fflush(output_file);
   fclose(output_file);

   return EXIT_SUCCESS;
}

// it seesm to work well but there's some improvements possible.
// Example outout: int main(void) {int * p = heap+256;putchar(*p);++p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;++p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;while (*p) {--p;++*p;++*p;++*p;++*p;++*p;++p;--*p;}++*p;++*p;++*p;++*p;++*p;++*p;++*p;++p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;++*p;while (*p) {--p;++....
// all these ++p could be turned into a single p+=50;
// similarly with -- ++* and --*
// that'll be next!