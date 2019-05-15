#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace RenameFile
{
	int main()
	{
		std::string bad_name = "./bad_name.txt";

		const boost::filesystem::path cool_file("./cool_name.txt");

		// Touch the file
		boost::filesystem::ofstream(bad_name.c_str()).close();

		// args should be path objects, but path has a constructor that takes string so the string is
		// converted implicitly to path, this is why it worked even with string arg
		boost::filesystem::rename(bad_name, cool_file);

		if (boost::filesystem::exists(cool_file))
		{
			std::cout << "Renaming file worked successfully" << '\n';

			// Remove the file
			if (boost::filesystem::remove(cool_file))
				std::cout << "Cool file deleted" << std::endl;
			else
				std::cout << "Error! Cool file could not be deleted" << std::endl;
		}

		return 0;
	}
}
