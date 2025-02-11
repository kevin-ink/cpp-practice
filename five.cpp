#include <iostream>

int main()
{
    std::string name1{}, name2{};
    int age{}, age2{};
    std::cout << "Enter the name of person #1: ";
    std::getline(std::cin >> std::ws, name1);
    std::cout << "Enter the age of " << name1 << ": ";
    std::cin >> age;
    std::cout << "Enter the name of person #2: ";
    std::getline(std::cin >> std::ws, name2);
    std::cout << "Enter the age of " << name2 << ": ";
    std::cin >> age2;

    if (age > age2)
    {
        std::cout << name1 << " (" << age << ") is older than " << name2 << " (" << age2 << ")\n";
    }
    else
    {
        std::cout << name2 << " (" << age2 << ") is older than " << name1 << " (" << age << ")\n";
    }

    return 0;
}