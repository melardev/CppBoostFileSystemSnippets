#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace CreateAndDeleteDirectory
{
	int main()
	{
		const std::string starting_point = "D:/temp/";
		const boost::filesystem::path directory(starting_point);
		// String folder path
		std::string new_dir = starting_point + "boost_dir";
		// Or create the path object
		const boost::filesystem::path new_dir_path = starting_point / boost::filesystem::path("boost_dir");
		// if (boost::filesystem::create_directory(new_dir)) // Using string, using path
		if (boost::filesystem::create_directory(new_dir_path))
		{
			std::cout << "Directory has been created" << std::endl;
			if (boost::filesystem::remove(new_dir_path))
				std::cout << "Folder has been deleted successfully" << std::endl;
			else
				std::cout << "Error! could not delete the created folder" << std::endl;
		}
		else
		{
			std::cout << "Error! Directory has not been created =(" << std::endl;
		}
		return 0;
	}
}

#if false
int main()
{
	CreateDirectoryWithBoost::main();
}
#endif
