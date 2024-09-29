// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int n, m;
    cin >> n >> m;

    set<string> set1;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        set1.insert(input);
    }

    set<string> set2;
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        if (set1.find(input) != set1.end())
            set2.insert(input);
    }

    cout << set2.size() << '\n';
    for (const string item : set2)
    {
        cout << item << '\n';
    }
    return 0;
}