#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int htoi(char string[]);

int main() {
    printf("%d\n", htoi("0x1f"));
    printf("%d\n", htoi("0x1F"));
    printf("%d\n", htoi("1F"));
    printf("%d\n", htoi("20"));
    printf("%d\n", htoi("2F"));
    return 0;
}

int htoi(char s[]) {
    int rst = 0;
    int i;

    i = s[0] == '0' && (s[1] == 'x' || s[1] == 'X') ? 2: 0;

    while(s[i] != '\0') {
        char d = 0;
        if (isdigit(s[i])) {
            d = s[i] - '0';
        } else if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f') {
            d = tolower(s[i]) - 'a' + 10;
        }
        rst = rst * 16 + d;
        i++;
    }

    return rst;
}
