#include <stdio.h>
#include <stdlib.h>

int tree[1000000];

long long getAvailableTreeMeter(int h, int* tree, int n)
{
    long long got = 0;
    for (int j = 0; j < n; j++)
    {
        int remain = tree[j] - h;
        if (remain > 0)
            got += remain;
    }
    return got;
}

int main()
{
    int n, m;
    int maxH = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int h;
        scanf("%d", &h);

        if (maxH < h)
            maxH = h;
        tree[i] = h;
    }

    // 이분탐색 [0, maxH)
    int middle = 0;
    int left = 0;
    int right = maxH - 1;
    long long value = 0;

    while (left <= right)
    {
        middle = (left + right) / 2;
        value = getAvailableTreeMeter(middle, tree, n);
        if (m < value)
        {
            right = middle - 1;
        }
        else if (m > value)
        {
            left = middle + 1;
        }
        else
        {
            break;
        }
    }

    printf("%d", middle);
    return 0;
}