#include "Algorithms.hpp"
#include <climits>
#include <cstdlib>
#include <algorithm>

void SortingAlgorithms::CountingSort(std::vector<int>& vec)
{
	int max = INT_MIN;
	int min = INT_MAX;
	int range = 0;
	for (int ele : vec)
	{
		if (min > ele)
		{
			min = ele;
		}

		if (max < ele)
		{
			max = ele;
		}	
	}

	range = max - min + 1;
	std::vector<int> arr(range, 0);

	for (int ele : vec)
	{
		arr[ele-min] ++;
	}

	int index = 0;
	for (size_t i=0; i<arr.size(); i++)
	{
		while (arr[i] != 0)
		{
			vec[index++] = min + i;
			arr[i] --;
		}
	}
}

void QuickSort(std::vector<int>& vec, size_t begin, size_t end)
{
	if (begin >= end)
	{
		return;
	}

	size_t mid_index = (begin + end) / 2;
	int pivot = vec[mid_index];
	size_t small_index = begin;
	size_t big_index = end;
	while(small_index < big_index)
	{
		while(vec[small_index] < pivot)
		{
			small_index++;
		}

		while(vec[big_index] > pivot)
		{
			big_index--;
		}
		
		if (small_index < big_index)
		{
			if (vec[small_index] > vec[big_index])
			{
				std::swap(vec[small_index], vec[big_index]);
			}
			small_index++;
			big_index--;
		}
		else
		{
			break;
		}
	}

	if (small_index == big_index)
	{
		if (pivot < vec[small_index])
		{
			big_index--;
		}
		else
		{
			small_index++;
		}
	}
	
	::QuickSort(vec, begin, big_index);
	::QuickSort(vec, small_index, end);
}

void SortingAlgorithms::QuickSort(std::vector<int>& vec)
{
	if (vec.size() < 2)
	{
		return;
	}

	::QuickSort(vec, 0, vec.size()-1);
}

