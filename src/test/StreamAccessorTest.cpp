#include "gtest/gtest.h"
#include "FileStreamAccessor.hpp"

template<typename Implementation>
void SampleFunc(IStreamAccessor<Implementation>& imp)
{
	imp.PeekLine(2);
	std::cout << "Exiting SampleFunc\n";
}

TEST(FileStreamAccessor, SampleTest)
{
	FileStreamAccessor fsa;
	std::cout << "About to call SampleFunc\n";
	SampleFunc<FileStreamAccessor>(fsa);
	std::cout << "Finished SampleFunc\n";
}
