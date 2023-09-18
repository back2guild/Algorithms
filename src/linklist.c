#include "linklist.h"

struct LinkListNode {
    void *data;
    struct LinkListNode *next;
};

struct LinkListHead {
    size_t count;
    struct LinkListNode *head;
};

lhead_t* createLinkList(void)
{
    lhead_t *head = (lhead_t*) malloc(sizeof(lhead_t));
    if(!head)
    {
        perror("Failed to create link list");
        return head;
    }
    head->count = 0;
    head->head = NULL;
    return head;
}