#include <stdio.h>
#include <stdlib.h>
int cmp(const void *arg1, const void* arg2)
{
    return *(const int*)arg1-*(const int*)arg2;
}
int main(int argc, char *argv[])
{
    int num[1001], n, i, j, tofind, start, end, mid, find;
    while(scanf("%d", &n) != EOF  && n)
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        qsort(num, n, sizeof(int), cmp);
        find = -1;
        for(i = n-1; i  >= 2  && find  ==  -1; i--)
        {
            for(j = i-1; j >= 0  && num[j] >= num[i]/2; j--)
            {
                tofind = num[i]-num[j];
                start = 0;
                end = j;
                while(start <= end)
                {
                    mid = (start+end)/2;
                    if(num[mid]  == tofind)
                    {
                        break;
                    }
                    if(num[mid] > tofind)
                    {
                        end = mid-1;
                    }
                    else
                    {
                        start = mid+1;
                    }
                }
                if(num[mid]  == tofind)
                {
                    if(mid != j || (num[mid] == num[mid+1] || (mid >= 1  &&  num[mid]  == num[mid-1])))
                    {
                        find = num[i];
                        break;
                    }
                }
            }
        }
        printf("%d\n", find);
    }
    return 0;
}
