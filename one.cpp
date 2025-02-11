#include <iostream>

int main() {
    int x, y;

    std::cout << "Enter an integer: ";
    std::cin >> x;
    std::cout << "Enter another integer: ";
    std::cin >> y;
    std::cout << x << " + " << y << " is " << x + y << std::endl;
    std::cout << y << " - " << x << " is " << y - x << std::endl;

    return 0;
}