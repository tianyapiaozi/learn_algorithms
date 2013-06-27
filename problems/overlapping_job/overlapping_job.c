#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct job
{
    int start, end;
    char name[10];
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
    int num;
    struct job money[MAX]; // job is money -_)
    scanf("%d", &num);
    if(!num)
    {
        return 0;
    }
    int i;
    for(i = 0; i < num; i++)
    {
        scanf("%s%d%d", money[i].name, &money[i].start, &money[i].end);
    }
    qsort(money, num, sizeof(struct job), cmp);
    struct job *current, *next;
    current = &money[0];
    printf("%s ", current->name);
    for(i = 1; i < num; i++)
    {
        if(money[i].start < current->end || money[i].end < current->end)
        {
            continue;
        }
        current = &money[i];
        printf(" %s ", current->name);
    }
    printf("\n");
    return 0;
}
