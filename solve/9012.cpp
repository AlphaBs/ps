#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool check(string& str)
{
    int sum = 0;
    for (char i : str)
    {
        if (i == '(') sum++;
        else if (i == ')')
        {
            sum--;
            if (sum < 0) return false;
        }
    }
    return sum == 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if (check(str))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}