#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> stk;
    int n, v;
    string cmd;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> v;
            stk.push(v);
        }
        else if (cmd == "pop")
        {
            if (stk.empty()) cout << "-1\n";
            else 
            {
                cout << stk.top() << "\n"; 
                stk.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << stk.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << (stk.empty() ? "1" : "0") << "\n";
        }
        else if (cmd == "top")
        {
            if (stk.empty()) cout << "-1\n";
            else cout << stk.top() << "\n";
        }
    }

    return 0;
}