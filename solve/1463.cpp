#include <iostream>
#include <queue>

bool visited[1'000'000];

int main()
{
    int input, result = 0;
    std::cin >> input;

    std::queue<int> q;

    q.push(input);
    q.push(-1);
    while (q.size())
    {
        input = q.front();
        q.pop();

        if (input == -1)
        {
            result++;
            q.push(-1);
            continue;
        }

        if (input == 1)
            break;

        int temp;
        if (input % 3 == 0)
        {
            temp = input / 3;
            if (!visited[temp])
                q.push(temp);
        }
        if (input % 2 == 0)
        {
            temp = input / 2;
            if (!visited[temp])
                q.push(temp);
        }
        temp = input - 1;
        if (temp > 0 && !visited[temp])
            q.push(temp);
    }

    std::cout << result << std::endl;
    return 0;
}