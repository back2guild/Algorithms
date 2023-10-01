#include "../src/tree.h"
#include "../src/comparator.h"

thead_t *tree = NULL;

void setup()
{
    printf("starting tree test setup\n");
    *tree = createTree(compareAsInt);
    printf("finishing tree test setup\n");
}

void teardown()
{
    printf("starting tree test teardown\n");
    destroyTree(tree);
    printf("finishing tree test teardown\n");
}

void test_create_tree(.init=setup, .fini=teardown) {
    assert(NULL != tree && isTreeEmpty(tree) == true);
}

int main(int argc, char const *argv[]) {
    test_create_tree();
    return 0;
}
