#include <stdio.h>
int sym['Z'+1];
char num[1001];
void torome(int n)
{
    while(n >= 1000)
    {
        printf("M");
        n  -= 1000;
    }
    int i = 100, j, k;
    for(; i > 0  && n; i /= 10)
    {
        if(n  >= 9*i)
        {
            printf("%c%c", num[i], num[i*10]);
            n -= 9 * i;
        }
        if(n >= 5*i)
        {
            printf("%c", num[5*i]);
            n  -= 5*i;
        }
        if(n  >= 4*i)
        {
            printf("%c%c", num[i], num[i*5]);
            n  -= 4*i;
        }
        k = n/i;
        for(j = 0; j < k; j++)
        {
            printf("%c", num[i]);
        }
        n  -= k*i;
    }
}
int todec(const char * str)
{
    int n = 0;
    while(*str)
    {
        if(*(str+1))
        {
            if(sym[*str] < sym[*(str+1)])
            {
                n  += sym[*(str+1)];
                n  -= sym[*str];
                str += 2;
                continue;
            }
        }
        n  += sym[*str];
        str += 1;
    }
    return n;
}
int main(int argc, char *argv[])
{
    sym['I'] = 1;
    sym['V'] = 5;
    sym['X'] = 10;
    sym['L'] = 50;
    sym['C'] = 100;
    sym['D'] = 500;
    sym['M'] = 1000;
    num[1] = 'I';
    num[5] = 'V';
    num[10] = 'X';
    num[50] = 'L';
    num[100] = 'C';
    num[500] = 'D';
    num[1000] = 'M';
    int t, i, sum, cas = 0;
    char str[64];
    while(scanf("%d", &t)  && t)
    {
        ++cas;
        sum = 0;
        for(i = 0; i < t; i++)
        {
            scanf("%s", str);
            sum  += todec(str);
        }
        printf("Case ");
        torome(cas);
        printf(": ");
        torome(sum);
        printf("\n");
    }
    return 0;
}
