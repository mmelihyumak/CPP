#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char *str = malloc(100);

    system("leaks a.out");
    return 0;
}