#include "Algorithms.hpp"
#include <algorithm>
#include "gtest/gtest.h"
#include <random>
#include <iostream>

TEST(Algorithms, QuickSort_Empty)
{
	std::vector<int> vec;
	SortingAlgorithms::QuickSort(vec);
	EXPECT_EQ(0, vec.size());
}

TEST(Algorithms, QuickSort_SingleElement)
{
	std::vector<int> vec({5});
	SortingAlgorithms::QuickSort(vec);
	EXPECT_EQ(1, vec.size());
	EXPECT_EQ(5, vec[0]);
}

TEST(Algorithms, QuickSort_EvenNumElements)
{
	std::vector<int> vec1({9, 3, 7, 1, 8, 8, 2, 3});
	std::vector<int> vec2(vec1);
	std::sort(vec1.begin(), vec1.end());
	SortingAlgorithms::QuickSort(vec2);
	EXPECT_EQ(vec1.size(), vec2.size());
	for (size_t i=0; i<vec1.size(); i++)
	{
		EXPECT_EQ(vec1[i], vec2[i]);
	}
}

TEST(Algorithms, QuickSort_OddNumElements)
{	
	std::vector<int> vec1({3, 7, 1, 8, 9, 8, 2, 3, 5});
	std::vector<int> vec2(vec1);
	std::sort(vec1.begin(), vec1.end());
	SortingAlgorithms::QuickSort(vec2);
	EXPECT_EQ(vec1.size(), vec2.size());
	for (size_t i=0; i<vec1.size(); i++)
	{
		EXPECT_EQ(vec1[i], vec2[i]);
	}
}

TEST(Algorithms, QuickSort_EqualElements)
{
	std::vector<int> vec1({0,0,0,0,0,0});
	std::vector<int> vec2({1,1,1,1,1,1,1});
	SortingAlgorithms::QuickSort(vec1);
	SortingAlgorithms::QuickSort(vec2);
}

TEST(Algorithms, QuickSort_RandomVector)
{
	std::random_device device;
	std::default_random_engine engine(device());
	std::uniform_int_distribution<int> distribution(1, 1000);

	size_t size = distribution(engine);
	std::cout << "Random vector size = " << size << std::endl;
	std::vector<int> vec1, vec2;
	for (size_t i=0; i<size; i++)
	{
		int value = distribution(engine);
		vec1.push_back(value);
		vec2.push_back(value);
	}
	std::sort(vec1.begin(), vec1.end());
	SortingAlgorithms::QuickSort(vec2);
	for (size_t i=0; i<vec1.size(); i++)
	{
		EXPECT_EQ(vec1[i], vec2[i]);
	}
}
