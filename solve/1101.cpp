// https://www.acmicpc.net/problem/1101

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int boxColor[55][55];

int find(int jokerBox)
{
    int moveCount = 0;
    for (int box = 0; box < n; box++)
    {
        if (box == jokerBox)
            continue;

        int colorCount = 0;
        for (int color = 0; color < m; color++)
        {
            if (boxColor[box][color] > 0)
            {
                colorCount++;
            }
        }

        if (colorCount == 0)
        {
            // empty box, ignore
            continue;
        }
        else if (colorCount == 1)
        {
            // move to box
            
        }
        else
        {
            // move to joker
            moveCount++;
        }
    }
    return moveCount;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    for (int box = 0; box < n; box++)
    {
        for (int color = 0; color < m; color++)
        {
            cin >> boxColor[box][color];
        }
    }

    int result = 999'999'999;
    for (int joker = 0; joker < n; joker++)
    {
        result = min(result, find(joker));
        //cout << find(joker) << endl;
    }
    cout << result;
    return 0;
}