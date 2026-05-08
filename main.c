#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

#define CALL(list, func, string) (*func)(list, string);

int main(void)
{
    LinkedList* list = malloc(sizeof(LinkedList));
    list->_head = NULL;
    list->_tail = NULL;
    CALL(list, append, "Hello")
    CALL(list, append, "World")
    CALL(list, append, "Test")

    if (find(list, "Test"))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    CALL(list, append, "Data")

    CALL(list, delete, "Test")

    if (find(list, "Test"))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }
    printList(list);
}