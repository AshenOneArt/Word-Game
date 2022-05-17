#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
int main()
{
	std::vector<std::string> five_word;
	{
		std::ifstream streamIn("five_word.txt");
		for (std::string line; std::getline(streamIn, line); )
		{
			if (line.empty())
			{
				continue;
			}
			five_word.push_back(line);
		}
	}
	
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(0, five_word.size() - 1);
	const std::string Target = five_word[dist(rng)];

	std::string input;
	std::cout << "Just guess five word letter" << std::endl;
	std::getline(std::cin, input);
	if (input.size() != 5)
	{
		std::cout << "I told you FIVE word , Asshole" << std::endl;
	}
	
	std::cin.get();
	return 0;
}