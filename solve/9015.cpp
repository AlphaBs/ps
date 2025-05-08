// https://www.acmicpc.net/problem/9015

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Point
{
    int y, x;
};

int n;
Point points[3333];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> points[i].x >> points[i].y;
        }

        
    }

    return 0;
}