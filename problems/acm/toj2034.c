#include <stdio.h>
int main(int argc, char *argv[])
{
    int n, i, rlt;
    while(scanf("%d", &n) != EOF)
    {
        rlt = 1;
        for(i = 2; i <= n; i++)
        {
            rlt *= i;
            while(rlt%10 == 0)
            {
                rlt /= 10;
            }
            if(rlt > 100000)
            {
                rlt %= 100000;
            }
        }
        printf("%5d -> %d\n", n, rlt%10);
    }
    return 0;
}
