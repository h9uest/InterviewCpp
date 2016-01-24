#include "LargestSlopeFinder.hpp"
#include <algorithm>
#include <climits>

typedef LargestSlopeFinder::Point Point;

std::tuple<const Point *, const Point *> LargestSlopeFinder::FindLargestSlope(const std::vector<Point>& vec)
{
	std::vector<Point> points = vec;
	std::sort(points.begin(), points.end());

	double max_slope = -std::numeric_limits<double>::max();
	std::tuple<Point *, Point *> max_points = std::make_tuple<Point *, Point *>(&points[0], &points[1]);
	for (size_t i=1; i<points.size(); ++i)
	{
		double slope = static_cast<double>((points[i].Y - points[i-1].Y)) / (points[i].X - points[i-1].X);
		if (max_slope < slope)
		{
			std::get<0>(max_points) = &points[i-1];
			std::get<1>(max_points) = &points[i];
			max_slope = slope;
		}
	}

	std::tuple<const Point *, const Point *> ret;
	for (size_t i=0; i<vec.size(); ++i)
	{
		if (vec[i] == *std::get<0>(max_points))
		{
			std::get<0>(ret) = &vec[i];
		}
		else if (vec[i] == *std::get<1>(max_points))
		{
			std::get<1>(ret) = &vec[i];
		}
	}

	return ret;
}
