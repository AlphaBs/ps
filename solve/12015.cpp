// https://www.acmicpc.net/problem/12015

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> lis;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    lis.reserve(1'111'111);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int next;
        cin >> next;

        auto it = upper_bound(lis.begin(), lis.end(), next);
        if (it == lis.end())
        {
            lis.push_back(next);
        }
        else
        {
            *it = next;
        }
    }

    cout << lis.size();
    return 0;
}

// 10 20 10 30 20 50

// lower_bound 일때: 주어진 값보다 크거나 같은 값이 처음 나타나는 위치
// 10
// 10 20
// 10 20 <- 10대체
// 10 20 30
// 10 20 30 <- 20 대체
// 10 20 30 50

// upper_bound 일때: 주어진 값보다 큰 값이 처음 나타나는 위치
// 10
// 10 20
// 10 10 <- 20대체 <- 잘못됨
