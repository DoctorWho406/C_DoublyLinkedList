#include <stddef.h>
#include "Item.h"

list_node_t *list_get_tail(list_node_t **head) {
    list_node_t *current_node = *head;
    if(!current_node) {
        return NULL;
    }
    while (current_node->next) {
        current_node = current_node->next;
    }
    return current_node;
}

list_node_t *list_append(list_node_t **head, list_node_t *item) {
    list_node_t *tail = list_get_tail(head);
    if (!tail) {
        *head = item;
    } else {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}

list_node_t *list_pop(list_node_t **head) {
    list_node_t *current_head = *head;
    if (!current_head) {
        return NULL;
    }
    *head = (*head)->next;
    (*head)->prev = NULL;
    current_head->next = NULL;
    return current_head;
}

list_node_t *list_remove(list_node_t **head, list_node_t *item) {
    list_node_t *current_node = *head;
    while(current_node->next != item) {
        current_node = current_node->next;
    }
    if(!current_node) { // scroll all and not find item
        return NULL;
    }
    list_node_t *removed = current_node->next;
    current_node->next = current_node->next->next;
    current_node->next->prev = current_node;    
    removed->next = NULL;
    removed->prev = NULL;
    return removed;
}


list_node_t *list_reverse(list_node_t **head) {
    list_node_t *curr_node = *head;
    list_node_t *prev_node = NULL;

    while(curr_node) {
        prev_node = curr_node->prev;
        curr_node->prev = curr_node->next;
        curr_node->next = prev_node;
        curr_node = curr_node->prev;
    }

    return prev_node->prev;
}

list_node_t *list_insert_after(list_node_t **head, list_node_t *item, list_node_t *after) {
    list_node_t *curr_node = *head;
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

list_node_t *list_insert_before(list_node_t **head, list_node_t *item, list_node_t *before) {
    list_node_t *curr_node = *head;
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