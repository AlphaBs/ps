#include <stdio.h>

#define LIMIT 1000000

// 1: 소수아님
// 0: 소수
int numbers[LIMIT+1];

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < n; i++)
    {
        numbers[i] = 0;
    }

    for (int i = 2; i <= n; i++)
    {
        if (numbers[i] == 1)
            continue;

        if (i >= m)
            printf("%d\n", i);

        int t = 1;
        while (1)
        {
            t++;
            int index = t * i;
            if (index > n)
                break;
            numbers[index] = 1;
        }
    }

    return 0;
}