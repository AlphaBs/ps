#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num[500000];

int comp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    qsort(num, n, sizeof(int), comp);

    int maxModeFreq = 1; // 최대 빈도수
    int modeFreq = 1; // 빈도수
    int modeValue1 = num[0]; // 최대 빈도수의 값
    int modeValue2 = num[0];

    int sum = num[0];
    for (int i = 1; i < n; i++)
    {
        if (num[i] != num[i - 1])
            modeFreq = 0;

        modeFreq++;
        if (maxModeFreq <= modeFreq)
        {
            maxModeFreq = modeFreq;
            modeValue2 = modeValue1;
            modeValue1 = num[i];
        }

        sum += num[i];
    }

    // 산술평균
    printf("%d\n", (int)round(sum / (float)n));
    // 중앙값
    printf("%d\n", num[n == 1 ? 0 : n / 2]);
    // 최빈값
    printf("%d\n", modeValue2);
    // 범위
    printf("%d\n", num[0] - num[n - 1]);

    return 0;
}