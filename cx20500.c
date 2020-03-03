#include <stdio.h>
int any(char s1[], char s2[]);

int main()
{
    printf("%d/n", any("ahjss", "abc"));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s2[i] != '\0'; i++ ) {
        for (j = 0; s1[j] != '\0'; j++) {
            if (s1[j] == s2[i]) {
                return j;
            }
        }
    }
    return -1;
}
