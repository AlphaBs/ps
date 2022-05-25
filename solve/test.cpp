#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < 100; i++)
    {
        if (i % 15 != i & 15)
            cout << i << "\n";
    }

    return 0;
}