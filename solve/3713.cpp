// https://www.acmicpc.net/problem/3713

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int stdHeight[555];
bool stdMale[555];
string stdMusic[555];
string stdSport[555];

bool isMatch(int a, int b)
{
    if (stdMale[a] == stdMale[b])
        return true;
    if (abs(stdHeight[a] - stdHeight[b]) > 40)
        return true;
    if (stdMusic[a] != stdMusic[b])
        return true;
    if (stdSport[a] == stdSport[b])
        return true;
    return false;
}   

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            char curSex;
            cin >> stdHeight[i] >> curSex >> stdMusic[i] >> stdSport[i];
            stdMale[i] = curSex == 'M';
        }

        
    }

    return 0;
}