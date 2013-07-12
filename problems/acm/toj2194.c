#include <stdio.h>
int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
int mine[102][102];
void expand(int r, int c, int n)
{
    int i, nr, nc;
    if(mine[r][c] != -1)
    {
        return;
    }
    mine[r][c] = 0;
    for(i = 0; i < 8; i++)
    {
        mine[r][c]  += mine[r+dir[i][0]][c+dir[i][1]]  == 9;
    }
    if(mine[r][c]  == 0)
    {
        for(i = 0; i < 8; i++)
        {
            nr = r+dir[i][0];
            nc = c+dir[i][1];
            if(mine[nr][nc] == -1 && nr  >= 1  && nr  <= n  && nc  >= 1  &&  nc  <= n)
            {
                expand(nr, nc, n);
            }
        }
    }
}
int main(int argc, char *argv[])
{
    int n, m, r, c, i, j, curr, curc, nr, nc;
    while(scanf("%d%d", &n, &m)  && n)
    {
        for(i = 0; i < n+2; i++)
        {
            for(j = 0; j < n+2; j++)
            {
                mine[i][j] = -1;
            }
        }
        for(i = 0; i < m; i++)
        {
            scanf("%d%d", &r, &c);
            mine[r][c] = 9;
        }
        scanf("%d%d", &r, &c);
        if(mine[r][c] == 9)
        {
            printf("oops!\n\n");
            continue;
        }
        expand(r, c, n);
        for(i = 1; i  <= n; i++)
        {
            for(j=1; j  <= n; j++)
            {
                if(mine[i][j] >= 0 && mine[i][j] <= 8)
                {
                    printf("%d", mine[i][j]);
                }
                else
                {
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
