#include "TecentArrayFiller.hpp"
#include <unordered_map>

std::vector<int> TecentArrayFiller::GetSolution(const std::vector<int>& arr)
{
	arr_ = &arr;
	std::vector<int> ret;
	ret.resize(arr.size());
	BacktrackFill(ret, 0);
	return ret;
}

bool TecentArrayFiller::IsSolution(const std::vector<int>& sol, unsigned int index) const
{
	if (index != sol.size())
	{
		return false;
	}

	std::unordered_map<int, int> counts;
	for (int ele : sol)
	{
		if (counts.find(ele) == counts.end())
		{
			counts[ele] = 1;
		}
		else
		{
			counts[ele] ++;
		}
	}

	for (unsigned int i=0; i<sol.size(); i++)
	{
		int ele = (*arr_)[i];
		if (counts.find(ele) == counts.end())
		{
			if (sol[i] != 0)
			{
				return false;
			}
		}

		if (counts[ele] != sol[i])
		{
			return false;
		}
	}

	return true;
}

std::vector<int> TecentArrayFiller::ConstructCandidates(std::vector<int>& sol, unsigned int index)
{
	int range = sol.size();
	for (unsigned int i=0; i<index; i++)
	{
		range -= sol[i];
	}

	std::vector<int> vec;
	for (int i=0; i<=range; i++)
	{
		vec.push_back(i);
	}

	return vec;
}

bool TecentArrayFiller::BacktrackFill(std::vector<int>& sol, unsigned int index)
{
	if (IsSolution(sol, index))
	{
		return true;
	}
	
	if (index >= sol.size())
	{
		return false;
	}

	std::vector<int> candidates = ConstructCandidates(sol, index);
	for (auto candidate : candidates)
	{
		sol[index] = candidate;
		if (BacktrackFill(sol, index + 1))
		{
			return true;
		}
	}
	return false;
}
