#include "sds.h"
#include <stdio.h>

int main()
{
    sds foo = sdsnew("Hello world redis.");

    printf("%zu\n",sdslen(foo));    

    sdsfree(foo);

    return 0;
}
