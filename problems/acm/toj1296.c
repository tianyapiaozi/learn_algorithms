#include<stdio.h>
#include <string.h>
#define N 46349
#define SINT (sizeof(int)*8)
int prime[5000];
unsigned int num[N/SINT+1] = {0};
unsigned int check[1000000/SINT+1];
int main(int argc, char *argv[])
{
    int i, pn = 0, j, l, u, diff, d, max, min, count, minl, minr, maxl, maxr, mod, prep;
    for(i = 2; i < N; i++)
    {
        if((num[i/SINT] >> (i%SINT)) & 1)
        {
            continue;
        }
        prime[pn++] = i;
        for(j = i*i; j < N; j += i)
        {
            num[j/SINT] |= (1 << (j%SINT));
        }
    }
    while(scanf("%d%d", &l, &u) != EOF)
    {
        count = 0;
        min = 1000001;
        max = -1;
        if(u <= prime[pn-1])
        {
            for(i = 0; i < pn  && prime[i]<l; i++)
            {
                ;
            }
            for(i++; i < pn && prime[i]  <= u; i++)
            {
                d = prime[i]-prime[i-1];
                count++;
                if(d < min)
                {
                    min = d;
                    minl = prime[i-1];
                    minr = prime[i];
                }
                if(d > max)
                {
                    max = d;
                    maxl = prime[i-1];
                    maxr = prime[i];
                }
            }
        }
        else
        {
            diff = u - l;
            memset(check, 0, (diff)/8+1);
            for(i = 0; i < pn; i++)
            {
                mod = u % prime[i];
                for(j = u - mod; j  >= l; j -= prime[i])
                {
                    check[(j-l)/SINT] |= (1 << (j-l)%SINT);
                }
            }
            for(i = 0; i <= diff  && ((check[i/SINT]  >> (i%SINT)) & 1); i++)
            {
                ;
            }
            prep = i;
            for(i++; i <= diff; i++)
            {
                if((check[i/SINT]   >>  (i%SINT) ) & 1)
                {
                    continue;
                }
                count ++;
                d =  i - prep;
                if(d < min)
                {
                    min = d;
                    minl = prep+l;
                    minr = i+l;
                }
                if(d > max)
                {
                    max = d;
                    maxl = prep+l;
                    maxr = i+l;
                }
                prep = i;
            }
        }
        if(count >= 1)
        {
            printf("%d,%d are closest, %d,%d are most distant.\n", minl, minr, maxl, maxr);
        }
        else
        {
            printf("There are no adjacent primes.\n");
        }
    }
    return 0;
}
