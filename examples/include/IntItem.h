#include "DoublyLinkedList.h"

typedef struct int_item {
    list_node_t node;
    int value;
} int_item_t;

int_item_t *int_item_new(const int value);