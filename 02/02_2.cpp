#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <fmt/format.h>

int main(int argc, char const *argv[])
{
	const char* sample_file = "./data/sample02.txt";
	const char* input_file  = "./data/input02.txt";
	std::ifstream file(input_file);
	
	int pos   = 0;
	int depth = 0;
	int aim   = 0;

	std::string command;
	int value;

	while(!file.eof())
	{
		file >> command >> value;
		switch (command[0])
		{
		case 'f': //forward
			pos += value;
			depth += aim * value;
			break;
		case 'd': //down
			aim += value;
			break;
		case 'u': //up
			aim -= value;
			break;
		default:
			break;
		}
	}
	file.close();
	const int solution = pos * depth;
	fmt::print("Solution {}\n", solution);
	return 0;
}
