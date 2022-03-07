#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char buffer[128];
    while (1)
    {
        scanf("%[^\n]", buffer);
        if (strcmp(buffer, ".") == 0)
            break;

        int index = 0;
        int lastOpener = -1; // 1: () 2: []
        int small = 0;
        int big = 0;
        char next;
        bool result = true;
        while (buffer[index++] != '.')
        {
            if (!result)
                continue;

            if (next == '(')
            {
                // if (lastOpener == 2)
                //     result = false;
                lastOpener = 1;
                small++;
            }
            else if (next == ')')
            {
                small--;
                if (small < 0)
                    result = false;
            }
            else if (next == '[')
            {
                // if (lastOpener == 1)
                //     result = false;
                lastOpener = 2;
                big++;
            }
            else if (next == ']')
            {
                big--;
                if (big < 0)
                    result = false;
            }
        }

        bool isValid = (result && small == 0 && big == 0);

        if (isValid)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}