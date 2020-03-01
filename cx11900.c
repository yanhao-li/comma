#include <stdio.h>
#define MAXLINE 1000

int my_getline(char line[], int maxline);
void reverse(char s[]);

int main() {
    char line[MAXLINE];
    while(my_getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("reversed: %s", line);
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

void reverse(char s[]) {
    int i, j;
    char temp;

    for (j = 0; s[j] != '\0'; j++)
    {
    }

    j--;

    i = 0;
    while(i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
