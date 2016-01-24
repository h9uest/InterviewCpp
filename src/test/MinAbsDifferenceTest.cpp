#include "gtest/gtest.h"
#include <vector>
#include "MinAbsDifference.hpp"
#include "Algorithms.hpp"

TEST(MinAbsDifference, CountingSort)
{
	std::vector<int> vec ({9, -2, -5, 6, 10});
	SortingAlgorithms::CountingSort(vec);
	std::vector<int> exp = {-5, -2, 6, 9, 10};
	EXPECT_EQ(exp, vec);
}

TEST(MinAbsDifference, GetMinAbsDifference)
{
	std::vector<int> vec = {2, -1, 9, 0, 2000};
	MinAbsDifference calculator;
	int res = calculator.GetMinAbsDifference(vec);
	EXPECT_EQ(1, res);
}
