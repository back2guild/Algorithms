#include "list.h"

struct Element {
  unsigned long long a;
  struct Element *next;
  struct Element *previous;
};

struct RootElement {
  unsigned long long size;
  struct Element *front;
  struct Element *rear;
  struct Element *current;
};

root_element_t* create_linklist()
{
    root_element_t *root = (root_element_t*) malloc(sizeof(root_element_t));
    if(root)
    {
        root->size = 0;
        root->front = NULL;
        root->rear = NULL;
        root->current = NULL;
    }
    else {
      printf("Error:MemoryOverflow - Linklist creation failed\n");
    }
    return root;
}

unsigned long long get_list_size(root_element_t* root)
{
  if(root != NULL)
  {
    return root->size;
  }
  else
  {
    return NULL_LIST_SIZE;
  }
}

bool is_empty(root_element_t* root)
{
  bool result = true;
  if(root != NULL)
  {
    result = ((root->size != 0) || (root->front != NULL) || (root->rear != NULL) || (root->current != NULL))?false:true;
  }
  return result;
}

bool add_at_front(root_element_t *root, element_t *node)
{
  bool success = false;
  if(root != NULL && node != NULL)
  {
    node->next = root->front;
    if(root->front != NULL)
    {
      root->front->previous = node;
      //root->rear = root->front;
    }
    else
    {
      root->rear = node;
    }
    root->current = node;
    node->previous = NULL;
    root -> front = node;
    root->size += 1;
    success = true;
  }
  return success;
}

void display(root_element_t* root)
{
  if(!is_empty(root))
  {
    printf("\n------ display start ------\n");
    element_t *temp = root->front;
    while(temp != NULL)
    {
      printf("{\"element\": %p, \"data\" : %llu, \"previous\" : %p, \"next\" : %p}\n", temp, temp->a, temp->previous, temp->next);
      temp = temp->next;
    }
    printf("------ display end ------\n");
  }
}

void droot(root_element_t *root)
{
  printf("\nroot {\"size\" = %llu, \"front\" = %p, \"rear\" = %p, \"current\" = %p}\n\n", root->size, root->front, root->rear, root->current);
}

element_t* create_element(unsigned long long data)
{
  element_t *e = (element_t*) malloc (sizeof(element_t));
  if(e)
  {
    e->a = data;
    e->next = NULL;
    e->previous = NULL;
  }
  else
  {
    printf("Error : MemoryOverflow - Failed to create link list element node\n");
  }
  return e;
}

void clean(root_element_t *root)
{
  if(root != NULL && !is_empty(root))
  {
    element_t *temp = NULL;
    while(root->front != NULL)
    {
      temp = root->front;
      root->front = temp->next;
      free(temp);
    }
    root->size = 0;
    free(root);
    root = NULL;
  }
}

bool add_at_rear(root_element_t *root, element_t *node) 
{
  bool status = false;
  if(root != NULL && node != NULL)
  {
    if(is_empty(root))
    {
      root->front = node;
      root->current = node;
    }
    else
    {
      node->previous = root->rear;
      root->rear->next = node;
    }
    root->rear = node;
    root->size += 1;
    status = true;
  }
  return status;
}