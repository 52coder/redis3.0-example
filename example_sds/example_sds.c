#include "sds.h"
#include <stdio.h>

int main()
{
    sds foo = sdsnew("Hello world redis.");
    /*打印sds->len sds->free*/
    printf("%zu\n",sdslen(foo));  
    printf("%zu\n",sdsavail(foo));

    sds foo_dup = sdsdup(foo);
    printf("%zu\n",sdslen(foo_dup));
    printf("%zu\n",sdsavail(foo_dup)); 

    if(0 == sdscmp(foo,foo_dup))
    {
        printf("foo foo_dup exactly the same binary string.\n");
    }

    /*返回给定sds分配的内存字节数*/
    /*sdslen(foo) + 8 + 1*/
    printf("%zu\n",sdsAllocSize(foo));

    printf("%zu\n",sdslen(foo));  
    printf("%zu\n",sdsavail(foo));

    sdsfree(foo);
    sdsfree(foo_dup);


    return 0;
}
