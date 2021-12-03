#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <bitset>


int main(int argc, char const *argv[])
{
	std::ifstream input_file("./data/input03.txt");
	std::vector<std::string> data;
	std::string line;
	while(input_file)
	{
		input_file >> line;
		data.push_back(line);
	}

	const int line_size = line.size();
	std::vector<int> bit_counter(line_size, 0);
	for(const auto& line : data)
	{
		for(int i = 0; i < line_size; ++i)
		{
			bit_counter[i] += (line[i] == '1');
		}
	}
	
	int gamma = 0;
	int epsilon = 0;

	for(int i = 0; i < line_size; ++i)
	{
		const int ones = bit_counter[i];
		const int zeros = data.size() - ones;

		const bool is_one = ones >= zeros;
		gamma <<= 1;
		gamma |= is_one;

		epsilon <<= 1;
		epsilon |= !is_one;
	}

	std::cout << "Solution: " << gamma * epsilon << std::endl;


	return 0;
}
