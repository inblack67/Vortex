#include <iostream>
#include <sstream>
#include <fstream>

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		std::cerr << "Wrong choice my friend." << std::endl;
		std::cerr << "./vtx <input.vtx>" << std::endl;
		return EXIT_FAILURE;
	}

	std::string file_name = argv[0];

	std::stringstream ss;

	std::ifstream file(file_name);
	if (!file.is_open())
	{
		std::cerr << "Error opening the file " << file_name << std::endl;
		return 1;
	}

	std::string contents;
	{
		std::fstream input(argv[1], std::ios::in);
		std::stringstream contents_stream;
		contents_stream << input.rdbuf();
		contents = contents_stream.str();
	}

	return EXIT_SUCCESS;
}
