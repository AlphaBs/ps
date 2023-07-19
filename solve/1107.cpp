// https://www.acmicpc.net/problem/1107

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int n, m;
bool buttons[11];
vector<int> clickedButtons;

int getClickedNumber()
{
    if (clickedButtons.size() == 0)
        return 999'999'999;

    int result = 0;
    int m = 1;
    for (int i = clickedButtons.size() - 1; i >= 0; i--)
    {
        result += (clickedButtons[i] * m);
        m *= 10;
    }
    return result;
}

int findMinButtonCounts()
{
    if (clickedButtons.size() > 6)
        return 999'999'999;
    
    int minResult = abs(getClickedNumber() - n) + clickedButtons.size();
    for (int i = 0; i <= 9; i++)
    {
        if (!buttons[i])
            continue;
        
        clickedButtons.push_back(i);
        minResult = min(minResult, findMinButtonCounts());
        clickedButtons.pop_back();
    }
    return minResult;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i <= 9; i++) buttons[i] = true;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        buttons[b] = false;
    }

    cout << min(abs(100 - n), findMinButtonCounts());
    return 0;
}