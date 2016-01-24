#include "ConcurrentQueue.hpp"
#include "gtest/gtest.h"
#include <thread>
#include <vector>
#include <iostream>

struct Product
{
	unsigned int Producer;
	int Value;
};

template<typename T, unsigned int Size>
void Produce(unsigned int id, ConcurrentQueue<T, Size>& q)
{
	int start = 0;
	while(true)
	{
		T product;
		product.Value = start;
		product.Producer = id;
		q.Push(product);
		std::cout << "Thread " << id << " produced element " << start << std::endl;
		start ++;
	}
}

template<typename T, unsigned int Size>
void Consume(unsigned int id, ConcurrentQueue<T, Size>& q)
{
	while(true)
	{
		Product p = q.Front();
		q.Pop();
		std::cout << "Thread " << p.Producer << " consumed element " << p.Value << std::endl;
	}
}


TEST(ConcurrentQueue, BaseCase)
{
	ConcurrentQueue<Product, 100> q;
	std::vector<std::thread> threads;
	threads.reserve(50);
	for (unsigned int i=0; i<10; i++)
	{
		threads.push_back(std::thread(&Produce<Product, 100>, i, std::ref(q)));
	}

	for (unsigned int i=10; i<50; i++)
	{
		threads.push_back(std::thread(&Consume<Product, 100>, i, std::ref(q)));
	}

	for (unsigned int i=0; i<50; i++)
	{
		threads[i].join();
	}
}
