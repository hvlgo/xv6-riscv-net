#ifndef LIST
#define LIST

struct list_head {
    struct list_head* next;
    struct list_head* prev;
};

static inline void list_init(struct list_head *head)
{
    head->prev = head->next = head;
}

static inline void list_add(struct list_head *newitem, struct list_head *head)
{
    head->next->prev = newitem;
    newitem->next = head->next;
    newitem->prev = head;
    head->next = newitem;
}

static inline void list_add_tail(struct list_head *newitem, struct list_head *head)
{
    head->prev->next = newitem;
    newitem->prev = head->prev;
    newitem->next = head;
    head->prev = newitem;
}

static inline void list_del(struct list_head *elem)
{
    struct list_head *prev = elem->prev;
    struct list_head *next = elem->next;

    prev->next = next;
    next->prev = prev;
}


#endif