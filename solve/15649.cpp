#include "iostream"
#include "cstdio"
#include "algorithm"

#define ARR_SIZE 10

using namespace std;
int nums[ARR_SIZE];
bool visited[ARR_SIZE];

void perm(int n, int m, int next)
{
    if (m == 0)
    {
        for (int i = 0; i < next; i++)
        {
            cout << nums[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        
        visited[i] = true;
        nums[next] = i;
        perm(n, m - 1, next + 1);
        visited[i] = false;
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 1부터 N까지 M개 고르기
    int n, m;
    cin >> n >> m;

    perm(n, m, 0);
    return 0;
}