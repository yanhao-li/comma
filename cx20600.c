#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
int main()
{
    // 12 => 1100
    // 57 => 0011 1001
    // 0100
    printf("%u\n", setbits((unsigned)12, 3, 2, (unsigned)57));
    // printf("%u\n", getbits((unsigned)100, 4, 3));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return ((~(~0 << n) & y) << (p+1-n)) | ~(0 << (p-n));
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}
