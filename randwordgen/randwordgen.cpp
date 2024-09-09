// randwordgen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>
#include <stdexcept>
#include <vector>
#include <functional>
#include <ctime>
#include <cstdlib>

std::array<std::string, 5> Patterns =
{
    "vcv",
    "cvvc",
    "cv",
    "vc",
    "ccv"
};

std::array<std::string, 10> Source =
{

};

std::array<char, 7> Vow = { "aeiouy" };
std::array<char, 21> Con = { "bcdfghjklmnpqrstvwxz" };

using call_pool = std::vector <std::function<char()>>;


char ranvow()
{
    int idx = rand () % (Vow.size() - 2);
    return Vow[idx];
}

char rancon()
{
    int idx = rand () % (Vow.size() - 2);
    return Con[idx];
}

call_pool parse_pattern(std::string pattern)
{
    call_pool pool;
    for (char c : pattern)
    {
        if (c == 'v')
        {
            pool.push_back(ranvow);
        }
        else if (c == 'c')
        {
            pool.push_back(rancon);
        }
        else
            throw std::runtime_error("A pattern must only consist of 'v' and 'c'");
    }
    return pool;
}

std::string make_word()
{
    std::string word;
    for (int i = 0; i < 2 + rand() % 3; i++)
    {
        call_pool pool = parse_pattern(Patterns[rand() % (Patterns.size() - 1)]);
        for (auto func : pool)
        {
            word += func();
        }
    }
    return word;
}

char mutvow(char c)
{
    char nc = c;
    while (nc == c)
    {
        int idx = rand () % (Vow.size() - 2);
        nc = Vow[idx];
    }
    return nc;
}

char mutcon(char c)
{
    char nc = c;
    while (nc == c)
    {
        int idx = rand () % (Con.size() - 2);
        nc = Con[idx];
    }
    return nc;
}

char mutchar(char c)
{
    for (char ic : Vow)
    {
        if (ic == c)
        {
            return mutvow(c);
        }
    }
    return mutcon(c);
}

void mutate(int steps)
{
    for (auto str : Source)
    {
        std::cout << str << '\n';
        for (int i = 0; i < steps; i++)
        {
            std::cout << "=> ";
            for (char c : str)
            {
                if (rand() % 8 == 0)
                {
                    std::cout << mutchar(c);
                }
                else std::cout << c;
            }
            std::cout << '\n';
        }
    }
}

int main()
{
    srand(time(NULL));
    int seed = rand();
    std::string word;
    for (int i = 0; i < 10; i++)
    {
        Source[i] = make_word();
    }
    mutate(10);
}

