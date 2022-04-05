#include <iostream>

int plus(int a, int b)
{
    return a + b;
}

double plus(double a, double b)
{
    return a + b;
}

int main()
{
    int num;
    std::cout << "Hello, World!" << std::endl;
    std::cin >> num;

    int result = plus(num, 10);
    std::cout << "The result is " << result;
    return 0;
}