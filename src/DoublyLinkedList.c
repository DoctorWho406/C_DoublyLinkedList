#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "DoublyLinkedList.h"

list_node_t *list_get_tail(list_node_t **head) {
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;
    while (current_node) {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
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
    *head = current_head->next;
    if ((*head)) {
        (*head)->prev = NULL;
    }
    current_head->next = NULL;
    return current_head;
}

list_node_t *list_remove(list_node_t **head, list_node_t *item, size_t size_of_value) {
    list_node_t *current_node = *head;

    while (current_node) {
        if (memcmp(current_node + 1, item + 1, size_of_value) == 0) {
            if (current_node->prev) {
                current_node->prev->next = current_node->next;
            }
            if (current_node->next) {
                current_node->next->prev = current_node->prev;
            }
            current_node->next = NULL;
            current_node->prev = NULL;
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}

void list_reverse(list_node_t **head) {
    list_node_t *current_node = *head;
    list_node_t *prev_node = NULL;

    while (current_node) {
        prev_node = current_node->prev;
        current_node->prev = current_node->next;
        current_node->next = prev_node;
        current_node = current_node->prev;
    }

    *head = prev_node->prev;
}

list_node_t *list_insert_after(list_node_t **head, list_node_t *item, list_node_t *after, size_t size_of_value) {
    list_node_t *current_node = *head;
    while (current_node) {
        if (memcmp(current_node + 1, after + 1, size_of_value) == 0) {
            item->next = current_node->next;
            item->prev = current_node;
            if (current_node->next) {
                current_node->next->prev = item;
            }
            current_node->next = item;

            return item;
        }
        current_node = current_node->next;
    }

    return NULL;
}

list_node_t *list_insert_before(list_node_t **head, list_node_t *item, list_node_t *before, size_t size_of_value) {
    list_node_t *current_node = *head;
    while (current_node) {
        if (memcmp(current_node + 1, before + 1, size_of_value) == 0) {
            item->next = current_node;
            item->prev = current_node->prev;
            if (current_node->prev) {
                current_node->prev->next = item;
            }
            current_node->prev = item;

            return item;
        }
        current_node = current_node->next;
    }

    return NULL;
}

void list_randomize(list_node_t **head) {
    list_node_t *current_node = *head;
    int list_count = 0;
    while (current_node) {
        list_count++;
        current_node = current_node->next;
    }

    srand(time(NULL));
    int random_index = rand() % list_count;
    int curr_index = 0;

    list_node_t *randomize_list = NULL;

    while (list_count) {
        curr_index = 0;
        current_node = *head;
        while (curr_index != random_index) {
            current_node = current_node->next;
            curr_index++;
        }

        if (current_node->prev) {
            current_node->prev->next = current_node->next;
        } else {
            (*head) = current_node->next;
        }
        if (current_node->next) {
            current_node->next->prev = current_node->prev;
        }
        list_append(&randomize_list, current_node);

        if (--list_count > 0) {
            if (random_index == 0 || random_index == list_count) {
                random_index = rand() % list_count;
            } else if (rand() % 2) {
                random_index = (rand() % (list_count - random_index)) + random_index;
            } else {
                random_index = rand() % random_index;
            }
        }
    }

    (*head) = randomize_list;
}