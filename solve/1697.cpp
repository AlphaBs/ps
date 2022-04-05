#include <iostream>
#include <vector>
#include <queue>

bool visited[100001];

bool isVisited(int value)
{
    //return false;
    return visited[value];
}

int main()
{
    int from, to;
    std::cin >> from >> to;

    int time = 0;

    std::queue<int> q;

    visited[from] = true;
    q.push(from);
    q.push(-1);

    while (q.size())
    {
        from = q.front();
        q.pop();

        if (from == -1)
        {
            q.push(-1);
            time++;
            //std::cout << "======" << time << std::endl;
            continue;
        }

        //std::cout << from << std::endl;

        if (from == to)
            break;

        visited[from] = true;

        int doubled = from * 2;
        int front = from + 1;
        int back = from - 1;

        if (doubled <= to + 2 && !isVisited(doubled))
            q.push(doubled);
        if (front <= to && !isVisited(front))
            q.push(front);
        if (back >= 0 && !isVisited(back))
            q.push(back);
    }

    std::cout << time << std::endl;

    return 0;
}