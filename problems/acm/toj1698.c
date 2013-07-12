#include <stdio.h>
#include <string.h>
int main(){
    int t, factor[7] = {9  ,3  ,7  ,9  ,3  ,7  ,9}, pos, i, len, tmp, rlt, j;
    char ch[8];
    scanf("%d", &t);
    for(j = 1; j <= t; j++){
        scanf("%s", ch);
        len = strlen(ch);
        tmp = 0;
        for(i = len-1; i  >= 0; i--)
            if(ch[i] != '?')
                tmp += (ch[i]-'0')*factor[len-i-1];
            else
                pos = len-1-i;
        tmp = 10 - tmp % 10;
        if(factor[pos] == 3)
            rlt = tmp * 7 % 10;
        else if(factor[pos] == 7)
            rlt = tmp * 3 % 10;
        else
            rlt = tmp * 9 % 10;
        ch[len-1-pos] = rlt + '0';
        printf("Scenario #%d:\n%s\n\n", j, ch);
    }
    return 0;
}
