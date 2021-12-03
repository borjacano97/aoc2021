#include<string>
#include<iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
	const char * sample_file = "./data/sample01.txt";
	const char * input_file = "./data/input01.txt";

	const char* filename = argc > 1 ? argv[1] : input_file;

	std::ifstream input = std::ifstream(filename);
	int lastValue;
	input >> lastValue;

	int sol = 0;
	while(input)
	{
		int value;
		input >> value;
		if(lastValue < value)
			sol++;
		lastValue = value;
	}
	input.close();

	std::cout << "Solution: " << sol << std::endl;
	return 0;
}
