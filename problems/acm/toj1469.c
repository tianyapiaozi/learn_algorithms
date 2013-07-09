#include <stdio.h>
#include <stdlib.h>
int cmp(const void *arg1, const void *arg2)
{
    const int *p1 = (const int *)arg1, *p2 = (const int *)arg2;
    if(*p1 != *p2)
    {
        return *p1-*p2;
    }
    return *(p1+1)-*(p2+1);
}
int main(int argc, char *argv[])
{
    int t, wood[5001][2], i, j, n, cur, min;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &wood[i][0], &wood[i][1]);
        }
        qsort(wood, n, 2*sizeof(int), cmp);
        min = 0;
        for(i = 0; i < n; i++)
        {
            if(wood[i][0] == 0)
            {
                continue;
            }
            cur = i;
            for(j = i+1; j < n; j++)
            {
                if(wood[j][0] >= wood[cur][0]  && wood[j][1]  >= wood[cur][1])
                {
                    wood[cur][0] = 0;
                    wood[cur][1] = 0;
                    cur = j;
                }
            }
            wood[cur][0] = 0;
            wood[cur][1] = 0;
            min++;
        }
        printf("%d\n", min);
    }
    return 0;
}

