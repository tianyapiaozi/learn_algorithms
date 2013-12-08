#include <stdio.h>
int main(int argc, char *argv[])
{
    int t, n, length, speed, posp, speedp, num, i, diff;
    double t1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &length, &speed);
        num = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d%d", &posp, &speedp);
            diff = speed - speedp;
            if(diff == 0)
            {
                if(posp  == 0)
                {
                    num += 1;
                }
            }
            else
            {
                t1 = (double)posp / diff;
                if(t1  >= -1e-6  && t1 * speed  <= length + 1e-6)
                {
                    num+=1;
                }
            }
        }
        printf("%d\n", num);
    }
    return 0;
}
