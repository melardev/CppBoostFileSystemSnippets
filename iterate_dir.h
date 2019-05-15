#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace IterateDir
{
	int main()
	{
		// Change the path to whatever you want and exists on your PC
		const boost::filesystem::path path("./");
		try
		{
			if (boost::filesystem::exists(path))
			{
				if (boost::filesystem::is_directory(path))
				{
					std::cout << path << " <DIR>" << '\n';

					for (boost::filesystem::directory_entry& file : boost::filesystem::directory_iterator(path))
					{
						std::cout << "\t" << file.path() << std::endl;
						if (boost::filesystem::is_regular_file(file))
							std::cout << "\t" << file << " ; size: " << file_size(file) << std::endl;
					}
				}
				else
				{
					std::cout << path << " is not a directory\n";
				}
			}
			else
				std::cout << path << " does not exist" << std::endl;
		}
		catch (const boost::filesystem::filesystem_error& ex)
		{
			std::cout << ex.what() << std::endl;
		}

		return 0;
	}
}
