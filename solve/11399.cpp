#include <iostream>
#include <algorithm>

int main()
{
    int n;
    std::cin >> n;

    int*arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + n);

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += (n - i) * arr[i];
    }

    std::cout << result << std::endl;
    delete [] arr;
    return 0;
}