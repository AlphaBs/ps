#include <stdio.h>

int sum(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        if (sum(i) + i == n)
        {
            printf("%d", i);
            return 0;
        }
    }

    printf("0");
    return 0;
}