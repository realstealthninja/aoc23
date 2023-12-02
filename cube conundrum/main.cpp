#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>

#define path "./input.txt"

std::regex match_str_expr("( ([\\d]*) (\\w*));?");
std::regex game_id("([0-9]+)");

/*
 * @brief part one
 */
int part_one(std::string line)
{
	int green{0};
	int blue{0};
	int red{0};
	auto match_begin = std::sregex_iterator(line.begin(), line.end(), match_str_expr);
	auto match_end = std::sregex_iterator();

	int num;
	for (std::sregex_iterator i = match_begin; i != match_end; ++i)
	{
		std::string match = (*i).str();
		num = std::stoi(match, 0, 10);
		std::string color = match.substr(match.find_last_of(" ") + 1);
		int end = color.find(";");
		if (end != std::string::npos)
		{
			color = color.replace(end, 1, "");
		}
		if (color.compare("red") == 0)
		{
			red = num;
		}
		if (color.compare("green") == 0)
		{
			green = num;
		}
		if (color.compare("blue") == 0)
		{
			blue = num;
		}
		if (red > 12 || green > 13 || blue > 14)
		{
			return 0;
		}
	}
	match_begin = std::sregex_iterator(line.begin(), line.end(), game_id);
	match_end = std::sregex_iterator();

	for (std::sregex_iterator i = match_begin; i != match_end; ++i)
	{
		std::string match = (*i).str();
		return std::stoi(match);
	}
}

int part_two(std::string line)
{
	int green{0};
	int blue{0};
	int red{0};
	auto match_begin = std::sregex_iterator(line.begin(), line.end(), match_str_expr);
	auto match_end = std::sregex_iterator();

	int num;
	for (std::sregex_iterator i = match_begin; i != match_end; ++i)
	{
		std::string match = (*i).str();
		num = std::stoi(match, 0, 10);
		std::string color = match.substr(match.find_last_of(" ") + 1);
		int end = color.find(";");
		if (end != std::string::npos)
		{
			color = color.replace(end, 1, "");
		}
		if ((color.compare("red") == 0) && (num > red))
		{
			red = num;
		}
		if ((color.compare("blue") == 0) && (num > blue))
		{
			blue = num;
		}
		if ((color.compare("green") == 0) && (num > green))
		{
			green = num;
		}
	}
	return red * blue * green;
}

int main()
{
	// inputting files.
	std::fstream file;
	file.open(path, std::ios_base::in);

	if (!file.is_open())
	{
		std::cout << "unable to open file\n";
	}
	int sum{0};
	int power{0};
	std::string line;
	while ((std::getline(file, line)))
	{
		sum += part_one(line);
		power += part_two(line);
		line = "";
	}
	std::cout << "the sum is: " << sum << std::endl;
	std::cout << "the power is: " << power << std::endl;

	file.close();
	return 0;
}
