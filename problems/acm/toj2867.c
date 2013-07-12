#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
struct job
{
    int start, end;
};
int cmp(const void *arg1, const void *arg2)
{
    struct job* left = (struct job *)arg1;
    struct job*  right = (struct job *)arg2;
    if(left->end < right->end)
    {
        return -1;
    }
    else if(left->end > right->end)
    {
        return 1;
    }
    else
    {
        return left->start - right->start;
    }
}
int main(int argc, char *argv[])
{
    int num, count;
    int i;
    struct job money[MAX];
    while(scanf("%d", &num) != EOF  &&  num)
    {
        for(i = 0; i < num; i++)
        {
            scanf("%d%d", &money[i].start, &money[i].end);
            money[i].end  += money[i].start;
        }
        qsort(money, num, sizeof(struct job), cmp);
        struct job *current;
        current = &money[0];
        count = 1;
        for(i = 1; i < num; i++)
        {
            if(money[i].start < current->end || money[i].end < current->end)
            {
                continue;
            }
            current = &money[i];
            count++;
        }
        printf("%d\n", count);

    }
    return 0;
}
