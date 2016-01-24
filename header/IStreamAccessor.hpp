#ifndef _IStreamAccessor_HPP_
#define _IStreamAccessor_HPP_

#include <string>
#include <iostream>

template<typename Implementation>
class IStreamAccessor
{
	protected:
		Implementation * Imp();
		const Implementation * Imp() const;
		IStreamAccessor()
		{
			std::cout << "IStreamAccessor() called\n";
		}
		

	public:
		std::string PeekLine(size_t line) const;
		std::string ReadLine(size_t line);
		bool WriteLine(size_t line, std::string str);
		virtual ~IStreamAccessor()
		{
			std::cout << "~IStreamAccessor() called\n";
		}
		
};

template<typename Implementation>
Implementation * IStreamAccessor<Implementation>::Imp()
{
	return static_cast<Implementation *>(this);
}

template<typename Implementation>
const Implementation * IStreamAccessor<Implementation>::Imp() const
{
	return static_cast<const Implementation *>(this);
}

template<typename Implementation>
std::string IStreamAccessor<Implementation>::PeekLine(size_t line) const
{
	std::cout << "PeekLine in IStreamAccessor\n";
	return Imp()->PeekLine(line);
}

template<typename Implementation>
std::string IStreamAccessor<Implementation>::ReadLine(size_t line)
{
	std::cout << "ReadLine in IStreamAccessor\n";
	return Imp()->ReadLine(line);
}

template<typename Implementation>
bool IStreamAccessor<Implementation>::WriteLine(size_t line, std::string str)
{
	std::cout << "WriteLine in IStreamAccessor\n";
	return Imp()->WriteLine(line, str);
}

#endif
