#include <stdio.h>
extern unsigned int _test (unsigned int, unsigned int);
int main(void)
{
   printf("%d\n", _test (85,5)); /* you are calling div here, not _test */
   return 0;
}
