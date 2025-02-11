#include <iostream>

int main()
{
    double towerHeight;
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> towerHeight;

    for (int i = 0; i <= 5; i++)
    {
        double distanceFallen = towerHeight - 9.8 * i * i / 2;

        if (distanceFallen <= 0)
        {
            std::cout << "At " << i << " seconds, the ball is on the ground.\n";
            break;
        }

        std::cout << "At " << i << " seconds, the ball is at height: " << distanceFallen << " meters\n";
    }

    return 0;
}
