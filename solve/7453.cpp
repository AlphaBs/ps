// https://www.acmicpc.net/problem/7453

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define ll long long 

using namespace std;

int n;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll arr[4567][4];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];    

    vector<ll> X;
    vector<ll> Y;
    X.reserve(n * n); 
    Y.reserve(n * n);

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        X.push_back(arr[i][0] + arr[j][1]);
        Y.push_back(arr[i][2] + arr[j][3]);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll count = 0;
    for (int i = 0; i < X.size(); i++)
    {
        count += (upper_bound(Y.begin(), Y.end(), -X[i]) - lower_bound(Y.begin(), Y.end(), -X[i]));
    }    

    cout << count;
    return 0;
}