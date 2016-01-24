#include <iostream>
#include "BinaryTreeVisibleNodeCounter.hpp"
using namespace std;
#include "OptimizedFibo.hpp"
#include "FileStreamAccessor.hpp"

	
	
template<typename Implementation>
void SampleFunc(IStreamAccessor<Implementation> * imp)
{
	imp->PeekLine(2);
	std::cout << "Exiting SampleFunc\n";
}

void TEST()
{
	FileStreamAccessor fsa;// = new FileStreamAccessor();
	std::cout << "About to call SampleFunc\n";
	SampleFunc(&fsa);
	std::cout << "Finished SampleFunc\n";

	//delete fsa;
}

int main()
{
	//OptimizedFibo<5> fibo;
	//std::cout << OptimizedFibo<5>::Value;
	TEST();

	std::cout << "Another usage:\n";
	IStreamAccessor<FileStreamAccessor> *ptr = new FileStreamAccessor();
	SampleFunc(ptr);
	delete ptr;

	return 0;
}

