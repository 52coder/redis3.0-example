#include "adlist.h"
#include <stdio.h>
#include <stdlib.h> /* free */
#include <string.h> /* memcpy */

int main()
{
    list *msgbox;
    listIter *iter;
    listNode *node;
    
    unsigned int size = 32;
    char str[] = "Hello redis";
    char s[] = "Hello world";

    /* 创建新链表 */
    if ((msgbox = listCreate()) == NULL)
        return -1;
    
    /*设置链表释放函数*/
    listSetFreeMethod(msgbox,free);

    /*链表value内存来源于堆,释放链表时需要free函数释放value*/
    char *value = (char *)malloc(size * sizeof(char));
    memset(value, 0x0, size * sizeof(char));
    memcpy(value,str,sizeof(str));

    /*vale插入链表,头插法*/
    listAddNodeHead(msgbox,value);

    value = (char *)malloc(size * sizeof(char));
    memset(value, 0x0, size* sizeof(char));
    memcpy(value,s,sizeof(s));
    
    /*vale插入链表,尾插法*/
    listAddNodeTail(msgbox,value);

    /*打印链表长度*/
    printf("list msgbox contains:%zu element\n",listLength(msgbox));

    // 从头向尾迭代整个输入链表
    iter = listGetIterator(msgbox, AL_START_HEAD);
    unsigned int count = 0;
    while((node = listNext(iter)) != NULL) 
    {
        void *value;
        value = node->value;
        printf("%uz'th element is %s\n",count++,(char *)value);
    }

    // 释放迭代器
    listReleaseIterator(iter);

    /* 释放链表 */
    listRelease(msgbox);
    return 0;
}
