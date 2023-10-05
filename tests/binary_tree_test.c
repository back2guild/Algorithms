#include "../src/tree.h"
#include "../src/comparator.h"
#include <criterion/criterion.h>

thead_t *tree = NULL;

void setup()
{
    printf("starting tree test setup\n");
    tree = createTree(compareAsInt);
    printf("finishing tree test setup\n");
}

void teardown()
{
    printf("starting tree test teardown\n");
    destroyTree(tree);
    printf("finishing tree test teardown\n");
}

Test(BinaryTree, CreateTree, .init=setup, .fini=teardown) {
    assert(NULL != tree && isTreeEmpty(tree) == true);
}