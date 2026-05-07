#pragma once
#include <memory.h>

struct Node;
typedef struct Node Node;

struct Node {
    char* data;
    Node* _next;
    Node* _prev;
};

struct LinkedList;
typedef struct LinkedList LinkedList;

struct LinkedList {
    Node* _head;
    Node* _tail;
};

void append(LinkedList* list, char* data);
void find(LinkedList* list, char* data);
void delete(LinkedList* list, char* data);
void printList(LinkedList* list);