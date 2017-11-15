#include <stdio.h>
#include <string.h>

int main() {
    char *p1 = "123", *p2 = "ABC", str[50] = "xyz";
    strcat(str, p2);
    printf("%c", str[30]);
    printf("%s", str);
    return 0;
}
