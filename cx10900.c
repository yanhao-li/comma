#include <stdio.h>

int main() {
    int c;
    int prevchar;
    while((c = getchar()) != EOF) {
        if (prevchar != ' ' || c != ' ') {
            putchar(c);
        }
        prevchar = c;
    } 
}
