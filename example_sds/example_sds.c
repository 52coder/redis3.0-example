#include "sds.h"
#include <stdio.h>

int main()
{
    sds foo = sdsnew("Hello world redis.");
    /*打印sds->len sds->free*/
    printf("%zu %zu\n",sdslen(foo),sdsavail(foo));  

    sds foo_dup = sdsdup(foo);
    printf("%zu %zu\n",sdslen(foo_dup),sdsavail(foo_dup)); 

    if(0 == sdscmp(foo,foo_dup))
    {
        printf("foo foo_dup exactly the same binary string.\n");
    }

    /*返回给定sds分配的内存字节数*/
    /*sdslen(foo) + 8 + 1*/
    printf("%zu\n",sdsAllocSize(foo));

    /*将sds扩充至指定长度*/
    /*执行函数后sdslen增加10,由于redis内存分配策略：小于1m,newlen*=2因此free为28*/
    foo = sdsgrowzero(foo,sdslen(foo) + 10);
    printf("%zu %zu\n",sdslen(foo),sdsavail(foo));  
    printf("%zu\n",sdsAllocSize(foo));

    sdsfree(foo);
    sdsfree(foo_dup);

    return 0;
}
