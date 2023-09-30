// https://www.acmicpc.net/problem/1099

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

#define NOT_VALUE 111'111'111

using namespace std;

int n;
string words[55];
string input;
int smem[55];
int cmem[55][55];

int calcCost(int startIndex, int wordIndex)
{
    int& res = cmem[startIndex][wordIndex];
    if (res != -1)
        return res;

    int alphabet[33] = {0, };
    int cost = 0;
    for (int i = 0; i < words[wordIndex].length(); i++)
    {
        alphabet[words[wordIndex][i] - 'a']++;
        alphabet[input[startIndex + i] - 'a']--;

        if (words[wordIndex][i] != input[startIndex + i])
            cost++;
    }

    for (int i = 0; i < 33; i++)
    {
        if (alphabet[i] != 0)
            return res = NOT_VALUE;
    }

    return res = cost;
}

int solve(int start)
{
    if (start >= input.length())
        return 0;

    int& res = smem[start];
    if (res != -1)
        return res;

    int minCost = NOT_VALUE;
    for (int i = 0; i < n; i++)
    {
        int nextCost = calcCost(start, i) + solve(start + words[i].length());
        minCost = min(minCost, nextCost);
    }
    return res = minCost;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill_n(smem, 55, -1);
    fill_n(cmem[0], 55*55, -1);

    cin >> input;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];

    int result = solve(0);
    cout << (result < NOT_VALUE ? result : -1) << endl;
    
    return 0;
}