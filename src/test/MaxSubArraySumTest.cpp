#include "gtest/gtest.h"
#include "MaxSubArraySum.hpp"

TEST(MaxSubArraySum, GetMaxSubArraySum_EmptyArray)
{
	MaxSubArraySum sum_finder;
	int max_sum = sum_finder.GetMaxSubArraySum({});
	EXPECT_EQ(0, max_sum);
}


TEST(MaxSubArraySum, GetMaxSubArraySum_OneElementArray)
{
	MaxSubArraySum sum_finder;
	int max_sum = sum_finder.GetMaxSubArraySum({1});
	EXPECT_EQ(1, max_sum);
}


TEST(MaxSubArraySum, GetMaxSubArraySum_RegularSizeArray)
{
	MaxSubArraySum sum_finder;
	int max_sum = sum_finder.GetMaxSubArraySum({1, -2, 3, 10, -4, 7, 2, -5});
	EXPECT_EQ(18, max_sum);
}


TEST(MaxSubArraySum, GetMaxSubArraySum_LongEqualArray)
{
	MaxSubArraySum sum_finder;
	std::vector<int> vec(1000, 2);
	int max_sum = sum_finder.GetMaxSubArraySum(vec);
	EXPECT_EQ(2000, max_sum);
}


