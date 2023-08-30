#include "../src/common.h"


void test_bit_pattern() {
    bit_pattern(10);
    assert(1==1);
}

void test_get_sys_info() {
    get_sys_info();
    assert(1==1);
}

int main() {
    test_get_sys_info();
    return EXIT_SUCCESS;
}