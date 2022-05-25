#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    int n, v;
    string cmd;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "push")
        {
            cin >> v;
            q.push(v);
        }
        else if (cmd == "pop")
        {
            if (q.empty()) cout << "-1\n";
            else 
            {
                cout << q.front() << "\n"; 
                q.pop();
            }
        }
        else if (cmd == "size")
        {
            cout << q.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << (q.empty() ? "1" : "0") << "\n";
        }
        else if (cmd == "front")
        {
            if (q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        }
        else if (cmd == "back")
        {
            if (q.empty()) cout << "-1\n";
            else cout << q.back() << "\n";
        }
    }

    return 0;
}