#include <iostream>

using Degree = double;
using Radian = double;

namespace constants
{
    constexpr double pi{3.14159};
}

double convertToRadians(double degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degree degrees{};
    std::cin >> degrees;

    Radian radians{convertToRadians(degrees)};
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}