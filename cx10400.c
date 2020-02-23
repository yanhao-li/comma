#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 150;
    step = 5;

    celsius = lower;
    printf("celsius\tfahr\n");
    while(celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%7.0f\t%3.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
