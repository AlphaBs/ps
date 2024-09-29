#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct ColorCount 
{
    int white, blue;
};

int map[128][128];

bool isZeroEqual(ColorCount a, ColorCount b)
{
    return a.blue == b.blue && a.white == b.white;
}

ColorCount merge(ColorCount a, ColorCount b, ColorCount c, ColorCount d)
{
    if (isZeroEqual(a, b) && isZeroEqual(b, c) && isZeroEqual(c, d))
    {
        if (a.blue == 1 && a.white == 0) return ColorCount {0, 1};
        else if (a.blue == 0 && a.white == 1) return ColorCount {1, 0};
    }

    ColorCount result = {0, 0};
    result.blue += a.blue += b.blue += c.blue += d.blue;
    result.white += a.white += b.white += c.white += d.white;
    return result;
}

ColorCount check(int n, int x, int y)
{
    if (n == 1)
    {
        if (map[y][x]) return ColorCount {0, 1}; // blue
        else return ColorCount {1, 0}; // white
    }
    
    int half = n / 2;
    ColorCount p1 = check(half, x, y);
    ColorCount p2 = check(half, x + half, y);
    ColorCount p3 = check(half, x, y + half);
    ColorCount p4 = check(half, x + half, y + half);

    return merge(p1, p2, p3, p4);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
        cin >> map[y][x];
    
    ColorCount result = check(n, 0, 0);
    cout << result.white << "\n" << result.blue;

    return 0;
}