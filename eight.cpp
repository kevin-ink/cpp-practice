#undef NDEBUG // Make sure that assert triggers even if we compile in release mode
#include <iostream>
#include "Random.h"
#include <cassert> // for assert

bool isPrime(int x)
{
    if (x <= 1)
    {
        return false;
    }

    for (int i{2}; i < x; ++i)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int assertPrime()
{
    assert(!isPrime(0)); // terminate program if isPrime(0) is true
    assert(!isPrime(1));
    assert(isPrime(2)); // terminate program if isPrime(2) is false
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}

void PlayHiLo()
{

    const int randomNumber = Random::get(1, 100);
    int min{1};
    int max{100};
    int maxGuesses{7};

    std::cout << "Let's play HiLo!\n";
    std::cout << "Minimum value (default = 1): ";
    std::cin >> min;
    std::cout << "Maximum value (default = 100): ";
    std::cin >> max;
    std::cout << "Max attempts (default = 7): ";
    std::cin >> maxGuesses;
    std::cout << "I'm thinking of a number between " << min << " and " << max
              << ". You have " << maxGuesses << " tries to guess what it is\n";

    for (int i{0}; i <= maxGuesses; ++i)
    {
        std::cout << "Guess #" << i << ": ";
        int guess{};
        std::cin >> guess;

        if (guess == randomNumber)
        {
            std::cout << "Correct! You win!\n";
            return;
        }
        else if (guess < randomNumber)
        {
            std::cout << "Your guess is too low.\n";
        }
        else
        {
            std::cout << "Your guess is too high.\n";
        }
    }
    std::cout << "Sorry, you lose. The correct number was " << randomNumber << '\n';
}

int main()
{
    while (true)
    {
        PlayHiLo();

        std::cout << "Would you like to try again? (y/n): ";
        char playAgain{};
        std::cin >> playAgain;

        while (playAgain != 'y' && playAgain != 'n')
        {
            std::cout << "Would you like to try again? (y/n): ";
            std::cin >> playAgain;
        }

        if (playAgain == 'n')
            break;
    }
}