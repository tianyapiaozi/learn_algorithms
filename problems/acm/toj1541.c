#include <stdio.h>
#include <string.h>
#define MAX 100000
int main(int argc, char *argv[])
{
    char str[MAX];
    long mark[MAX];
    int len;
    int i;
    while(scanf("%s", str)  && str[0] != '0')
    {
        len = strlen(str);
        mark[0] = mark[1] = 1;
        for(i = 1; i < len ; i++)
        {
            if(str[i]  == '0')
            {
                mark[i+1] = mark[i-1];
            }
            else if(str[i-1]  == '0' || ((str[i-1]-'0')*10+str[i]-'0' > 26))
            {
                mark[i+1] = mark[i];
            }
            else
            {
                mark[i+1] = mark[i]+mark[i-1];
            }
        }
        printf("%ld\n", mark[len]);
    }
    return 0;
}
