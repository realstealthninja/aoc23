// day 3
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <deque>
bool is_valid(int i, int j, int n, int m)
{
    if (i < 0 || j < 0 || i > n - 1 || j > m - 1)
        return 0;
    return 1;
}

int part_one(std::vector<std::string> data)
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

int main()
{
    std::fstream file;
    std::vector<std::string> data;
    std::string line;
    file.open("input.txt", std::ios_base::in);

    while (std::getline(file, line))
    {
        data.push_back(line);
    }

    std::cout << part_one(data) << std::endl;
}