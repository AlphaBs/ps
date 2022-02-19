#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    getchar();

    char str[51];
    for (int i = 0; i < t; i++)
    {
        scanf("%s", str);
        getchar();
        
        int c = 0;
        for (int j = 0; j < strlen(str); j++)
        {
            if (str[j] == '(')
                c++;
            else if (str[j] == ')')
                c--;
            
            if (c < 0)
                break;
        }

        if (c == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}