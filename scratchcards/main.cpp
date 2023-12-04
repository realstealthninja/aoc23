#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <cstring>

std::regex winning_number(": +([\\d ]+) ");
std::regex given_number("\\| +([ \\d]+)");

int part_one(std::string card)
{
    int points{0};
    std::smatch win_number_match;
    std::regex_search(card, win_number_match, winning_number);
    std::smatch given_number_match;
    std::regex_search(card, given_number_match, given_number);

    std::vector<int> winning_numbers;
    std::vector<int> given_numbers;

    std::string delimiter = " ";
    size_t position = 0;

    std::string win_number_str = win_number_match[1].str();
    std::string given_number_str = given_number_match[1].str();
    while ((position = win_number_str.find(delimiter)) != std::string::npos)
    {
        if (std::atoi(win_number_str.substr(0, position).c_str()) != 0)
        {
            winning_numbers.push_back(std::atoi(win_number_str.substr(0, position).c_str()));
        }
        win_number_str.erase(0, position + delimiter.length());
    }
    winning_numbers.push_back(std::atoi(win_number_str.c_str()));
    position = 0;
    while ((position = given_number_str.find(delimiter)) != std::string::npos)
    {
        if (std::atoi(given_number_str.substr(0, position).c_str()) != 0)
        {
            given_numbers.push_back(std::atoi(given_number_str.substr(0, position).c_str()));
        }
        given_number_str.erase(0, position + delimiter.length());
    }
    given_numbers.push_back(std::atoi(given_number_str.c_str()));

    for (const int &number : given_numbers)
    {
        for (const int &win_num : winning_numbers)
        {
            if (number == win_num)
            {
                if (points == 0)
                {
                    points++;
                    break;
                }
                points += points;
                break;
            }
        }
    }
    return points;
}

int main()
{
    std::string path = "input.txt";
    std::fstream file;
    file.open(path, std::ios_base::in);

    int sum{0};
    std::string card;

    while ((std::getline(file, card)))
    {
        sum += part_one(card);
    }
    std::cout << sum << std::endl;

    return 0;
}
