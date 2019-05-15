#pragma once
#include <boost/filesystem.hpp>
#include <iostream>


namespace BoostIfStreamBinary
{
	int main()
	{
		// Run the boost_ofstream_binary.h snippet so you will have that file
		boost::filesystem::ifstream in("./ofstream_demo.bin", std::iostream::binary);
		if (in.is_open())
		{
			char buffer[1024];
			std::string contents;
			while (!in.eof())
			{
				in.read(buffer, 1024);
				contents += buffer;
				memset(buffer, 0x00, 1024);
			}
			std::cout << contents << std::endl;
		}
		else
		{
			std::cout << "Could not open the file, have did you run boost_ofstream_binary.h snippet?\n";
		}
		return 0;
	}
}
