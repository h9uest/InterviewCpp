#ifndef _TecentArrayFiller_HPP_
#define _TecentArrayFiller_HPP_

#include <vector>

class TecentArrayFiller
{
	protected:
		const std::vector<int> *arr_;
		std::vector<int> ConstructCandidates(std::vector<int>& sol, unsigned int index);
		bool IsSolution(const std::vector<int>& sol, unsigned int index) const;
		bool BacktrackFill(std::vector<int>& sol, unsigned int index);

	public:
		std::vector<int> GetSolution(const std::vector<int>& arr);
};

#endif
