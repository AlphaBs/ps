// https://www.acmicpc.net/problem/11723

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool s[22];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string op;
        cin >> op;

        if (op == "all")
        {
            for (int j = 0; j < 22; j++)
                s[j] = true;
        }
        else if (op == "empty")
        {
            for (int j = 0; j < 22; j++)
                s[j] = false;
        }
        else
        {
            int v;
            cin >> v;

            if (op == "add")
                s[v] = true;
            else if (op == "remove")
                s[v] = false;
            else if (op == "check")
                cout << (s[v] ? "1\n" : "0\n");
            else if (op == "toggle")
                s[v] = !s[v];
        }
    }

    return 0;
}