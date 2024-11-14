// https://www.acmicpc.net/problem/1918

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

string input;    
stack<char> stk;

int getPriority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input;

    for (const auto& ch : input)
    {
        int p = getPriority(ch);
        if (ch == '(')
        {
            stk.push('(');
        }
        else if (ch == ')')
        {
            while (!stk.empty())
            {
                if (stk.top() == '(')
                {
                    stk.pop();
                    break;
                }
                cout << stk.top();
                stk.pop();
            }
        }
        else if (p == -1)
        {
            cout << ch;
        }
        else
        {
            while (!stk.empty() && p <= getPriority(stk.top()))
            {
                cout << stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while (!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
    return 0;
}