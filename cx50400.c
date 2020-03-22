#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main()
{
    printf("%d\n", strend("test", "end"));
    printf("%d", strend("testend", "end"));
}

int strend(char *s, char *t)
{
    s += (strlen(s) - strlen(t));
    while(*s++ == *t++) {
        if (*s == '\0')
            return 1;
    }
    return 0;
}