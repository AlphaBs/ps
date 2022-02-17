#include <stdio.h>

int main()
{
    int x, y, w, h;
    scanf("%d %d %d %d", &x, &y, &w, &h);

    int dw1 = x;
    int dw2 = w - x;
    int dh1 = y;
    int dh2 = h  - y;

    int minDisX = (dw1 < dw2) ? dw1 : dw2;
    int minDisY = (dh1 < dh2) ? dh1 : dh2;

    int minDis = (minDisX < minDisY) ? minDisX : minDisY;
    printf("%d", minDis);

    return 0;
}