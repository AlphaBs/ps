// https://www.acmicpc.net/problem/9791

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        string input;
        cin >> input;
        
        if (input == "0")
            break;

        if (input.size() == 1)
        {
            cout << 1 << input[0] << '\n';
        }
        else
        {
            int length = 1;
            for (int i = 1; i < input.size(); i++)
            {
                if (input[i - 1] == input[i])
                {
                    length++;
                }
                else
                {
                    cout << length << (input[i - 1] - '0');
                    length = 1;
                }
            }

            if (length > 0)
                cout << length << (input[input.size() - 1] - '0');

            cout << '\n';
        }
    }

    return 0;
}