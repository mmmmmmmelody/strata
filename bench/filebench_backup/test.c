#include <stdio.h>
#include <stdlib.h>

int main () {
   printf("PATH : %s\n", getenv("LD_LIBRARY_PATH"));

   return(0);
}
