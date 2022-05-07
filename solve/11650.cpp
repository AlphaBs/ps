#include "iostream"
#include "cstdio"
#include "algorithm"

using namespace std;

struct Location
{
    int x, y;
};

Location locations[100'000];

bool comp(const Location& a, const Location& b)
{
    if (a.x == b.x)
        return (a.y - b.y) < 0;

    return (a.x - b.x) < 0;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> locations[i].x;
        cin >> locations[i].y;
    }

    sort(locations, locations + n, comp);

    for (int i = 0; i < n; i++)
    {
        cout << locations[i].x << " " << locations[i].y << "\n";
    }

    return 0;
}