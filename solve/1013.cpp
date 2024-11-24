// https://www.acmicpc.net/problem/1013

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

string input;

bool isEnd(int pos)
{
    return pos >= input.length();
}

// (100+1+ | 01)+
bool match(int state, int pos)
{
    switch (state)
    {
    case 0: // (100+1+ | 01)+
        if (isEnd(pos))
            return true;
        if (input[pos] == '0')
            return match(4, pos);
        else if (input[pos] == '1')
            return match(1, pos);

    case 1: // 100+1+
        if (isEnd(pos) || isEnd(pos + 1) || isEnd(pos + 2))
            return false;
        if (input[pos] == '1' && input[pos + 1] == '0' && input[pos + 2] == '0')
            return match(2, pos + 2);
        return false;
        
    case 2: // 0+
        if (isEnd(pos))
            return false;
        if (input[pos] == '0')
            return match(2, pos + 1);
        if (input[pos] == '1')
            return match(3, pos);

    case 3: // 1
        if (isEnd(pos))
            return false;
        if (input[pos] == '0')
            return false;
        if (input[pos] == '1')
            return match(5, pos + 1);

    case 5: // +
        if (isEnd(pos))
            return true;
        if (input[pos] == '0')
            return match(0, pos);
        if (input[pos] == '1')
            return match(5, pos + 1) || match(0, pos);

    case 4: // 01
        if (isEnd(pos) || isEnd(pos + 1))
            return false;
        if (input[pos] == '0' && input[pos + 1] == '1')
            return match(0, pos + 2);
        else
            return false;
    }

    assert(false);
    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++)
    {
        cin >> input;
        cout << (match(0, 0) ? "YES" : "NO");
        cout << '\n';
    }

    return 0;
}