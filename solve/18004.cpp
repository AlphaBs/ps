// https://www.acmicpc.net/problem/18004

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int a, b;

int find(int from)
{
    if (from == b)
    {
        return 0;
    }
    else if (from > b)
    {
        if (from % 2 == 0)
        {
            return find(from / 2) + 1;
        }
        else
        {
            return find(from / 2 + 1) + 2;
        }
    }
    else if (from < b)
    {
        return b - from;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << find(a);
    return 0;
}