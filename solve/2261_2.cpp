#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
struct Point {int x, y;};
Point points[100'100];
int N;

long long closest;

bool isGreater(Point a, Point b)
{
    return a.x < b.x && a.y < b.y;
}

void merge(int left, int mid, int right)
{
    static Point tmp[100'000];

    int l = left, r = right;
    while (left <= l && r <= right)
    {

    }

}

void find(int left, int right)
{
    if (left >= right) return;

    int mid = (left + right) / 2;
    find(left, mid);
    find(mid+1, right);
    merge(left, mid, right);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> points[i].x >> points[i].y;

    find(0, N - 1);
    cout << closest;

    return 0;
}