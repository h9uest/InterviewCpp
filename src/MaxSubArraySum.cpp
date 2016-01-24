#include "MaxSubArraySum.hpp"
#include <climits>

int MaxSubArraySum::GetMaxSubArraySum(std::vector<int> arr)
{
	if (arr.size() == 0)
	{
		return 0;
	}
	int max = INT_MIN;
	GetMaxSubArraySumEndingAt(arr, arr.size()-1, max);
	return max;
}

int MaxSubArraySum::GetMaxSubArraySumEndingAt(const std::vector<int>& arr, unsigned int index, int& max)
{
	if (index == 0)
	{
		max = arr[index];
		return arr[index];
	}

	int prev_sum = GetMaxSubArraySumEndingAt(arr, index-1, max);
	int value;
	if (prev_sum < 0)
	{
		value = arr[index];
	}
	else
	{
		value = prev_sum + arr[index];
	}
	
	if (max < value)
	{
		max = value;
	}
	return value;
}
