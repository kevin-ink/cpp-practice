#include <iostream>
#include "Random.h"

class Monster
{
public:
    enum Type
    {
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes
    };

    Monster(Type type, std::string_view name, std::string_view roar, int hp)
        : m_type{type}, m_name{name}, m_roar{roar}, m_hp{hp}
    {
    }

    constexpr std::string_view getTypeString() const
    {
        switch (m_type)
        {
        case dragon:
            return "dragon";
        case goblin:
            return "goblin";
        case ogre:
            return "ogre";
        case orc:
            return "orc";
        case skeleton:
            return "skeleton";
        case troll:
            return "troll";
        case vampire:
            return "vampire";
        case zombie:
            return "zombie";
        default:
            return "???";
        }
    }

    void print() const
    {
        if (m_hp <= 0)
        {
            std::cout << m_name << " the " << getTypeString() << " is dead.\n";
            return;
        }
        std::cout << m_name << " the " << getTypeString() << " has " << m_hp << " hit points and says " << m_roar << '.' << '\n';
    }

private:
    Type m_type;
    std::string m_name;
    std::string m_roar;
    int m_hp;
};

namespace MonsterGenerator
{
    std::string_view getName(int x)
    {
        switch (x)
        {
        case 0:
            return "Anakin";
        case 1:
            return "Sharky";
        case 2:
            return "Seethe";
        case 3:
            return "Elva";
        case 4:
            return "Grim";
        case 5:
            return "Spike";
        default:
            return "???";
        }
    }

    std::string_view getRoar(int x)
    {
        switch (x)
        {
        case 0:
            return "rawrrrrr";
        case 1:
            return "meowwwww";
        case 2:
            return "ahhhhhhh";
        case 3:
            return "eeeeeeeeee";
        case 4:
            return "uwuwuwuuwuwuwuwu";
        case 5:
            return "sssssssssssssssss";
        default:
            return "???";
        }
    }

    Monster generate()
    {
        return Monster(static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)), getName(Random::get(0, 5)), getRoar(Random::get(0, 5)), Random::get(1, 100));
    }
}

int main()
{
    Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};
    skeleton.print();

    Monster vampire{Monster::vampire, "Nibblez", "*hiss*", 0};
    vampire.print();

    Monster m{MonsterGenerator::generate()};
    m.print();

    return 0;
}