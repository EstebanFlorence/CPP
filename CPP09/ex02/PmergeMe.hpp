#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <vector>
# include <list>
# include <deque>
# include <algorithm>
# include <iterator>
# include <string>
# include <sstream>
# include <ctime>
# include <stdexcept>

class	PmergeMe
{
	private:
		std::string					oldSequence;
		std::vector<int>			vecSequence;
		std::deque<int>				deqSequence;
		double						vecExecTime;
		double						deqExecTime;
		static const unsigned int	K = 3;

		PmergeMe();

	public:
		PmergeMe(const std::string& sequence);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();

		PmergeMe&	operator=(const PmergeMe& other);

		bool	isValid(const std::string& input);
		void	run();

		template <typename C, typename IT>
		void	pMergeInsertion(C& sequence, IT first, IT last);
		template <typename IT>
		void	insertionSort(IT first, IT last);

		const std::string&		getOldSequence() const;
		const std::vector<int>&	getVector() const;
		const std::deque<int>&	getDeque() const;
		const double&			getVecExecTime() const;
		const double&			getDeqExecTime() const;
		
		template <typename T>
		std::string				getOrderedSequence(const T& container) const;

};

template <typename C, typename IT>
void	PmergeMe::pMergeInsertion(C& sequence, IT first, IT last)
{
	if (std::distance(first, last) > K)
	{
		IT	mid = first + std::distance(first, last) / 2;
		pMergeInsertion(sequence, first, mid);
		pMergeInsertion(sequence, mid, last);

		C	copy(std::distance(first, last));

		std::merge(first, mid, mid, last, copy.begin());

		IT	copyBegin(copy.begin());
		IT	copyEnd(copy.end());
		std::copy(copyBegin, copyEnd, first);
	}
	else
	{
		insertionSort(first, last);
	}
}

template <typename IT>
void	PmergeMe::insertionSort(IT first, IT last)
{
	for (IT it = first + 1; it != last; ++it)
	{
		int	tmp = *it;
		IT	j = it - 1;

		while (j >= first && *j > tmp)
		{
			*(j + 1) = *j;
			--j;
		}
		*(j + 1) = tmp;
	}
}


std::ostream&	operator<<(std::ostream& os, const PmergeMe& pMerge);

#endif