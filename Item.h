typedef struct list_node{
    struct list_node *prev;
    struct list_node *next;
} list_node_t;

typedef struct int_item {
    list_node_t node;
    int value;
} int_item_t;