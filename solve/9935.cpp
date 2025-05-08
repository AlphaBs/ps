// https://www.acmicpc.net/problem/9935

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input, target;
    cin >> input >> target;

    char last = target[target.size() - 1];
    stack<char> stk;
    stack<char> tmp;

    for (int i = 0; i < input.size(); i++)
    {
        stk.push(input[i]);

        int targetIndex = target.size() - 1;
        while (!stk.empty() && targetIndex >= 0)
        {
            if (stk.top() == target[targetIndex])
            {
                tmp.push(stk.top());
                stk.pop();
                targetIndex--;
            }
            else
            {
                break;
            }
        }

        if (targetIndex < 0)
        {
            while (!tmp.empty())
                tmp.pop();
        }

        while (!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
        }
    }

    if (stk.empty())
    {
        cout << "FRULA";
    }
    else
    {
        while (!stk.empty())
        {
            tmp.push(stk.top());
            stk.pop();
        }
        while (!tmp.empty())
        {
            cout << tmp.top();
            tmp.pop();
        }
    }

    return 0;
}