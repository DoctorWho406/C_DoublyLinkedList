struct list_node{
    struct list_node *prev;
    struct list_node *next;
};

struct int_item {
    struct list_node node;
    int value;
};