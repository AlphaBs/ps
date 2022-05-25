#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool map[20'100][20'100];
int N;

bool get(int x, int y)
{
    return map[y+10'000][x+10'000];
}

void set(int x, int y, bool v)
{
    map[y+10'000][x+10'000] = v;
}

// (minxX, minY) ~ (maxX, maxY) 에서 가장 짧은 선 구하기
int find(int minX, int minY, int maxX, int maxY)
{


    int midX = (minX + maxX) / 2;
    int midY = (minY + maxY) / 2;
    return min({
        find(minX, minY, minX+midX, minY+midY), // 왼쪽아래
        find(midX+1, minY, maxX, midY), // 오른쪽아래
        find(minX, midY+1, midX, maxY), // 왼쪽위
        find(midX+1, midY+1, maxX, maxY), // 오른쪽위
        find((minX+midX)/2, (minY+midY)/2, (midX+maxX)/2, (midY+maxY)/2)}); // 가운데
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int minX = 999'999, minY = 999'999;
    int maxX = -999'999, maxY = -999'999;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        if (get(x, y))
        {
            cout << "0";
            return 0;
        }
        set(x, y, true);

        if (minX > x) minX = x;
        if (minY > y) minY = y;
        if (maxX < x) maxX = x;
        if (maxY < y) maxY = y;
    }

    int count = 0;
    for (int y = -10000; y <= 10000; y++)
    for (int x = -10000; x <= 10000; x++)
    {
        if (get(x, y)) count++;
    }
    cout << count;
    //cout << find(minX, minY, maxX, maxY);

    return 0;
}