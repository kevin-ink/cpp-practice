#include "Random.h"
#include <iostream>

namespace WordList
{
    std::vector<std::string_view> words{
        "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

    std::string_view
    getRandomWord()
    {
        return words[Random::get(0, words.size() - 1)];
    }
}

class Session
{
public:
    std::string_view getWord() const { return m_word; }
    bool hasGuessed(char c) const { return m_guessed[c - 'a']; }
    void setGuess(char c)
    {
        m_guessed[c - 'a'] = true;
        if (m_word.find(c) == std::string::npos)
        {
            std::cout << c << " is not in the word.\n";
            m_wrongGuesses.push_back(c);
            --m_guessesLeft;
        }
        else
        {
            bool won{true};
            for (const auto &c : m_word)
            {
                if (!m_guessed[c - 'a'])
                {
                    won = false;
                    break;
                }
            }
            m_won = won;
        }
    }
    int getGuessesLeft() const { return m_guessesLeft; }
    std::vector<char> getWrongGuesses() const { return m_wrongGuesses; }
    bool won() const { return m_won; }

private:
    std::string_view m_word{WordList::getRandomWord()};
    std::vector<bool> m_guessed{std::vector<bool>(26)};
    std::vector<char> m_wrongGuesses{std::vector<char>()};
    int m_guessesLeft{6};
    bool m_won{false};
};

void draw(Session &session)
{
    std::cout << '\n'
              << "The word: ";

    for (const auto &c : session.getWord())
    {
        if (session.hasGuessed(c))
        {
            std::cout << c;
        }
        else
        {
            std::cout << '_';
        }
    }

    std::cout << "   Wrong guesses: ";

    for (int i = 0; i < session.getGuessesLeft(); ++i)
    {
        std::cout << "+";
    }

    for (const auto &c : session.getWrongGuesses())
    {
        std::cout << c;
    }

    std::cout << '\n';
}

char getGuess(Session &session)
{
    char c{};
    while (true)
    {
        std::cout << "Enter a letter: ";
        std::cin >> c;
        if (!std::cin)
        {
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (c < 'a' || c > 'z')
        {
            std::cout << "That wasn't a lowercase letter.  Try again.\n";
            continue;
        }

        if (session.hasGuessed(c))
        {
            std::cout << "You've already guessed that. Try again.\n";
            continue;
        }

        std::cout << "You entered: " << c << '\n';

        session.setGuess(c);
        return c;
    }
}

int main()
{
    std::cout << "Welcome to C++man (a variant of Hangman)\n"
              << "To win: guess the word. To lose: run out of pluses.\n";

    Session session{};
    int wrongGuessesLeft{6};

    while (session.getGuessesLeft() > 0 && !session.won())
    {
        draw(session);
        getGuess(session);
    }

    if (session.won())
    {
        std::cout << "Congratulations! You won!\n";
    }
    else
    {
        std::cout << "Sorry, you lost. The word was: " << session.getWord() << '\n';
    }
}