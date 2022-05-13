#include "iostream"
#include "cstdio"
#include "algorithm"

using namespace std;

unsigned long long search(unsigned long long n)
{
    unsigned long long left = 0;
    unsigned long long right = n / 2;
    unsigned long long mid;
    bool found = false;

    while (left <= right)
    {
        mid = (left + right) / 2;
        unsigned long long power = mid * mid;
        if (n < power || mid > 3037000500) // power가 초과하는 경우
            right = mid - 1;
        else if (n > power)
            left = mid + 1;
        else
        {
            found = true;
            break;
        }
    }

    if (!found)
        mid = left;
    return mid;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unsigned long long n;
    cin >> n;
    cout << search(n);

    //for (int i = 0; i < 1000; i++)
    //{
    //    auto mid = search(i);
    //    cout << i << ":" << mid << "\n";
    //}
    return 0;
}