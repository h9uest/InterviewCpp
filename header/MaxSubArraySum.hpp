#ifndef _MaxSubArraySum_HPP_
#define _MaxSubArraySum_HPP_

#include <vector>

class MaxSubArraySum
{
	protected:
		int GetMaxSubArraySumEndingAt(const std::vector<int>& arr, unsigned int index, int& max);

	public:
		int GetMaxSubArraySum(std::vector<int> arr);
};

#endif
