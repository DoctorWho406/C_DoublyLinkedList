#include <stddef.h>
#include "Item.h"

list_node_t *list_get_tail(list_node_t **head);

list_node_t *list_append(list_node_t **head, list_node_t *item);

list_node_t *list_pop(list_node_t **head);

int_item_t *int_item_new(const int value);

list_node_t *list_remove(list_node_t **head, list_node_t *item);

list_node_t *list_reverse(list_node_t **head);

list_node_t *list_insert_after(list_node_t **head, list_node_t *item, list_node_t *after);

list_node_t *list_insert_before(list_node_t **head, list_node_t *item, list_node_t *before);