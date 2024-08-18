// Hi-Lo Game Written by Selcuk Yuksel

#include "Random.h" // for Random::getInteger()
#include <limits> // for std::numeric_limits, std::streamsize
#include <iostream> // for std::cout, std::cin

namespace Config
{
    constexpr int guessCount {7};
    constexpr int rangeMin   {1};
    constexpr int rangeMax   {100};
}

// Input error handling functions

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool hasUnextractedInput()
{
    return !std::cin.eof() && std::cin.peek() != '\n';
}

// *************************************************** //

int getUserGuess(int guessNumber)
{
    while (true)
    {
        std::cout << "Guess #" << guessNumber << ": ";
        int guess {};
        std::cin >> guess;

        if (!std::cin || hasUnextractedInput())
        {
            std::cin.clear();
            ignoreLine();
            std::cout << "You have to enter a valid number.\n";
            continue;
        }

        if (guess < Config::rangeMin || guess > Config::rangeMax)
        {
            std::cout << "You have to enter in range of " << Config::rangeMin << " to " << Config::rangeMax << ".\n";
            continue;
        }

        return guess;
    }
}

char getUserChoice()
{
    while (true)
    {
        std::cout << "Would you like to play again (y\\n): ";
        char choice {};
        std::cin >> choice;

        if (hasUnextractedInput())
        {
            ignoreLine();
        }

        switch (choice)
        {
        case 'y':
        case 'n':
            return choice;
        }

        std::cout << "You have to enter a valid choice.\n";
    }
}

void playHiLo()
{
    const int randomNumber {Random::getInteger(Config::rangeMin, Config::rangeMax)};

    std::cout << "I picked a number between " << Config::rangeMin << " - " << Config::rangeMax
            << " you have " << Config::guessCount << " tries to find the number.\n";

    for (int tryCount {1}; tryCount <= Config::guessCount; ++tryCount)
    {
        int guess {getUserGuess(tryCount)};

        if (guess < randomNumber)
        {
            std::cout << "Too low!\n";
        }
        else if (guess > randomNumber)
        {
            std::cout << "Too high!\n";
        }
        else
        {
            std::cout << "CORRECT! You win. :D\n";
            return;
        }
    }

    std::cout << "Sorry, you lose. :( The correct number was " << randomNumber << ".\n";
}

int main()
{
    while (true)
    {
        playHiLo();

        if (getUserChoice() == 'n')
        {
            std::cout << "\nThank you for playing. :)\n";
            break;
        }

        std::cout << '\n';
    }

    return 0;
}
