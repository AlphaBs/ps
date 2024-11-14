// https://www.acmicpc.net/problem/9663

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n, result;

bool placeX[22];
bool placeLeft[50];
bool placeRight[50];

void place(int y, int x, bool value)
{
    placeX[x] = value;
    placeLeft[x - y] = value;
    placeRight[x + y] = value;
}

void find(int y)
{
    if (y == n)
    {
        result++;
        return;
    }

    for (int x = 0; x < n; x++)
    {
        if (!placeX[x] && !placeLeft[x - y] && !placeRight[x + y])
        {
            place(y, x, true);
            find(y + 1);
            place(y, x, false);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    find(0);
    cout << result;
    return 0;
}