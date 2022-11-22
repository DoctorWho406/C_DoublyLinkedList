#include <stddef.h>
#include "Item.h"

struct list_node *list_get_tail(struct list_node **head) {
    struct list_node *current_node = *head;
    if(!current_node) {
        return NULL;
    }
    while (current_node->next) {
        current_node = current_node->next;
    }
    return current_node;
}

struct list_node *list_append(struct list_node **head, struct list_node *item) {
    struct list_node *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}

struct list_node *list_pop(struct list_node **head) {
    struct list_node *current_head = *head;
    if (!current_head) {
        return NULL;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    current_head->next = NULL;
    return current_head;
}

struct list_node *list_remove(struct list_node **head, struct list_node *item) {
    struct list_node *current_node = *head;
    while(current_node->next != item) {
        current_node = current_node->next;
    }
    if(!current_node) { // scroll all and not find item
        return NULL;
    }
    struct list_node *removed = current_node->next;
    current_node->next = current_node->next->next;
    current_node->next->prev = current_node;    
    removed->next = NULL;
    removed->prev = NULL;
    return removed;
}


struct list_node *list_reverse(struct list_node **head) {
    struct list_node *curr_node = *head;
    struct list_node *prev_node = NULL;

    while(curr_node) {
        prev_node = curr_node->prev;
        curr_node->prev = curr_node->next;
        curr_node->next = prev_node;
        curr_node = curr_node->prev;
    }

    return prev_node->prev;
}

struct list_node *list_insert_after(struct list_node **head, struct list_node *item, struct list_node *after) {
    struct list_node *curr_node = *head;
    while (curr_node && curr_node != after) {
        curr_node = curr_node->next;
    }
    if(!curr_node) {
        return NULL;
    }
    item->next = curr_node->next;
    if(item->next) {
        item->next->prev = item;
    }
    item->prev = curr_node;
    curr_node->next = item;
    return item;
}

struct list_node *list_insert_before(struct list_node **head, struct list_node *item, struct list_node *before) {
    struct list_node *curr_node = *head;
    while (curr_node && curr_node != before) {
        curr_node = curr_node->next;
    }
    if(!curr_node) {
        return NULL;
    }
    item->prev = curr_node->prev;
    if(item->prev) {
        item->prev->next = item;
    }
    item->next = curr_node;
    curr_node->prev = item;
    return item;
}