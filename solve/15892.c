// https://www.acmicpc.net/problem/15829

#include <stdio.h>

int main()
{
    int length;
    char input[256];

    int r = 31;
    int m = 1234567891;

    scanf("%d %s", &length, input);

    long long tempr = 1;
    long long sum = 0;
    for (int i = 0; i < length; i++)
    {
        int charval = input[i] - 96;
        sum += charval * tempr;
        tempr *= r;
    }

    printf("%lld", sum % m);

    return 0;
}