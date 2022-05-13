#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
int map[8][8];
stack<char> stk;

int check(int xn, int yn, int n)
{
    int first = map[yn][xn];
    for (int y = 0; y < yn; y++)
    for (int x = 0; x < xn; x++)
    {
        if (first != map[y][x])
            return -1;
    }
    return first;
}

int comp(int x, int y, int n)
{
    if (n == 0)
        return map[y][x];
    
    int next = n / 2;
    int r1 = check(x + next * 0, y + next * 0, next);
    int r2 = check(x + next * 1, y + next * 0, next);
    int r3 = check(x + next * 0, y + next * 1, next);
    int r4 = check(x + next * 1, y + next * 1, next);

    if ((r1 == r2) && (r2 == r3) && (r3 ==r4) && r1 >= 0)
    {
        return r1;
    }
    else
    {
        cout << "(";
        comp(x + next * 0, y + next * 0, next);
        comp(x + next * 1, y + next * 0, next);
        comp(x + next * 0, y + next * 1, next);
        comp(x + next * 1, y + next * 1, next);
        cout << ")";
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    for (int y = 0; y < n; y++)
    {
        char inp[10];
        cin >> inp;
        for (int x = 0; x < n; x++)
            map[y][x] = inp[x] - '0';
    }
    
    comp(0, 0, n);

    return 0;
}