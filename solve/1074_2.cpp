#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int search(int n, int x, int y)
{
    if (n == 0)
    {
        return 0;
    }

    int length = pow(2, n);
    int half = length / 2;
    int part = half * half;

    if (x < half && y < half) // 0
        return part*0 + search(n-1, x, y);
    else if (x >= half && y < half) // 1
        return part*1 + search(n-1, x - half, y);
    else if (x < half && y >= half) // 2
        return part*2 + search(n-1, x, y - half);
    else if (x >= half && y >= half)
        return part*3 + search(n-1, x - half, y - half);
    else
        return 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, r, c;
    cin >> n >> r >> c;

    //int until = pow(2,n);
    //for (int y = 0; y < until; y++)
    //{
    //    for (int x = 0; x < until; x++)
    //        cout << search(n, x, y) << " ";
    //    cout << "\n";
    //}

    cout << search(n, c, r);
    return 0;
}