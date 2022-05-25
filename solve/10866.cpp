#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    deque<int> deq;
    int n, v;
    string cmd;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> v;
            deq.push_front(v);
        }
        else if (cmd == "push_back")
        {
            cin >> v;
            deq.push_back(v);
        }
        else if (cmd == "pop_front")
        {
            if (deq.empty()) cout << "-1\n";
            else
            {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (deq.empty()) cout << "-1\n";
            else
            {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << deq.size() << "\n";
        }
        else if (cmd == "empty")
        {
            if (deq.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (cmd == "front")
        {
            if (deq.empty()) cout << "-1\n";
            else cout << deq.front() << "\n";
        }
        else if (cmd == "back")
        {
            if (deq.empty()) cout << "-1\n";
            else cout << deq.back() << "\n";
        }
    }

    return 0;
}