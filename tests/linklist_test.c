#include <criterion/criterion.h>
#include "../src/linklist.h"

Test(LinkList, CreateLinkList)
{
    lhead_t* head = createLinkList();
    cr_expect(head != NULL && getSize(head) == 0 && getHead(head) == NULL, "Head must not be NULL");
}