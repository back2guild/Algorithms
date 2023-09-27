#include "../src/tree.h"


void test_create_tree() {
    head_t *tree = createBST(NULL, NULL);
    assert(NULL != tree && isEmpty(tree) == true);
}

int main(int argc, char const *argv[]) {
    test_create_tree();
    return 0;
}
