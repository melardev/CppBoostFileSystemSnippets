#pragma once
#include <boost/filesystem.hpp>
#include <iostream>

namespace RecursiveIterator
{
	void main()
	{
		const std::string src_dir("./");

		for (boost::filesystem::recursive_directory_iterator end, file(src_dir); file != end; ++file)
		{
			// If not file skip
			if (file->status().type() != boost::filesystem::regular_file)
				continue;

			// If file, print path and file size
			const uint64_t size = boost::filesystem::file_size(*file);
			std::cout << "\t" << file->path().string() << "\t" << size << std::endl;
			// map.insert(boost::proto::functional::make_pair(size, file_info(file->path().string(), size)));
		}
	}
}
