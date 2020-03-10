#include <stdio.h>
#define MAXLENGTH 1000

char pattern[] = "test";

int mygetline(char s[], int lim);
int strindex(char s[], char t[]);

int main()
{
    char line[MAXLENGTH];

    while(mygetline(line, MAXLENGTH) > 0) {
        printf("%d", strindex(line, pattern));
    }

    return 0;
}

/* getline: get line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;
    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// returns the position of the rightmost occurrence of t in s, or -1 if there is none.
int strindex(char s[], char t[])
{
    int i, j, k, tmp;

    tmp = -1;
    for(i = 0; s[i] != '\0'; i++) {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > tmp && t[k] == '\0') {
            tmp = i;
        }
    }

    return tmp;
}
