// https://www.acmicpc.net/problem/18870

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Item
{
    int index;
    int value;
    int count;
};

int n;
Item items[1'111'111];

bool compareValue(const Item& a, const Item& b)
{
    return a.value < b.value;
}

bool compareIndex(const Item& a, const Item& b)
{
    return a.index < b.index;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        items[i] = { i, v, 0 };
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    sort(items, items + n, compareValue);

    int c = 0;
    for (int i = 1; i < n; i++)
    {
        if (items[i - 1].value < items[i].value)
            c++;
        items[i].count = c;
    }

    sort(items, items + n, compareIndex);

    for (int i = 0; i < n; i++)
    {
        cout << items[i].count << ' ';
    }
    return 0;
}