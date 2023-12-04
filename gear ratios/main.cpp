// day 3
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>
#include <deque>

bool is_valid(int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
        return 0;
    return 1;
}

int part_one_non_working(std::vector<std::string> data)
{
    int sum{0};
    for (int i{0}; i < data.size(); i++)
    {
        for (int j{0}; j < data[i].length(); j++)
        {
            if (std::isdigit(data[i][j]) || data[i][j] == '.')
            {
                continue;
            }
            int prev_num{0};
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {

                    if (!is_valid(i + k, j + l, data.size(), data[0].size()))
                    {
                        std::cout << i + k << std::endl;
                        std::cout << j + l << std::endl;
                        continue;
                    }
                    if (!std::isdigit(data.at(i + k).at(j + l)))
                    {
                        continue;
                    }
                    std::deque<char> num;
                    int x{-1};
                    num.push_back(data.at(i + k).at(j + l));
                    while (is_valid(i + k, (j + l) + x, data.size(), data[0].size()) && isdigit(data.at(i + k).at((j + l) + x)))
                    {
                        num.push_front(data.at(i + k).at((j + l) + x));
                        x--;
                    }
                    x = 1;
                    while (is_valid(i + k, j + l + x, data.size(), data[0].size()) && isdigit(data.at(i + k).at((j + l) + x)))
                    {
                        num.push_back(data.at(i + k).at((j + l) + x));
                        x++;
                    }
                    std::string num_string(num.begin(), num.end());
                    if (std::stoi(num_string) != prev_num)
                    {
                        sum += std::stoi(num_string);
                        // std::cout << num_string << std::endl;
                        prev_num = std::stoi(num_string);
                    }
                }
            }
        }
    }
    return sum;
}

int part_one(std::vector<std::string> data)
{
    int sum{0};
    int gear{0};
    bool is_valid_num = false;
    std::regex digit_find("\\d+");
    for (int i{0}; i < data.size(); i++)
    {
        int j{0};
        auto match_begin = std::sregex_iterator(data.at(i).begin(), data.at(i).end(), digit_find);
        auto match_end = std::sregex_iterator();
        for (std::sregex_iterator v = match_begin; v != match_end; ++v)
        {
            int pos = (*v).position();
            std::string num_as_string = (*v).str();
            for (const char &character : num_as_string)
            {

                std::vector<std::pair<int, int>> poses{
                    std::pair<int, int>{i, pos - 1},
                    std::pair<int, int>{i, pos + 1},

                    std::pair<int, int>{i - 1, pos - 1},
                    std::pair<int, int>{i - 1, pos},
                    std::pair<int, int>{i - 1, pos + 1},

                    std::pair<int, int>{i + 1, pos - 1},
                    std::pair<int, int>{i + 1, pos},
                    std::pair<int, int>{i + 1, pos + 1},

                };
                for (const std::pair<int, int> &pear : poses)
                {
                    if (!is_valid(pear.first, pear.second, data.size(), data.at(i).size()))
                    {
                        continue;
                    }
                    if (std::isdigit(data.at(pear.first).at(pear.second)) || data.at(pear.first).at(pear.second) == '.')
                    {
                        continue;
                    }
                    is_valid_num = true;
                }
                pos += 1;
            }
            if (is_valid_num)
            {
                sum += std::stoi(num_as_string);
                is_valid_num = false;
            }

            j++;
        }
    }

    return sum;
}

int part_two(std::vector<std::string> data)
{
    int sum{0};
    std::vector<int> number_per_gear;
    std::regex gear_find("\\*");
    for (int i{0}; i < data.size(); i++)
    {
        auto match_begin = std::sregex_iterator(data.at(i).begin(), data.at(i).end(), gear_find);
        auto match_end = std::sregex_iterator();
        for (std::sregex_iterator v = match_begin; v != match_end; ++v)
        {
            int pos = (*v).position();
            int prev_num{0};

            std::vector<std::pair<int, int>> poses{
                std::pair<int, int>{i, pos - 1},
                std::pair<int, int>{i, pos + 1},

                std::pair<int, int>{i - 1, pos - 1},
                std::pair<int, int>{i - 1, pos},
                std::pair<int, int>{i - 1, pos + 1},

                std::pair<int, int>{i + 1, pos - 1},
                std::pair<int, int>{i + 1, pos},
                std::pair<int, int>{i + 1, pos + 1},
            };
            for (const std::pair<int, int> &pear : poses)
            {
                if (!is_valid(pear.first, pear.second, data.size(), data.at(i).size()))
                {
                    continue;
                }
                if (std::isdigit(data.at(pear.first).at(pear.second)))
                {
                    std::deque<char> num;
                    int x{-1};
                    num.push_back(data.at(pear.first).at(pear.second));
                    while (is_valid(pear.first, pear.second + x, data.size(), data[0].size()) && isdigit(data.at(pear.first).at(pear.second + x)))
                    {
                        num.push_front(data.at(pear.first).at(pear.second + x));
                        x--;
                    }
                    x = 1;
                    while (is_valid(pear.first, pear.second + x, data.size(), data[0].size()) && isdigit(data.at(pear.first).at(pear.second + x)))
                    {
                        num.push_back(data.at(pear.first).at(pear.second + x));
                        x++;
                    }
                    std::string num_string(num.begin(), num.end());
                    if (std::stoi(num_string) != prev_num)
                    {
                        number_per_gear.push_back(std::stoi(num_string));
                        prev_num = std::stoi(num_string);
                    }
                }
            }
            if (number_per_gear.size() == 1)
            {
                number_per_gear.clear();
                continue;
            }
            int gear = 1;
            for (const int &number : number_per_gear)
            {
                gear *= number;
            }
            number_per_gear.clear();
            sum += gear;
            pos += 1;
        }
    }

    return sum;
}

int main()
{
    std::fstream file;
    std::vector<std::string> data;
    std::string line;
    file.open("test.txt", std::ios_base::in);

    while (std::getline(file, line))
    {
        data.push_back(line);
    }

    std::cout << part_one(data) << std::endl;
    std::cout << part_two(data) << std::endl;
}