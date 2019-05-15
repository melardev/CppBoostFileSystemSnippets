#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace BoostOfStreamBinary
{
	int main()
	{
		// Even though I am writing text, I always prefer to use binary mode
		// For text
		boost::filesystem::ofstream os("./ofstream_demo.bin", std::ios::binary);
		if (os.is_open())
		{
			std::cout << "File opened successfully" << std::endl;
			// We can still use the same as we did for the ofstream_text demo
			const std::string text = "Write a line";
			os << text << std::endl;

			// And the most important function for binary is write() we have to pass a buffer of bytes
			// and specify how many bytes to write, no matter what write() writes in binary mode
			const char* other_text = "This is written always in binary, it does not matter the std::ios mode\n";
			os.write(other_text, strlen(other_text) + 1);
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
