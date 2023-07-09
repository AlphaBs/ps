#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int mem[22];

int cal(int n)
{
    if (n < 0) return 0;
    if (n == 0) return 1;
    if (mem[n] > 0) return mem[n];

    int sum = 0;
    for (int i = 3; i > 0; i--)
    {
        sum += cal(n - i);
    }
    return mem[n] = sum;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    int n;
    while (tc--)
    {
        cin >> n;
        cout << cal(n) << "\n";
    }        

    return 0;
}