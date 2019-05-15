#pragma once
#include <boost/filesystem.hpp>


namespace BoostIfStreamText
{
	int main()
	{
		// Run the boost_ofstream_text.h snippet so you will have that file
		boost::filesystem::ifstream in("./ofstream_demo.txt");
		if (in.is_open())
		{
			char buffer[1024];
			std::string line;

			while (std::getline(in, line))
				std::cout << line << std::endl;
		}
		else
		{
			std::cout << "Could not open the file, have did you run boost_ofstream_text.h snippet?\n";
		}
		return 0;
	}
}
