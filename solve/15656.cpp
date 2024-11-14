// https://www.acmicpc.net/problem/15656

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int input[11];
int result[11];

void solve(int count)
{
    if (count > m)
    {
        for (int i = 1; i <= m; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        result[count] = input[i];
        solve(count + 1);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> input[i];
    sort(input, input + n);
    solve(1);
    return 0;
}