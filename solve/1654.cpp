#include "iostream"
#include "cstdio"
#include "algorithm"

using namespace std;

unsigned long wires[10'001];
int k;
int n;

unsigned long long calculateWires(unsigned cut)
{
    unsigned long long count = 0;
    for (int i = 0; i < k; i++)
    {
        count += wires[i] / cut;
    }
    return count;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> k >> n;
    unsigned longestWire = 0;

    for (int i = 0; i < k; i++)
    {
        cin >> wires[i];
        if (wires[i] > longestWire)
            longestWire = wires[i];
    }

    unsigned left = 1;
    unsigned right = longestWire;
    unsigned mid;
    while (left <= right)
    {
        // mid를 높일수록 랜선의 갯수가 감소
        // mid를 낮힐수록 랜선의 갯수가 증가
        mid = (left + right) / 2;
        unsigned long long count = calculateWires(mid);

        if (n <= count) // 더많이생기거나 일치
        {
            longestWire = mid;
            left = mid + 1;
        }
        else if (n > count) // 모자람
            right = mid - 1;
    }

    cout << longestWire;

    return 0;
}