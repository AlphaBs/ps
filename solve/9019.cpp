#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

short prevNode[11111];
char opHistory[11111];

int opD(int input)
{
    return (input * 2) % 10000;
}

int opS(int input)
{
    if (input == 0)
        return 9999;
    else
        return input - 1;
}

int opL(int input)
{
    int d1 = input / 1000;
    int d234 = input % 1000;
    return d234 * 10 + d1;
}

int opR(int input)
{
    int d4 = input % 10;
    int d123 = input / 10;
    return d4 * 1000 + d123;
}

void solve(int start, int dest)
{
    for (int i = 0; i < 11111; i++)
        prevNode[i] = opHistory[i] = -1;

    queue<int> q;
    q.push(start);
    while (q.size())
    {
        int node = q.front();
        q.pop();
        
        if (node == dest)
            break;

        int next[] = 
        { 
            opD(node), 
            opS(node), 
            opL(node), 
            opR(node) 
        };

        for (int i = 0; i < 4; i++)
        {
            if (prevNode[next[i]] == -1)
            {
                prevNode[next[i]] = node;
                opHistory[next[i]] = i;
                q.push(next[i]);
            }
        }
    }
}

void printResult(int start, int dest)
{
    static string dslr = "DSLR";
    stack<char> history;
    int curr = dest;
    while (curr != start)
    {
        history.push(dslr[opHistory[curr]]);
        curr = prevNode[curr];
    }

    while (history.size())
    {
        cout << history.top();
        history.pop();
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (; t > 0; t--)
    {
        int a, b;
        cin >> a >> b;
        solve(a, b);
        printResult(a, b);
        cout << '\n';
    }

    return 0;
}