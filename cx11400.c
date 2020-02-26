#include <stdio.h>

int main() {
    int c, i, j;
    char nchar[26];

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            nchar[c - 'a']++;
        }
    }

    for (i = 0; i < 26; i++) {
        printf("%c| ", 'a' + i);
        for (j = 0; j < nchar[i]; j++) {
            putchar('*');
        }
        putchar('\n');

    }

    return 0;
}
