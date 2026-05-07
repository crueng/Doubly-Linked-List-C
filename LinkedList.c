#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void append(LinkedList* list, char* data)
{
    if (list->_head == NULL) // Case: No Elements exist in List
    {
        Node* node = malloc(sizeof(Node));
        node->data = data;
        list->_head = node;
        list->_head->_next = list->_tail;
        list->_head->_prev = list->_tail;
        list->_tail = node;
        list->_tail->_next = list->_head;
        list->_tail->_prev = list->_head;
    }
    else if (list->_head == list->_tail) // Case: One Element exist in List
    {
        Node* node = malloc(sizeof(Node));
        list->_tail = list->_head;
        list->_head  = node;
        node->_prev = list->_tail;
        node->_next = list->_tail;
        node->data = data;
        return;
    }

    Node* node = malloc(sizeof(Node));
    Node* head = list->_head;
    head->_prev->_next = node;
    node->_prev = head->_prev;
    node->_next = head;
    head->_prev = node;
    node->data = head->data;
    head->data = data;
}

Node* find(LinkedList* list, char* data)
{
    Node* tail = list->_tail;
    Node* next = tail->_next;
    while (next != tail)
    {
        if (next->data == data)
        {
            return next;
        }
        next = next->_next;
    }
    return NULL;
}

void delete(LinkedList* list, char* data)
{
    Node* tail = list->_tail;
    Node* next = list->_tail->_next;;
    while (next != tail)
    {
        if (next->data == data)
        {
            next->_prev->_next = next->_next;
            next->_next->_prev = next->_prev;
            free(next);
            return;
        }
        next = next->_next;
    }
}

void printList(LinkedList* list)
{
    Node* tail = list->_tail;
    Node* next = list->_tail->_next;
    if (tail == NULL) return;

    printf(tail->data);
    while (next != tail)
    {
        printf("\n");
        printf(next->data);
        next = next->_next;
    }
}