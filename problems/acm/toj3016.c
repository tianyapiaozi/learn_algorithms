#include<stdio.h>
#include<string.h>
int n, m, p[80], i, j;
char ch1[81], ch2[81], ch, str[81], cnt, next, ccnt;
int main(){
    while(scanf("%d%d", &n, &m) != EOF && n){
        for(i = 0; i < n; i++)
            scanf("%d", &p[i]);
        scanf("%c", &ch);
        gets(ch1);
        strcpy(str, ch1);
        ch2[n] = '\0';
        for(i = 0; i < n; i++)
        {
            next = p[i];
            for(cnt = 1; ; cnt++, next=p[next-1])
            {
                if(i  == next-1)
                {
                    break;
                }
            }
            ccnt = m % cnt;
            next = i+1;
            for(j = 0; j < ccnt; j++)
            {
                next = p[next-1];
            }
            ch2[next-1] = ch1[i];
        }
        printf("%s\n", ch2);
    }
    return 0;
}
