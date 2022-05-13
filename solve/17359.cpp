#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    bool inputs[10];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 1; j < str.size(); j++)
            if (str[j-1] != str[j]) sum++;

        if (str.front() == str.back()) // 1~~~1, 0~~~0
            inputs[i] = 1;
    }

    int min = INT32_MAX;
    do
    {
        int count = 0;
        for (int i = 1; i < n; i++)
            if (inputs[i-1] && inputs[i]) count++;

        if (min > count)
            min = count;
    } while (next_permutation(inputs, inputs + n));
    
    cout << (min + sum);
    return 0;
}