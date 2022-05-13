#include "iostream"
#include "cstdio"
#include "algorithm"

using namespace std;
bool map[2187][2187]; // 3**7 = 2187

void draw(int x, int y, int n)
{
    if (n == 1)
    {
        map[y][x] = true;
        return;
    }

    int next = n / 3;
    draw(x + next * 0, y + next * 0, next);
    draw(x + next * 1, y + next * 0, next);
    draw(x + next * 2, y + next * 0, next);
    draw(x + next * 0, y + next * 1, next);
    draw(x + next * 2, y + next * 1, next);
    draw(x + next * 0, y + next * 2, next);
    draw(x + next * 1, y + next * 2, next);
    draw(x + next * 2, y + next * 2, next);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    draw(0, 0, n);

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (map[y][x])
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }

    return 0;
}