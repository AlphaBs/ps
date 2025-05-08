// https://www.acmicpc.net/problem/27468

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int map[2'222'222];
bool used[2'222'222];

bool canMove(int a)
{
    return 1 <= a && a <= n;
}

bool generate(int length, int a0, int a1)
{
    if (length == n)
    {
        cout << "YES\n";
        for (int i = 1; i <= length; i++)
        {
            cout << map[i] << ' ';
        }
        return true;
    }

    int d = abs(a0 - a1);
    int d1 = d * 2;
    int d2 = d / 2;

    int nexts[] = {
        a1 + d1,
        a1 - d1,
        a1 + d2,
        a1 - d2
    };

    for (int i = 0; i < 4; i++)
    {
        int next = nexts[i];
        if (canMove(next) && !used[next])
        {
            used[next] = true;
            map[length + 1] = next;
            bool result = generate(length + 1, a1, next);
            if (result)
                return true;
            used[next] = false;
        }
    }

    return false;
}

void start()
{
    for (int a0 = 1; a0 <= n; a0++)
    {
        used[a0] = true;
        map[1] = a0;
        for (int a1 = 1; a1 <= n; a1++)
        {   
            if (used[a1])
                continue;
            used[a1] = true;
            map[2] = a1;
            bool result = generate(2, a0, a1);
            if (result)
                return;
            used[a1] = false;
        }
        used[a0] = false;
    }
    cout << "NO\n";
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 3; i <= 1000; i++)
    {
        if (i % 4 != 0) continue;
        for (int j = 0; j < 2'222'222; j++)
            used[j] = false;
        cout << endl << i << endl;
        n = i;
        start();
    }
    return 0;
}