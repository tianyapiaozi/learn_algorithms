#include <stdio.h>
int main(int argc, char *argv[])
{
    char map[256] = {0}, str[4096], *p, str2[4096];
    char match[4][18] = { "`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./"};
    int i, j;
    for(i = 0; i < 4; i++)
    {
        for(j = 0; match[i][j]; j++)
        {
            map[match[i][j+1]] = match[i][j];
        }
    }
    map[' '] = ' ';
    while(gets(str) != NULL)
    {
        for(i = 0; str[i]; i++)
        {
            str2[i] = map[str[i]];
        }
        str2[i] = '\0';
        printf("%s\n", str2);
    }
    return 0;
}
