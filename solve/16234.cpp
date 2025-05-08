// https://www.acmicpc.net/problem/16234

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, l, r;
int people[55][55];
bool isOpen[55][55][4];

int dy[4] = { -1, 0, 1,  0 };
int dx[4] = {  0, 1, 0, -1 };

bool visitInSum[55][55];
bool visitInSet[55][55];

bool canMove(int y, int x)
{
    if (!(0 <= y && y < n))
        return false;
    if (!(0 <= x && x < n))
        return false;
    return true;
}

bool shouldOpen(int a, int b)
{
    int d = abs(a - b);
    return (l <= d && d <= r);
}

int sumPeople(int y, int x, int& count)
{
    visitInSum[y][x] = true;
    count++;

    int totalPeople = people[y][x];
    
    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (canMove(nextY, nextX) && isOpen[y][x][i] && !visitInSum[nextY][nextX])
        {
            totalPeople += sumPeople(nextY, nextX, count);
        }
    }

    return totalPeople;
}

void resetVisitInSet()
{
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        visitInSet[y][x] = false;
    }
}

void setPeople(int y, int x, int v)
{
    visitInSet[y][x] = true;
    people[y][x] = v;

    for (int i = 0; i < 4; i++)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (canMove(nextY, nextX) && isOpen[y][x][i] && !visitInSet[nextY][nextX])
        {
            setPeople(nextY, nextX, v);
        }
    }
}

void printMap()
{
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            cout << people[y][x] << ' ';
        }
        cout << endl;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> l >> r;
    for (int y = 0; y < n; y++)
    for (int x = 0; x < n; x++)
    {
        cin >> people[y][x];
    }

    int d = 0;
    while (true)
    {
        // 국경 모두 닫기
        for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
        {
            for (int i = 0; i < 4; i++)
                isOpen[y][x][i] = false;

            visitInSum[y][x] = false;
            visitInSet[y][x] = false;
        }
        
        // L 이상 R 이하 국경 열기
        bool hasMoved = false;
        for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
        {
            // 왼쪽
            if (canMove(y, x + 1) && shouldOpen(people[y][x], people[y][x + 1]))
            {
                isOpen[y][x][1] = true;
                isOpen[y][x + 1][3] = true;
                hasMoved = true;
            }

            // 아래쪽
            if (canMove(y + 1, x) && shouldOpen(people[y][x], people[y + 1][x]))
            {
                isOpen[y][x][2] = true;
                isOpen[y + 1][x][0] = true;
                hasMoved = true;
            }
        }

        if (!hasMoved)
            break;

        // 인구 이동
        for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
        {
            if (visitInSum[y][x])
                continue;

            int count = 0;
            int totalPeople = sumPeople(y, x, count);
            int newPeople = totalPeople / count;

            resetVisitInSet();
            setPeople(y, x, newPeople);
        }

        // 하루 끝
        d++;

        //printMap();
        //cout << endl;
    }

    cout << d;
    return 0;
}