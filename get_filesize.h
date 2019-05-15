#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace GetFileSize
{
	int main()
	{
		boost::filesystem::path file("");
		if (boost::filesystem::exists(file))
		{
			std::cout << "File size of " << file << std::endl;
			boost::filesystem::file_size(file);
		}
	}
}
