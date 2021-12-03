#include <string>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char const *argv[])
{
	const char * sample_file = "./data/sample01.txt";
	const char * input_file = "./data/input01.txt";

	const char* filename = argc > 1 ? argv[1] : input_file;
	int sol = 0;

	std::ifstream input = std::ifstream(filename);
	std::vector<int> data;
	while(input)
	{
		int d;
		input >> d;
		data.push_back(d);
	}

	std::cout << "Read " << data.size() << " numbers" << std::endl;

	std::vector<int> sums;
	int usable_data = 3* (data.size()/3);

	for(int i = 0; i < usable_data; ++i)
	{
		int sum = data[i + 0]
				+ data[i + 1]
				+ data[i + 2];

		sums.push_back(sum);
	}

	for(int i = 1; i < sums.size(); ++i)
	{
		std::cout << sums[i] << " ";
		const int prev = sums[i-1];
		const int curr = sums[i];

		if(prev < curr)
		{
			std::cout << "increased" << std::endl;
			sol++;
		}
		else if(prev > curr)
		{
			std::cout << "decreased" << std::endl;
		}
		else 
		{
			std::cout << "same" << std::endl;
		}
	}

	std::cout << "Solution: " << sol << std::endl;
	return 0;
}
