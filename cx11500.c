#include <stdio.h>

int ftoc(int f);

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = ftoc(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

int ftoc(int f)
{
    return 5 * (f-32) / 9;
}
