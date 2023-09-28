// baekjoon 1006 

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, w;
int sectors[222222];

bool isInnerSector(int i)
{
    return i < n;
}

int getLeftSector(int i)
{
    return (i - 1) % n;
}

int getRightSector(int i)
{
    return (i + 1) % n;
}

int getUpDownSector(int i)
{
    if (isInnerSector(i))
        return i + n;
    else
        return i - n;
}

int solve()
{
    cin >> n >> w;
    for (int i = 0; i < n * 2; i++)
    {
        cin >> sectors[i];
    }

    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << "\n";
    }    

    return 0;
}