#include "TecentArrayFiller.hpp"
#include "gtest/gtest.h"

TEST(TecentArrayFiller, GetSolution_OneElementArray)
{
	TecentArrayFiller filler;
	std::vector<int> vec {1};
	std::vector<int> res = filler.GetSolution(vec);
	EXPECT_EQ(1, res.size());
	EXPECT_EQ(0, res[0]);
}

TEST(TecentArrayFiller, GetSolution_SampleTest)
{
	TecentArrayFiller filler;
	std::vector<int> vec {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> res = filler.GetSolution(vec);
	std::vector<int> sol {6,2,1,0,0,0,1,0,0,0};
	EXPECT_EQ(sol, res);
}
