#include <stdio.h>
#include <stdbool.h>

bool is666(int num)
{
    int count = 0;

    while (num)
    {
        int pn = num % 10;

        if (pn == 6)
        {
            count++;
            if (count >= 3)
                return true;
        }
        else
        {
            count = 0;
        }

        num /= 10;
    }

    return false;
}

int main()
{
    int input;
    scanf("%d", &input);

    int count = 0;
    for (int i = 666;;i++)
    {
        if (is666(i))
        {
            count++;
            if (count == input)
            {
                printf("%d", i);
                return 0;
            }
        }
    }
    return 0;
}