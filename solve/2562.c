#include <stdio.h>

int main()
{
    int maxindex = 0;
    int max = 0;
    for (int i = 0; i < 9; i++)
    {
        int input = 0;
        scanf("%d", &input);
        if (input > max)
        {
            max = input;
            maxindex = i;
        }
    }

    printf("%d\n%d", max, maxindex + 1);
}