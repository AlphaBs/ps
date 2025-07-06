// https://www.acmicpc.net/problem/25907

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int query(int d)
{
    if (d == 1)
        return 1;
    cout << "? " << d << endl;
    int r;
    cin >> r;
    return r;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    int lo = 1;
    int hi = n;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        int sheep = query(mid);
        int wolf = mid - sheep;

        if (sheep == wolf)
        {
            cout << "! " << mid << endl;
            return 0;
        }
        if (sheep > wolf)
        {
            lo = mid;
        }
        if (sheep < wolf)
        {
            hi = mid;
        }
    }

    cout << "! 0\n";
    return 0;
}