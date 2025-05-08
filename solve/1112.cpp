// https://www.acmicpc.net/problem/1112

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

#define ll long long

using namespace std;

bool printDigit = false;

// a ^ b
ll power(ll a, ll b)
{
    ll n = 1;
    for (ll i = 0; i < b; i++)
    {
        n = n * a;
    }
    return n;
}

// b 진수에서, position 번째 숫자가 digit 일 때, 가능한 최대 최소 범위
pair<ll, ll> findRange(ll b, ll position, ll digit)
{
    ll rangeMax = 0;
    ll rangeMin = 0;
    if (b >= 0)
    {
        ll n = 1; // n = b^i
        for (int i = 0; i < position; i++)
        {
            ll s = abs(n * (abs(b) - 1));
            rangeMax += s;
            rangeMin -= s;
            n *= b;
        }
        rangeMax += n * digit;
        rangeMin += n * digit;
    }
    else
    {
        ll n = 1; // n = b^i
        for (int i = 0; i < position; i++)
        {
            ll s = abs(n * (abs(b) - 1));
            if (i % 2 == 0)
            {
                rangeMax += s;
            }
            else
            {
                rangeMin -= s;
            }
            n *= b;
        }
        rangeMax += n * digit;
        rangeMin += n * digit;
    }
    return {rangeMax, rangeMin};
}

// 십진수 x를 b진법으로 바꾸어 출력
void calc(ll x, ll b, ll pos)
{
    if (pos < 0)
        return;

    for (int i = (1 - abs(b)); i < abs(b); i++)
    {
        pair<ll, ll> range = findRange(b, pos, i);
        if (range.first >= x && range.second <= x)
        {
            if (i != 0)
                printDigit = true;
            if (printDigit)
                cout << i;
            calc(x - power(b, pos) * i, b, pos - 1);
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x, b;
    cin >> x >> b;

    int pos = 0;
    while (true)
    {
        pair<ll, ll> range = findRange(b, pos, 0);
        if (range.first >= x && range.second <= x)
        {
            break;
        }
        pos++;
    }
    pos--;

    if (b >= 0 && x < 0)
    {
        cout << '-';
        calc(-x, b, pos);
    }
    else
        calc(x, b, pos);

    if (!printDigit)
        cout << 0;
    return 0;
}