#include "../src/reader.h"

void test_read_file()
{
    const unsigned int BUFFER_SIZE = 10;
    char *buffer = NULL;
    char *file_content = read_file(__FILE__,buffer, BUFFER_SIZE);
    printf("%s\n", file_content);
    assert (file_content != NULL);
    free(buffer);
}

int main(int argc, char const *argv[])
{
    if(argc > 0 && argv[1] != NULL) {
        test_read_file();
    }
    return 0;
}
