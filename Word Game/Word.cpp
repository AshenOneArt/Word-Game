#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


bool IsInFiveWord(std::vector<std::string>& five_word,std::string& word)
{
	for (const auto w : five_word)
	{
		if (w == word)
		{
			return true;
		}
	}
	return false;
}


int main()
{
	enum EqualTargetStr
	{
		None = 0,
		one = 1,
		two = 2,
		three = 3,
		four = 4,
		five = 5
	};
	EqualTargetStr targetStrNum = None;
	
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
	//const std::string Target = five_word[dist(rng)];
	const std::string Target = five_word[dist(rng)];

	while (true)
	{
		static int times;
		static bool Matching = false;
		std::string input;
		std::stringstream StrStream;
		

		
		if (times == 0)
		{
			std::cout << "Just guess five word letter\n" << std::endl;
		}
		else
		{
			std::cout << "Please guess five word letter again, motherfucker and thank you\n" << std::endl;
		}
		std::getline(std::cin, input);
		std::cout << "\n";
		times++;
		if (input.size() != 5)
		{
			std::cout << "I have told you FIVE word , Asshole, wanna me to kick your ass?\n" << std::endl;
			continue;
		}
		if (!IsInFiveWord(five_word, input))
		{
			std::cout << "this motherfucking shit isn't even a word...... what hell you think about? Dude?\n" << std::endl;
			continue;
		}
		for (int i=0;i< input.length();i++)
		{
			if (Target[i] == input[i])
			{
				Matching = true;
				targetStrNum = EqualTargetStr(i+1);
				{
					StrStream << "|";
					switch (targetStrNum)
					{
					case one:
						StrStream << "first";
						break;
					case two:
						StrStream << "second";
						break;
					case three:
						StrStream << "third";
						break;
					case four:
						StrStream << "fourthly";
						break;
					case five:
						StrStream << "fivthly";
						break;
					default:
						
						break;
					}
				}
			}

			
		}
		if (Matching)
		{
			std::cout << "The " << StrStream.str().c_str() << "| letter is right,keep going my man\n" << std::endl;
		}
		else
		{
			std::cout << StrStream.str().c_str() << "To be honest,glad you make a word Finally,but not this word,keep try,bro\n" << std::endl;
		}
		
		
	}
	
	
	
	std::cin.get();
	return 0;
}