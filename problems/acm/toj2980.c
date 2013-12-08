#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char board[2][10], str[120];
    int score[2], n, i, j, len;
    while(scanf("%d", &n) != EOF  && n)
    {
        score[0] = score[1] = 0;
        while(getchar() != '\n')
            ;
        for(i = 0; i < n; i++)
        {
            gets(str);
            len = strlen(str);
            while(str[len-1] == ' ')
            {
                str[--len]='\0';
            }
            if(len > 8  && memcmp(str+len-8, " no good", 8)  == 0)
            {
                board[i&1][i/2] = 'X';
            }
            else
            {
                board[i&1][i/2] = 'O';
                score[i&1]  += 1;
            }
        }
        if(n & 1)
        {
            board[i&1][i/2] = '-';
            n  += 1;
        }
        for(i = 0; i < n / 2; i++)
        {
            printf("%d ", i+1);
        }
        printf("Score\n");
        for(j = 0; j < 2; j++)
        {
            for(i = 0; i < n / 2; i++)
            {
                printf("%c ", board[j][i]);
            }
            printf("%d\n", score[j]);
        }
    }
    return 0;
}
