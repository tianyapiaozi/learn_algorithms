#include <stdio.h>
#include <stdlib.h>
int cmp(const void *arg1, const void *arg2)
{
    const int *p1 = (const int * )arg1, *p2 = (const int *)arg2;
    if(*p1 != *p2)
    {
        return *p1 - *p2;
    }
    return *(p1+1) - *(p2+1);
}
int main(int argc, char *argv[])
{
    int t, n, tables[201][2], i, j, min, cur, tmp;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &tables[i][0], &tables[i][1]);
            tables[i][0] = (tables[i][0]+1)/2;
            tables[i][1] = (tables[i][1]+1)/2;
            if(tables[i][0] > tables[i][1])
            {
                tmp = tables[i][0];
                tables[i][0] = tables[i][1];
                tables[i][1] = tmp;
            }
        }
        qsort(tables, n, 2*sizeof(int), cmp);
        min = 0;
        for(i = 0; i < n; i++)
        {
            if(!tables[i][0])
                continue;
            cur = i;
            for(j = i+1; j < n; j++)
            {
                if(tables[j][0]  > tables[cur][1])
                {
                    tables[cur][0] = tables[cur][1] = 0;
                    cur = j;
                }
            }
            tables[cur][0] = tables[cur][1] = 0;
            min  += 10;
        }
        printf("%d\n", min);
    }
    return 0;
}
