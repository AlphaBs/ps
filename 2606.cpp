#include <iostream>
#include <vector>
#include <queue>

std::vector<int> graph[101];
bool visited[101];

int main()
{
    int verteces, edges;
    std::cin >> verteces >> edges;

    while (edges--)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int result = 0;

    std::queue<int> q;
    q.push(1);
    visited[1] = true;

    while (q.size())
    {
        int v = q.front();
        q.pop();

        for (int i : graph[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }

        result++;
    }

    std::cout << result - 1 << std::endl;
    return 0;
}