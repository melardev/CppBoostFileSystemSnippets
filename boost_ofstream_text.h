#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace BoostOfStreamText
{
	int main()
	{
		// Even though I am writing text, I always prefer to use binary mode
		// For text
		boost::filesystem::ofstream os("./ofstream_demo.txt");
		if (os.is_open())
		{
			std::cout << "File opened successfully" << std::endl;
			const std::string text = "Write a line";
			os << text << std::endl;
			os << "Write another line" << '\n';
			os << "Yet another line\n";

			const unsigned long long bytesWritten = os.tellp();
			std::cout << bytesWritten << " Written" << std::endl;
			os.seekp(0); // seek the cursor to the beginning, not needed
			os.close();
			std::cout << "Finished" << std::endl;
		}
		else
		{
			std::cout << "Error! couldn't open the file" << std::endl;
		}


		return 0;
	}
}
