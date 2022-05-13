#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

void hanoi(int n, int from, int step, int to)
{
    if (n <= 0)
        return;

    hanoi(n - 1, from, to, step);
    cout << from << " " << to << "\n";
    hanoi(n - 1, step, from, to);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int count = pow(2, n) - 1;
    cout << count << "\n";
    hanoi(n, 1, 2, 3);

    return 0;
}