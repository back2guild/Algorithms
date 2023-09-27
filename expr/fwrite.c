#include <stdio.h>
#include <curses.h>

int main(int argc, char **argv)
{
    int c = 0;
    while ((c = getch()) != 'z')
    {
        fputc(c, stdout);
    }
    return 0;
}