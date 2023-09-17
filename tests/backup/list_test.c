#include "../src/list.h"

root_element_t* test_create_linklist() {
    root_element_t *root = create_linklist();
    assert(root != NULL);
    assert(get_list_size(root) == 0L);
    return root;
}

/**
    * ------ display start ------
    * {"element": 0x600002d11320, "data" : 10, "previous" : 0x0, "next" : 0x600002d11300}
    * {"element": 0x600002d11300, "data" : 9, "previous" : 0x600002d11320, "next" : 0x600002d112e0}
    * {"element": 0x600002d112e0, "data" : 8, "previous" : 0x600002d11300, "next" : 0x600002d112c0}
    * {"element": 0x600002d112c0, "data" : 7, "previous" : 0x600002d112e0, "next" : 0x600002d112a0}
    * {"element": 0x600002d112a0, "data" : 6, "previous" : 0x600002d112c0, "next" : 0x600002d11280}
    * {"element": 0x600002d11280, "data" : 5, "previous" : 0x600002d112a0, "next" : 0x600002d11260}
    * {"element": 0x600002d11260, "data" : 4, "previous" : 0x600002d11280, "next" : 0x600002d11240}
    * {"element": 0x600002d11240, "data" : 3, "previous" : 0x600002d11260, "next" : 0x600002d11220}
    * {"element": 0x600002d11220, "data" : 2, "previous" : 0x600002d11240, "next" : 0x600002d11200}
    * {"element": 0x600002d11200, "data" : 1, "previous" : 0x600002d11220, "next" : 0x0}
    * ------ display end ------
*/
void test_add_to_front(root_element_t *root)
{
    for(int i = 1; i<= 10; i++)
    {
        assert(add_at_front(root, create_element(i)));
    }
}

void test_add_to_rear(root_element_t *root)
{
    for(int i = 1; i<= 10; i++)
    {
        assert(add_at_rear(root, create_element(i)));
    }
}

void test_display(root_element_t *root)
{
    assert(root != NULL);
    display(root);
}

void test_clean(root_element_t *root)
{
    clean(root);
}

void test_droot(root_element_t *root)
{
    droot(root);
}

void test_front_add_usecase() {
    root_element_t *root = test_create_linklist();
    test_add_to_front(root);
    test_display(root);
    test_droot(root);
    test_clean(root);
    test_droot(root);    
    printf("\n\n-------------------------------\n\n");
    printf("\n\n-------------------------------\n\n");
}

void test_rear_add_usecase() {
    root_element_t *rr = test_create_linklist();
    test_add_to_rear(rr);
    test_display(rr);
    test_droot(rr);
    test_clean(rr);
    test_droot(rr);
}

int main()
{
    test_front_add_usecase();
    test_rear_add_usecase();
    return 0;
}
