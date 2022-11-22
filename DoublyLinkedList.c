#include <stddef.h>
#include <stdio.h>
#include "Functions.h"

#define toList (struct list_node **)
#define toNode (struct list_node *)
#define toIntItem (struct int_item *)

int main() {
    struct int_item *my_doublylinked_list = NULL;
    struct int_item *first_item = int_item_new(8);
    struct int_item *new_item = int_item_new(3);
    list_append(toList&my_doublylinked_list, toNode first_item);
    list_append(toList&my_doublylinked_list, toNode new_item);
    list_append(toList&my_doublylinked_list, toNode int_item_new(1));
    list_append(toList&my_doublylinked_list, toNode int_item_new(1));
    printf("==========LIST==========\n");
    struct int_item *int_item = my_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (toIntItem int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (toIntItem int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = toIntItem int_item->node.next;
    }

    list_remove(toList&my_doublylinked_list, toNode new_item);
    printf("==========LIST AFTER REMOVE==========\n");
    int_item = my_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (toIntItem int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (toIntItem int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = toIntItem int_item->node.next;
    }

    printf("==========REVERSED LIST==========\n");
    struct int_item *my_reversed_doublylinked_list = toIntItem list_reverse(toList&my_doublylinked_list);
    int_item = my_reversed_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (toIntItem int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (toIntItem int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = toIntItem int_item->node.next;
    }

    list_insert_before(toList&my_reversed_doublylinked_list, toNode new_item, toNode first_item);
    printf("==========INSERT BEFORE==========\n");
    int_item = my_reversed_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (toIntItem int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (toIntItem int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = toIntItem int_item->node.next;
    }

    list_insert_after(toList&my_reversed_doublylinked_list, toNode int_item_new(5), toNode new_item);
    printf("==========INSERT AFTER==========\n");
    int_item = my_reversed_doublylinked_list;
    while (int_item) {
        if(int_item->node.prev) {
            printf("%d<-", (toIntItem int_item->node.prev)->value);
        } else {
            printf(" <-");
        }
        printf("%d", int_item->value);
        if(int_item->node.next) {
            printf("->%d\n", (toIntItem int_item->node.next)->value);
        } else {
            printf("-> \n");
        }
        int_item = toIntItem int_item->node.next;
    }

    return 0;
}