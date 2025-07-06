// https://www.acmicpc.net/problem/3713

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int stdHeight[555];
bool stdMale[555];
int stdMusic[555];
int stdSport[555];

unordered_map<string, int> musicMap;
unordered_map<string, int> sportMap;

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
            string curMusic;
            string curSport;
            cin >> stdHeight[i] >> curSex >> curMusic >> curSport;

            // 성별
            stdMale[i] = curSex == 'M';

            // 음악장르
            auto& musicIdPos = musicMap.find(curMusic);
            if (musicIdPos == musicMap.end())
            {
                int nextId = musicMap.size();
                musicMap.insert({curMusic, nextId});
                stdMusic[i] = nextId;
            }
            else
            {
                stdMusic[i] = (*musicIdPos).second;
            }

            // 스포츠
            auto& sportIdPos = sportMap.find(curSport);
            if (sportIdPos == sportMap.end())
            {
                int nextId = sportMap.size();
                sportMap.insert({curSport, nextId});
                stdSport[i] = nextId;
            }
            else
            {
                stdSport[i] = (*sportIdPos).second;
            }
        }

        
    }

    return 0;
}