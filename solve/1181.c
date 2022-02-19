#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Word[51];
Word inputs[20001];

int comp(const void* a, const void* b)
{
    char* ra = (char*)a;
    char* rb = (char*)b;

    int compLength = strlen(ra) - strlen(rb);
    if (compLength == 0)
        return strcmp(ra, rb);
    return compLength;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", inputs[i]);
        getchar();
    }

    qsort(inputs, n, sizeof(Word), comp);

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && strcmp(inputs[i-1], inputs[i]) == 0)
            continue;

        printf("%s\n", inputs[i]);
    }
}