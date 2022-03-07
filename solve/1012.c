#include <stdio.h>
#include <stdlib.h>

#define INDEX(x,y,m) y*m+x

int check(char* map, int x, int y, int m, int n)
{
    if (x < 0 || y < 0)
        return 0;
    if (x > m - 1 || y > n - 1)
        return 0;

    if (map[INDEX(x, y, m)] == 0)
        return 0;

    map[INDEX(x, y, m)] = 0;
    check(map, x - 1, y, m, n);
    check(map, x + 1, y, m, n);
    check(map, x, y - 1, m, n);
    check(map, x, y + 1, m, n);

    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--)
    {
        // 입력
        int m, n, k;
        scanf("%d %d %d", &m, &n, &k);

        char* map = (char*)malloc(m * n * sizeof(char));
        for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            map[INDEX(x, y, m)] = 0;
        }

        for (int i = 0; i < k; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            map[INDEX(x, y, m)] = 1;
        }

        // 확인
        int count = 0;
        for (int y = 0; y < n; y++)
        for (int x = 0; x < m; x++)
        {
            count += check(map, x, y, m, n);
        }

        printf("%d\n", count);

        // 해제
        free(map);
    }

    return 0;
}