// https://www.acmicpc.net/problem/1342

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string line;

bool isGood()
{
    if (line.length() <= 1)
        return true;

    for (int i = 1; i < line.length(); i++)
    {
        if (line[i] == line[i - 1])
            return false;
    }
    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> line;
    sort(line.begin(), line.end());
    int count = 0;
    do
    {
        if (isGood())
            count++;
    } while (next_permutation(line.begin(), line.end()));

    cout << count;
    return 0;
}