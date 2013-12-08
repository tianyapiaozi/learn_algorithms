#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int base;
    long long num, divide;
    char str[100], *p;
    while(scanf("%d", &base)  && base)
    {
        scanf("%s", str);
        num = strtoll(str, NULL, base);
        divide = 0;
        for(p = str; *p; p++)
        {
            divide  += *p-'0';
        }
        if(num % divide)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
    return 0;
}
