#include "gtest/gtest.h"
#include <vector>
#include "LargestSlopeFinder.hpp"

typedef LargestSlopeFinder::Point Point;

TEST(LargestSlopeFinder, FindLargestSlope)
{
	std::vector<Point> vec({Point(3, 4), Point(0.5, 0.5), Point(4.5, 5), Point(2, 0), Point(4, 4)});
	LargestSlopeFinder finder;
	std::tuple<const Point *, const Point *> res = finder.FindLargestSlope(vec);
	EXPECT_EQ(Point(2, 0), *std::get<0>(res));
	EXPECT_EQ(Point(3, 4), *std::get<1>(res));
}
