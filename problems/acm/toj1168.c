#include <stdio.h>
#include <string.h>
typedef struct node
{
    int num;
    struct node *next;
} node;
node all[1000002];
int team[1000002];
node *last[1002];
node *queue , *freel , *lastf , *lastq;
void inqueue(node *previous, int num)
{
    node *tmp = freel;
    freel = freel->next;
    tmp->num = num;
    if(previous)
    {
        tmp->next = previous->next;
        previous->next=tmp;
        if(previous  == lastq)
        {
            lastq = tmp;
        }
    }
    else
    {
        lastq = queue = tmp;
        tmp->next = NULL;
    }
}
void dequeue()
{
    node *tmp = queue;
    queue = queue->next;
    tmp->next = NULL;
    if(lastq  == tmp)
    {
        lastq = NULL;
    }
    lastf->next = tmp;
    lastf = tmp;
    printf("%d\n", tmp->num);
}
int main(int argc, char *argv[])
{
    int n, num, each, i, j, maxlen, ser=0;
    char str[10];
    while(scanf("%d", &n)  && n)
    {
        ++ser;
        printf("Scenario #%d\n", ser);
        memset(last, 0, sizeof(node *)*(n+1));
        freel = &all[0];
        queue = lastq = NULL;
        maxlen = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &num);
            maxlen  += num;
            for(j = 0; j < num; j++)
            {
                scanf("%d", &each);
                team[each] = i+1;
            }
        }
        lastf = &all[maxlen];
        for(i = 0; i < maxlen ; i++)
        {
            all[i].next = &all[i+1];
        }
        while(scanf("%s", str) != EOF  && str[0] != 'S')
        {
            if(str[0]  == 'E')
            {
                scanf("%d", &num);
                if(last[team[num]])
                {
                    inqueue(last[team[num]], num);
                    last[team[num]] = last[team[num]]->next;
                }
                else
                {
                    inqueue(lastq, num);
                    last[team[num]] = lastq;
                }
            }
            else
            {
                num = queue->num;
                if(last[team[num]]  == queue)
                {
                    last[team[num]] = NULL;
                }
                dequeue();
            }
        }
        printf("\n");
    }
    return 0;
}
