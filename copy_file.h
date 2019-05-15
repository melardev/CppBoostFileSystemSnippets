#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace CopyFileWithBoost
{
	int main()
	{
		const std::string original_file = "./copy_file.h";
		if (!boost::filesystem::is_regular_file(original_file))
		{
			// Create the file if it does not exist
			boost::filesystem::ofstream ofs(original_file);
			if (!ofs.is_open())
			{
				std::cout << original_file << " does not exist and could not create it" << std::endl;
				return 1;
			}
			ofs.close();
		}

		const std::string copied_file = original_file + ".copy";
		const boost::filesystem::path source(original_file);

		const boost::filesystem::path destination(copied_file);
		try
		{
			boost::filesystem::copy_file(source, destination, boost::filesystem::copy_option::fail_if_exists);

			// Delete the files, comment this if you wanna test fail_if_exists option, which triggers an exception
			// for example when the file is already present; to overwrite the file use copy_option::overwrite_if_exists
			boost::filesystem::remove(copied_file);
			boost::filesystem::remove(destination);
		}
		catch (...)
		{
			std::cout << "Something bad happened " << std::endl;
		}

		return 0;
	}
}

#if false
int main()
{
	CopyFileSnippet::main();
}
#endif
