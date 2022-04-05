#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int count = 0;
    while (n != 1)
    {
        int r = n % 3;
        if (r == 1)
        {
            n = n / 3 - 1;
            count += 2;
        }
        else if (r == 0)
        {
            n = n / 3;
            count += 1;
        }
        else
        {
            r = n % 2;
            if (r == 1)
            {
                n = n / 2 - 1;
                count += 2;
            }
            else
            {
                n = n / 2;
                count += 1;
            }
        }
    }

    printf("%d", count);
    return 0;
}