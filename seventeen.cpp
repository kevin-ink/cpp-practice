#include <iostream>
#include <vector>
#include "Random.h"

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        maxPotionTypes,
    };

    std::vector<Type> types{healing, mana, speed, invisibility};
    std::vector<int> costs{20, 30, 12, 50};
    std::vector<std::string_view> names{"healing", "mana", "speed", "invisibility"};
}

class Player
{
public:
    explicit Player(std::string_view name) : m_name{name} {}
    int gold() const { return m_gold; }
    void subtractGold(int cost) { m_gold -= cost; }
    int inventory(Potion::Type p) const { return m_inventory[p]; }
    int addPotion(Potion::Type p)
    {
        if (m_inventoryEmpty)
        {
            m_inventoryEmpty = false;
        }
        return m_inventory[p]++;
    }
    bool inventoryEmpty() const { return m_inventoryEmpty; }

private:
    std::string_view m_name{};
    std::vector<int> m_inventory{std::vector<int>(Potion::maxPotionTypes)};
    int m_gold{Random::get(s_minStartingGold, s_maxStartingGold)};
    bool m_inventoryEmpty{true};
    static constexpr int s_minStartingGold{80};
    static constexpr int s_maxStartingGold{120};
};

void shop(Player &player)
{
    std::cout << "\n"
              << "Here is our selection for today:\n";

    for (const auto &type : Potion::types)
    {
        std::cout << type << ") " << Potion::names[type] << " costs " << Potion::costs[type] << '\n';
    }

    char choice{};
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

    while (true)
    {

        std::cin >> choice;

        if (!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (!std::cin.eof() && std::cin.peek() != '\n')
        {
            std::cout << "Invalid choice. Try again: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 'q')
            return;

        int num{choice - '0'};

        if (num < 0 || num >= Potion::maxPotionTypes)
        {
            std::cout << "Invalid choice. Try again: ";
            continue;
        }

        break;
    }

    if (player.gold() < Potion::costs[choice - '0'])
    {
        std::cout << "You cannot afford that.\n";
        shop(player);
        return;
    }

    player.subtractGold(Potion::costs[choice - '0']);
    player.addPotion(Potion::types[choice - '0']);

    std::cout << "You purchased a potion of " << Potion::names[choice - '0']
              << ". You have " << player.gold() << " gold left.\n";

    shop(player);
}

int main()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n"
              << "Enter your name: ";

    std::string name{};
    std::getline(std::cin >> std::ws, name);

    Player player{name};

    std::cout << "Hello, " << name << ", you have " << player.gold() << " gold.\n";

    shop(player);

    if (player.inventoryEmpty())
    {
        std::cout << "\nYou didn't buy anything.\n\n";
    }
    else
    {
        std::cout << "\nYour inventory contains:\n";

        for (const auto &type : Potion::types)
        {
            if (player.inventory(type) > 0)
            {
                std::cout << player.inventory(type) << "x potion of " << Potion::names[type] << '\n';
            }
        }
    }

    std::cout << "You escaped with " << player.gold() << " gold remaining.\n"
              << "\nThanks for shopping at Roscoe's potion emporium!\n";

    return 0;
}