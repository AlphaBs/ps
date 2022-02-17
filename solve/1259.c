#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    char input[32];
    while (1)
    {
        scanf("%s", input);

        if (strcmp(input, "0") == 0)
            break;

        bool isPell = true;
        int length = strlen(input);
        for (int i = 0; i < length / 2; i++)
        {
            if (input[i] != input[length - i - 1])
            {
                isPell = false;
                break;
            }
        }

        if (isPell)
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}