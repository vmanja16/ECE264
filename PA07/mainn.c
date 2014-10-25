#include "answer07.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <libgen.h>
#include <string.h>

int main (int argc, char * * argv)

{

Image * ThisImage = NULL;

ThisImage = Image_load(argv[1]);



if (ThisImage != NULL){ Image_free(ThisImage);}


return 0;
}
