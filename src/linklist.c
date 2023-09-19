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

size_t getSize(lhead_t* head) {
    return (NULL != head ? head->count : 0);
}

 lnode_t* getHead(lhead_t *head) {
    return (NULL != head ? head->head: NULL);
 }

 bool isListEmpty(lhead_t *head) {
    assert(NULL != head);
    return (head->count == 0 && head->head == NULL);
 }

 bool addLinkListNode(lhead_t *head, lnode_t *node) {
    assert(NULL != head);
    bool success = false;
    if(isListEmpty(head)) { //First node
        head->head = node;
    }
    else
    {
        lnode_t *temp = head->head;
        while(NULL != temp->next)
        {
            temp = temp->next;
        }
        temp->next = node;
    }
    head->count++;
    success = true;
    return success;
 }

 void destroyLinkList(lhead_t *head) {
    assert(NULL != head);
    if(isListEmpty(head))
    {
        free(head);
    }
    else
    {
        lnode_t *temp = head->head;
        while(NULL != temp->next)
        {
            lnode_t *t = temp->next;
            free(temp);
            temp = t;
        }
        free(temp);
        free(head);
    }
 }

 lnode_t* createLinkListNode(void *vp) {
    lnode_t *node = (lnode_t*) malloc(sizeof(lnode_t));
    assert(node != NULL);
    node->data = vp;
    node->next = NULL;
    return node;
 }
