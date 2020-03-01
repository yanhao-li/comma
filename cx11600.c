#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len, max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = my_getline(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0)
        printf("length: %d\n", max);
        printf("string: %s", longest);
    return 0;
}

// getline: read a line into s, return length
int my_getline(char s[], int lim)
{
    int c, i;
    i = 0;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' ; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i - 1;
}

// copy: copy 'from' into 'to', assume to is big enough
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}

