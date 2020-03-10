#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    printf("%d\n", bitcount(100));
}

int bitcount(unsigned x)
{
    int b = 0;

    while(x != 0) {
        x &= (x - 1);
        b++;
    }

    return b;
}
