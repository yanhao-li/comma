#include <stdio.h>
void mystrcat(char *s, char *t);

int main()
{
    char s[8192] = "test";
    char t[8192] = "cat";
    mystrcat(s, t);
    printf("%s", s);
    return 0;
}

void mystrcat(char *s, char *t)
{
    while(*s != '\0') {
        ++s;
    }

    while((*s = *t) != '\0') {
        ++s;
        ++t;
    }
}
