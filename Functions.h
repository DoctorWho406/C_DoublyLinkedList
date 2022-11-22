#include <stddef.h>
#include "Item.h"

struct list_node *list_get_tail(struct list_node **head);

struct list_node *list_append(struct list_node **head, struct list_node *item);

struct list_node *list_pop(struct list_node **head);

struct int_item *int_item_new(const int value);

struct list_node *list_remove(struct list_node **head, struct list_node *item);

struct list_node *list_reverse(struct list_node **head);

struct list_node *list_insert_after(struct list_node **head, struct list_node *item, struct list_node *after);

struct list_node *list_insert_before(struct list_node **head, struct list_node *item, struct list_node *before);