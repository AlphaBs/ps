// https://www.acmicpc.net/problem/10072

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool printDebug = false;
unordered_set<int> dup;

int n;
int arr[111'111];

// 교체된 번호는 n보다 커야함 (초과)
bool isReplacedItem(int num)
{
    return num > n;
}

int findStartPos()
{
    int minValue = arr[0];
    int minIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minValue)
        {
            minValue = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}

bool valid()
{
    for (int i = 0; i < n; i++)
    {
        if (dup.find(arr[i]) == dup.end())
            dup.insert(arr[i]);
        else
            return false;
    }

    // 시작지점은 가장 작은 수의 위치가 될거임
    int startPos = findStartPos();

    for (int i = 0; i < n; i++)
    {
        int currPos = (startPos + i) % n;
        bool isCurrReplaced = isReplacedItem(arr[currPos]);

        // 정상이면 원래 자리가 맞는지 확인필요함
        if (!isCurrReplaced)
        {
            // 정상 자리수
            int expectNum = arr[startPos] + i;

            if (expectNum != arr[currPos])
            {
                if (printDebug) cout << "expect " << expectNum << ", but actual " << arr[currPos] << endl;
                return false;
            }
        }

        // 마지막꺼는 다음꺼를 확인할 필요가 없음
        if (i == n - 1)
            break;

        int nextPos = (currPos + 1) % n;
        bool isNextReplaced = isReplacedItem(arr[nextPos]);

        // 변화 없음 -> 잘못된 수열
        if (arr[currPos] == arr[nextPos])
        {
            if (printDebug) cout << "same number " << currPos << endl;
            return false;
        }
        
        // 작아지는거
        if (arr[currPos] > arr[nextPos])
        {
            // 둘다 교체되었던거
            if (isCurrReplaced && isNextReplaced)
                continue;
            // 교체된거였는데 정상으로 돌아옴
            if (isCurrReplaced && !isNextReplaced)
                continue;
            // 정상에서 정상인데 줄어드는건 불가능함
            if (!isCurrReplaced && !isNextReplaced)
            {
                if (printDebug) cout << "decreased in wrong place " << currPos << endl;
                return false;
            }
        }

        // 커지는거
        if (arr[currPos] < arr[nextPos])
        {
            // 얼마나 커졌냐
            int step = arr[nextPos] - arr[currPos];

            // 둘다 정상이였다면 -> 1씩만 커져야함
            if (!isCurrReplaced && !isNextReplaced)
            {
                if (step == 1)
                    continue;
                else
                {
                    if (printDebug) cout << "expect 1 increasement " << currPos << endl;
                    return false;
                }
            }

            // 교체 -> 정상
            // 정상 -> 교체
            // 교체 -> 교체
            continue;
        }        
    }

    return true;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << (valid() ? 1 : 0);
    return 0;
}