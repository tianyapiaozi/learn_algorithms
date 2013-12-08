#include <stdio.h>
int main(int argc, char *argv[])
{
    int y, r, n, i, win;
    char str[16];
    char team[2][10] = {"Yellow","Red"};
    while(scanf("%d", &n)  && n)
    {
        y = r = 7;
        scanf("%s", str);
        for(i = 0; i < n; i++)
        {
            switch(str[i])
            {
                case 'Y':
                    y--;
                    break;
                case 'R':
                    r--;
                    break;
                case 'B':
                    win = r == 0 ? 1 : 0;
                    break;
                case 'L':
                    win = y == 0 ? 0 : 1;
                    break;
            }
        }
        printf("%s\n", team[win]);
    }
    return 0;
}
