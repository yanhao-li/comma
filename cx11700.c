#include <stdio.h> 
#define MAXLINE 1000

int my_getline(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE];

    while((len = my_getline(line, MAXLINE)) > 0) {
        if (len > 8) {
            printf("%s", line);
        }
    }

    return 0;
}

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
