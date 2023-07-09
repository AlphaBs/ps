// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int members, parties;
int party[55][55];
bool checkedMembers[55];
bool realParties[55];

bool isExists(int partyNumber, int member)
{
    return party[partyNumber][member];
}

void setExists(int partyNumber, int member)
{
    party[partyNumber][member] = 1;
}

int getPartyMembers(int partyNumber)
{
    return party[partyNumber][0];
}

void setPartyMembers(int partyNumber, int members)
{
    party[partyNumber][0] = members;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;

    int knows;
    cin >> members >> parties >> knows;
    for (int i = 0; i < knows; i++)
    {
        int member;
        cin >> member;
        q.push(member);
        checkedMembers[member] = true;
    }
    for (int partyNumber = 0; partyNumber < parties; partyNumber++)
    {
        int partyMembers;
        cin >> partyMembers;
        setPartyMembers(partyNumber, partyMembers);

        for (int j = 0; j < partyMembers; j++)
        {
            int memberNumber;
            cin >> memberNumber;
            setExists(partyNumber, memberNumber);
        }
    }

    while (!q.empty())
    {
        int member = q.front();
        //cout << member << " poped\n";
        q.pop();
        for (int partyNumber = 0; partyNumber < parties; partyNumber++)
        {
            if (isExists(partyNumber, member)) // get party number of member
            {
                realParties[partyNumber] = true;
                for (int partyMember = 1; partyMember <= members; partyMember++)
                {
                    // push all members of party
                    if (!checkedMembers[partyMember] && isExists(partyNumber, partyMember))
                    {
                        //cout << "push " << partyMember << "\n";
                        checkedMembers[partyMember] = true;
                        q.push(partyMember);
                    }
                }
            }
        }
    }

    int fakedPartyCount = 0;
    for (int i = 0; i < parties; i++)
    {
        //cout << i << ":" << (realParties[i] ? "real" : "faked") << "\n";
        if (!realParties[i])
            fakedPartyCount++;
    }
    cout << fakedPartyCount;

    return 0;
}