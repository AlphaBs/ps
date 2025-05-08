// https://www.acmicpc.net/problem/25955

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[1111];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char token[11];
        cin >> token;

        int level = 10000 - atoi(&token[1]);
        if (token[0] == 'B')
            level += 0;
        if (token[0] == 'S')
            level += 10000;
        if (token[0] == 'G')
            level += 20000;
        if (token[0] == 'P')
            level += 30000;
        if (token[0] == 'D')
            level += 40000;

        arr[i] = level;
    }

    int arrCopy[1111];
    for (int i = 0; i < n; i++)
    {
        arrCopy[i] = arr[i];
    }

    sort(arr, arr + n);

    int wrongItems[11];
    int wrongItemCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arrCopy[i])
        {
            wrongItems[wrongItemCount++] = arr[i];
        }
    }

    if (wrongItemCount == 0)
    {
        cout << "OK";
    }
    else
    {
        cout << "KO\n";

        for (int i = 0; i < wrongItemCount; i++)
        {
            int tier = wrongItems[i] / 10000;
            if (tier == 0)
                cout << 'B';
            if (tier == 1)
                cout << 'S';
            if (tier == 2)
                cout << 'G';
            if (tier == 3)
                cout << 'P';
            if (tier == 4)
                cout << 'D';
            
            int level = 10000 - (wrongItems[i] % 10000);
            cout << level << ' ';
        }
    }

    return 0;
}