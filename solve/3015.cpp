// https://www.acmicpc.net/problem/3015

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>

using namespace std;

int n;
int arr[555'555];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int result = 0;
    for (int start = 0; start < n; start++)
    {
        for (int end = start + 1; end < n; end++)
        {
            result++;
            if (arr[start] < arr[end])
                break;
        }
    }

    cout << result;
    return 0;
}