#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int t, num;
    char str[102];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", str);
        num = strtol(str, NULL, 2);
        printf("%o\n", num);
    }
    return 0;
}
