#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int n, i, k, j, alter, len, next, count;
    int array[201];
    char str[2][201];
    int repeat[201];
    while(scanf("%d", &n)  && n)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }
        for(i = 0; i < n; i++)
        {
            count = 1;
            next = array[i];
            while(next != i+1)
            {
                next = array[next-1];
                count++;
            }
            repeat[i] = count;
        }
        while(scanf("%d", &k)  && k)
        {
            getchar();
            gets(str[0]);
            len = strlen(str[0]);
            for(i = len; i < n; i++)
            {
                str[0][i] = ' ';
            }
            for(i = 0; i < n; i++)
            {
                next = i+1;
                for(j = 0; j < k%repeat[i]; j++)
                {
                    next = array[next-1];
                }
                str[1][next-1] = str[0][i];
            }
            str[1][n] = '\0';
            printf("%s\n", str[1]);
        }
        printf("\n");
    }
    return 0;
}
