#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    unordered_map<string, string> map;

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
    {
        string site;
        cin >> site;
        cin >> map[site];
    }

    for (int i = 0; i < b; i++)
    {
        string site;
        cin >> site;
        cout << map[site] << '\n';
    }

    return 0;
}