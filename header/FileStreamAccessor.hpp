#ifndef _FileStreamAccessor_HPP_
#define _FileStreamAccessor_HPP_

#include "IStreamAccessor.hpp"

class FileStreamAccessor : public IStreamAccessor<FileStreamAccessor>
{
	public:
		FileStreamAccessor()
		{
			std::cout << "FileStreamAccessor() called\n";
		}
		std::string PeekLine(size_t line) const
		{
			std::cout << "PeekLine in FileStreamAccessor\n";
			return "";
		}
		std::string ReadLine(size_t line)
		{
			std::cout << "ReadLine in FileStreamAccessor\n";
			return "";
		}
		bool WriteLine(size_t line, std::string str)
		{
			std::cout << "WriteLine in FileStreamAccessor\n";
			return true;
		}
		~FileStreamAccessor()
		{
			std::cout << "~FileStreamAccessor() called\n";
			//~IStreamAccessor<FileStreamAccessor>();
		}
};

#endif
