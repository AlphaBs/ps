// https://www.acmicpc.net/problem/1541

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
    
    string input;
    cin >> input;
    input.push_back('+');

    int sum = 0;
    int start = 0;
    int count = 0;
    int d = 1;
    for (int i = 0; i < input.size(); i++)
    {
        char ch = input[i];
        if (ch == '+' || ch == '-')
        {
            int next = stoi(input.substr(start, count));
            //cout << next << endl;
            sum += next * d;
            start = i + 1;
            count = 0;

            if (ch == '-')
                d = -1;
        }
        else
        {
            count++;
        }
    }
    cout << sum;
    return 0;
}