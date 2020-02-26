#include <stdio.h>

int main() {
    int c, nl, bk, tab;

    nl = bk = tab = 0;

    while((c = getchar()) != EOF) {
        if (c == '\n') {
            nl++;
        } else if (c == ' ') {
            bk++;
        } else if (c == '\t') {
            tab ++;
        }
    }

    printf("new lines: %d, blanks: %d, tabs: %d", nl, bk, tab);
}
