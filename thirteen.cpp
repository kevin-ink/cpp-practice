#include <iostream>

enum MonsterType
{
    Ogre,
    Dragon,
    Orc,
    GiantSpider,
    Slime
};

struct Monster
{
    MonsterType type;
    std::string name;
    int health;
};

void printMonster(Monster m)
{
    std::string type{};
    switch (m.type)
    {
    case Ogre:
        type = "Ogre";
        break;
    case Dragon:
        type = "Dragon";
        break;
    case Orc:
        type = "Orc";
        break;
    case GiantSpider:
        type = "Giant Spider";
        break;
    case Slime:
        type = "Slime";
        break;
    }

    std::cout << "This " << type << " is named " << m.name << " and has " << m.health << " health.\n";
}

template <typename T>
struct Triad
{
    T first;
    T second;
    T third;
};

template <typename T>
void print(const Triad<T> &t)
{
    std::cout << '[' << t.first << ", " << t.second << ", " << t.third << ']';
}

template <typename T>
Triad(T, T, T) -> Triad<T>;

int main()
{
    Monster torg{Ogre, "Torg", 145};
    Monster blurp{Slime, "Blurp", 23};
    printMonster(torg);
    printMonster(blurp);
}
