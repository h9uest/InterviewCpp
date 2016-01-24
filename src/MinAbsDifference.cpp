#include "MinAbsDifference.hpp"
#include <climits>
#include <algorithm>
#include <unordered_map>
#include "Algorithms.hpp" 


int MinAbsDifference::GetMinAbsDifference(std::vector<int> vec)
{
	//std::sort(vec.begin(), vec.begin()+vec.size());
	SortingAlgorithms::CountingSort(vec);
	int min_diff = INT_MAX;
	for (size_t i=0; i<vec.size()-1; i++)
	{
		int abs_diff = abs(vec[i+1] - vec[i]);
		if (min_diff > abs_diff)
		{
			min_diff = abs_diff;
		}
	}

	return min_diff;
}
