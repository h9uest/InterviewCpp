#ifndef _LargestSlopeFinder_HPP_
#define _LargestSlopeFinder_HPP_

#include <vector>
#include <tuple>

class LargestSlopeFinder
{
	public:
		struct Point
		{
			double X;
			double Y;

			Point(double x, double y)
			{
				X = x;
				Y = y;
			}

			bool operator<(const Point& point) const
			{
				return X < point.X;
			}

			bool operator==(const Point& point) const
			{
				return X == point.X && Y == point.Y;
			}
		};

		std::tuple<const Point *, const Point *> FindLargestSlope(const std::vector<Point>& vec);
};

#endif
