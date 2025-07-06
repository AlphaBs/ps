// https://www.acmicpc.net/problem/17354

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

#define ll long long

using namespace std;

ll screenWidth, screenHeight;
ll bx, by; // 현재 위치
ll vx, vy; // 가속도

bool canMove(ll y, ll x)
{
    if (!(0 <= y && y < screenHeight))
        return false;
    if (!(0 <= x && x < screenWidth))
        return false;
    return true;
}

bool isEnd()
{
    // 왼쪽위
    if (by == 0 && bx == 0)
        return true;
    
    // 왼쪽아래
    if (by + 1 == screenHeight && bx == 0)
        return true;
    
    // 오른쪽위
    if (by == 0 && bx + 1 == screenWidth)
        return true;
    
    // 오른쪽아래
    if (by + 1 == screenHeight && bx + 1 == screenWidth)
        return true;

    // 아님
    return false;
}

ll moveToEnd()
{
    ll yAfterY, xAfterY, tAfterY;
    if (vy < 0) // 위로
    {
        tAfterY = by;
        yAfterY = 0;
        xAfterY = bx + vx * tAfterY;
    }
    else // 아래로
    {
        tAfterY = screenHeight - 1 - by;
        yAfterY = screenHeight - 1;
        xAfterY = bx + vx * tAfterY;
    }

    if (canMove(yAfterY, xAfterY))
    {
        by = yAfterY;
        bx = xAfterY;
        return tAfterY;
    }

    ll xAfterX, yAfterX, tAfterX;
    if (vx < 0) // 왼쪽으로
    {
        tAfterX = bx;
        yAfterX = by + vy * tAfterX;
        xAfterX = 0;
    }
    else // 오른쪽으로
    {
        tAfterX = screenWidth - 1 - bx;
        yAfterX = by + vy * tAfterX;
        xAfterX = screenWidth - 1;
    }

    by = yAfterX;
    bx = xAfterX;
    return tAfterX;
}

void invertVelocity()
{
    if (bx == 0)
        vx = 1;
    else if (bx + 1 == screenWidth)
        vx = -1;
    else if (by == 0)
        vy = 1;
    else if (by + 1 == screenHeight)
        vy = -1;
}

ll encodePos(ll y, ll x)
{
    return y * 1111111 + x;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int boxWidth, boxHeight;
    cin >> boxWidth >> boxHeight >> screenWidth >> screenHeight;
    cin >> bx >> by;
    cin >> vx >> vy;

    screenWidth = screenWidth - boxWidth + 1;
    screenHeight = screenHeight - boxHeight + 1;

    unordered_set<ll> visit;
    ll t = 0;
    while (!isEnd())
    {
        ll pos = encodePos(by, bx);
        if (visit.find(pos) == visit.end()) // 가본적 없는 좌표
        {
            visit.insert(pos);
            t += moveToEnd();
            invertVelocity();
            //cout << bx << "," << by << " v" << vx << "," << vy << " t=" << t << endl;
        }
        else // 가본적 있는 좌표
        {
            t = -1;
            break;
        }
    }

    cout << t;
    return 0;
}