#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main(void)
{
    LinkedList* list = malloc(sizeof(LinkedList));
    list->_head = NULL;
    list->_tail = NULL;
    append(list, "Hello");
    append(list, "World");
    append(list, "Test");

    if (find(list, "Test"))
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found\n");
    }

    append(list, "Data");

    delete(list, "Test");

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