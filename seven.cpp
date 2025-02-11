#include "constants.h"
#include <iostream>

int accumulate(int x);
int classSize();

int main()
{
    std::cout << accumulate(4) << '\n'; // prints 4
    std::cout << accumulate(3) << '\n'; // prints 7
    std::cout << accumulate(2) << '\n'; // prints 9
    std::cout << accumulate(1) << '\n'; // prints 10

    return 0;
}

int classSize()
{
    std::cout << "How many students are in your class? ";
    int students{};
    std::cin >> students;

    if (students > Constants::maxClassSize)
        std::cout << "There are too many students in this class";
    else
        std::cout << "This class isn't too large";

    return 0;
}

int accumulate(int x)
{
    static int sum{0};
    return sum += x;
}