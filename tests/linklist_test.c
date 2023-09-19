#include <signal.h>
#include <criterion/criterion.h>
#include "../src/linklist.h"

lhead_t *linkList = NULL;
#define TEST_LIST_SIZE 10

void setup(void)
{
    printf("Starting test setup\n");
    if(!linkList)
    {
        linkList = createLinkList();
        if(linkList)
        {
            printf("Test setup successfully created linklist\n");
        }
        else
        {
            printf("Setup not required as linklist is available to use\n");
        }
    }
    printf("Finished test setup\n");
}

void teardown(void)
{
    printf("Starting test teardown\n");
    if(linkList)
    {
        destroyLinkList(linkList);
        printf("Linklist released\n");
    }
    printf("Finished test teardown\n");
}

Test(LinkList, CreateLinkList)
{
    lhead_t* head = createLinkList();
    cr_expect(head != NULL && getSize(head) == 0 && getHead(head) == NULL, "Head must not be NULL");
}

Test(LinkList, TestSizeAtCreation, .init=setup, .fini = teardown)
{
    cr_expect(getSize(linkList) == 0);
}

Test(LinkList, EmptyListTest, .signal=SIGABRT)
{
    cr_assert(isListEmpty(linkList) == true, "Fail is expected as NULL linklist is passed");
}

Test(LinkList, AddToLinkList, .init=setup, .fini = teardown) {
    for (int i = 0; i < TEST_LIST_SIZE; i++)
    {
        cr_expect(addLinkListNode(linkList, createLinkListNode(&i)) == true, "Must be successful to add node");
    }
       
}