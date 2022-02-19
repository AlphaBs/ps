#include <stdio.h>

int map[100];
int prime[1001] = {0};

int main()
{
    int n;
    scanf("%d", &n);

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &map[i]);
        if (max < map[i])
            max = map[i];
    }

    // 0: 소수
    // 1: 소수가 아님
    prime[0] = 1;
    prime[1] = 1;

    for (int i = 2; i <= max; i++)
    {
        if (prime[i] == 0)
        {
            int next = i;
            while ((next += i) <= max)
            {
                prime[next] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (prime[map[i]] == 0)
            count++;
    }

    printf("%d", count);

    return 0;
}