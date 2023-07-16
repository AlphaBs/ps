// https://www.acmicpc.net/problem/2448

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
bool map[6666][6666];

bool minTriangle[3][6] = 
{
    { 0, 0, 1, 0, 0, 0 },
    { 0, 1, 0, 1, 0, 0 },
    { 1, 1, 1, 1, 1, 0 }
};

void draw(int x, int y, int n)
{
    if (n == 3)
    {
        for (int ty = 0; ty < 3; ty++)
        for (int tx = 0; tx < 6; tx++)
            map[ty + y][tx + x] = minTriangle[ty][tx];
        return;
    }

    int nextN = n / 2;
    draw(x + nextN, y, nextN);
    draw(x, y + nextN, nextN);
    draw(x + nextN * 2, y + nextN, nextN);
}

void draw(int n)
{
    draw(0, 0, n);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n * 2; x++)
        {
            cout << (map[y][x] ? '*' : ' ');
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    draw(n);

    return 0;
}