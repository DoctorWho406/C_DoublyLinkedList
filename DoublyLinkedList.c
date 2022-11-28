#include <stddef.h>
#include <stdio.h>
#include "Functions.h"

#define to_list (list_node_t **)
#define to_node (list_node_t *)
#define to_int_item (int_item_t *)

int main() {
    int_item_t *my_doublylinked_list = NULL;
    int_item_t *first_item = int_item_new(8);
    int_item_t *new_item = int_item_new(3);
    list_append(to_list&my_doublylinked_list, to_node first_item);
    list_append(to_list&my_doublylinked_list, to_node new_item);
    list_append(to_list&my_doublylinked_list, to_node int_item_new(1));
    list_append(to_list&my_doublylinked_list, to_node int_item_new(1));
    printf("==========LIST==========\n");
    int_item_t *int_item = my_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }

    list_remove(to_list&my_doublylinked_list, to_node new_item);
    printf("==========LIST AFTER REMOVE==========\n");
    int_item = my_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }

    printf("==========REVERSED LIST==========\n");
    int_item_t *my_reversed_doublylinked_list = to_int_item list_reverse(to_list&my_doublylinked_list);
    int_item = my_reversed_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }

    list_insert_before(to_list&my_reversed_doublylinked_list, to_node new_item, to_node first_item);
    printf("==========INSERT BEFORE==========\n");
    int_item = my_reversed_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }

    list_insert_after(to_list&my_reversed_doublylinked_list, to_node int_item_new(5), to_node new_item);
    printf("==========INSERT AFTER==========\n");
    int_item = my_reversed_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (to_int_item int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (to_int_item int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = to_int_item int_item->node.next;
    }

    return 0;
}