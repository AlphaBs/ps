// https://www.acmicpc.net/problem/2201

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

#define ll unsigned long long

using namespace std;

ll fibs[111];

void initFibs(int count)
{
    fibs[0] = 0;
    fibs[1] = 1;
    fibs[2] = 2;
    for (int i = 3; i <= count; i++)
    {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
}

int floorFibIndex(ll v)
{
    int i = 1;
    while (!(fibs[i] <= v && v < fibs[i + 1])) i++;
    return i;
}

void printNumber(ll th)
{
    if (th == 1)
    {
        
    }
    else if (th == 2)
    {
        putchar('0');
    }
    else if (th == 3)
    {
        putchar('0');
        putchar('0');
    }
    else
    {
        ll fibIndex = floorFibIndex(th);
        ll fib0 = fibs[fibIndex - 0];
        ll fib1 = fibs[fibIndex - 1];
        ll fib2 = fibs[fibIndex - 2];
        ll fib3 = fibs[fibIndex - 3];

        // f 번째 수열 = ('0' + f-1 수열) concat ('01' + f-2 수열)

        ll thInFib0 = th - fib0 + 1;
        if (thInFib0 <= fib2)
        {
            putchar('0');

            ll thInFib1 = thInFib0 + fib1 - 1;
            printNumber(thInFib1);
        }
        else
        {
            putchar('0');
            putchar('1');

            ll thInFib2 = thInFib0 - 1;
            printNumber(thInFib2);
        }
    }
}

int main() 
{
    /*
    01 1
    02 10   
    03 100   
    04 101
    05 1000
    06 1001
    07 1010
    08 10000
    09 10001
    10 10010
    11 10100
    12 10101
    13 100000
    14 100001
    15 100010
    16 100100
    17 100101
    18 101000
    19 101001
    20 101010
    */

    // 87번째에서 1'000'000'000'000'000'000 넘어감
    initFibs(90);

    ll k;
    scanf("%lld", &k);
    putchar('1');
    printNumber(k);

    // for (int i = 0; i <= 100; i++)
    // {
    //     ll k = 999999999999999000ULL + i;
    //     putchar('1');
    //     printNumber(k);
    //     putchar('\n');
    // }
    return 0;
}