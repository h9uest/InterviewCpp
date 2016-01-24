#ifndef _OptimizedFibo_HPP_
#define _OptimizedFibo_HPP_

template<int i>
struct OptimizedFibo
{
	static const int Value = i * OptimizedFibo<i-1>::Value;
};

template<>
struct OptimizedFibo<0>
{
	static const int Value = 1;
};

#endif
