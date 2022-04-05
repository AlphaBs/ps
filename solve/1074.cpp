#include <iostream>
#include <cmath>

// 1 2 3 4 Z순서대로 사분면
int search(int nn, int r, int c)
{
    if (r <= nn / 2 && c <= nn / 2)
        return 1;
    if (r <= nn / 2 && c > nn / 2)
        return 2;
    if (r > nn / 2 && c <= nn / 2)
        return 3;
    if (r > nn / 2 && c > nn / 2)
        return 4;

    return 0;
}

int main()
{
    int n, r, c, result = 0;
    std::cin >> n >> r >> c;
    r++;
    c++;

    int nn = pow(2, n);
    while (true)
    {
        int part = search(nn, r, c);
        //std::cout << part << std::endl;
        result += (part - 1) * (nn * nn / 4);
        nn = nn / 2;
        
        if (nn == 1)
            break;

        if (part == 2)
            c -= nn;
        else if (part == 3)
            r -= nn;
        else if (part == 4)
        {
            c -= nn;
            r -= nn;
        }
    }

    std::cout << result << std::endl;
    return 0;
}
