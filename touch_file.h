#pragma once

#include <boost/filesystem.hpp>
#include <iostream>

namespace TouchFile
{
	int main()
	{
		// One liner:
		// boost::filesystem::ofstream f("D:/temp/random_file.txt").close();

		// Detailed:
		boost::filesystem::ofstream f("D:/temp/random_file.txt");
		if (f.is_open())
		{
			f.close();
			if (boost::filesystem::exists("D:/temp/random_file.txt"))
				std::cout << "File created successfully" << std::endl;
			else
				std::cout << "File could not be created" << '\n';
		}
		else
			std::cout << "File could not be created\n";
		return 0;
	}
}
