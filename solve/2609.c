#include <stdio.h>

int gcd(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d\n%d", gcd(a, b), lcm(a, b));
    return 0;
}