#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace FileExists
{
	inline int main()
	{
		std::cout << "D:/temp/text_file.txt exists? ";
		if (boost::filesystem::exists("D:/temp/text_file.txt"))
			std::cout << "Yes!";
		else
			std::cout << "No!";
		std::cout << std::endl;

		return 0;
	}
}


#if false
int main()
{
	FileExists::main();
}
#endif
