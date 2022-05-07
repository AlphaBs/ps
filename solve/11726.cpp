#include <iostream>

int main()
{
    int input;
    std::cin >> input;

    unsigned result = 0;
    for (int a = 0; a <= input / 2; a++)
    {
        int b = input - 2 * a;
        //std::cout << a << ", " << b << std::endl;
        result += nCr(a+b, a) % 10'007;
    }

    std::cout << result % 10'007 << std::endl;
    return 0;
}