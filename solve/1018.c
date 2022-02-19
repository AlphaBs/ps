#include <stdio.h>

char map[50][50];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            scanf("%c", &map[y][x]);
        }
        getchar();
    }

    int min = 999999;
    for (int ty = 0; ty < n - 7; ty++)
    {
        for (int tx = 0; tx < m - 7; tx++)
        {
            char color = 'W';
            char correct = 0;
            char incorr = 0;

            for (int y = 0; y < 8; y++)
            {
                for (int x = 0; x < 8; x++)
                {
                    if (color == map[ty+y][tx+x])
                        correct++;
                    else
                        incorr++;
                    
                    if (x != 7)
                    {
                        if (color == 'W')
                            color = 'B';
                        else
                            color = 'W';
                    }
                }
            }

            if (correct > incorr)
                correct = incorr;
            
            if (min > correct)
                min = correct;
        }
    }

    printf("%d", min);
    
    return 0;
}