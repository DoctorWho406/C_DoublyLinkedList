#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"
#include "IntItem.h"

#define to_list (list_node_t **)
#define to_node (list_node_t *)
#define to_int_item (int_item_t *)

int main() {
    int_item_t *my_doublylinked_list = NULL;
    list_append(to_list & my_doublylinked_list, to_node int_item_new(8));
    list_append(to_list & my_doublylinked_list, to_node int_item_new(3));
    list_append(to_list & my_doublylinked_list, to_node int_item_new(1));
    list_append(to_list & my_doublylinked_list, to_node int_item_new(1));
    printf("==========LIST==========\n");
    int_item_t *int_item = my_doublylinked_list;
    while (int_item) {
        if (int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if (int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }

    int_item_t *item_to_search = int_item_new(3);
    int_item_t *removed_item = to_int_item list_remove(to_list & my_doublylinked_list, to_node item_to_search, sizeof(int));
    printf("==========LIST AFTER REMOVE==========\n");
    int_item = my_doublylinked_list;
    while (int_item) {
        if (int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if (int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }
    // Free item
    free(item_to_search);


    printf("==========REVERSED LIST==========\n");
    list_reverse(to_list & my_doublylinked_list);
    int_item = my_doublylinked_list;
    while (int_item) {
        if (int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if (int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }

    int_item_t *before = int_item_new(8);
    list_insert_before(to_list & my_doublylinked_list, to_node removed_item, to_node before, sizeof(int));
    printf("==========INSERT BEFORE==========\n");
    int_item = my_doublylinked_list;
    while (int_item) {
        if (int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if (int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }
    free(before);

    list_insert_after(to_list & my_doublylinked_list, to_node int_item_new(5), to_node removed_item, sizeof(int));
    printf("==========INSERT AFTER==========\n");
    int_item = my_doublylinked_list;
    while (int_item) {
        if (int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if (int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }
    free(removed_item);

    list_randomize(to_list & my_doublylinked_list);
    printf("==========RANDOMIZE==========\n");
    int_item = my_doublylinked_list;
    while (int_item) {
        if (int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if (int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }


    // Free list
    while (my_doublylinked_list) {
        removed_item = to_int_item list_pop(to_list & my_doublylinked_list);
        free(removed_item);
    }

    return 0;
}