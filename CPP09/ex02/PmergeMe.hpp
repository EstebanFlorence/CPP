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

// # define THRESHOLD 7

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
		bool	pMergeInsertion(std::vector<int>& sequence);
		bool	pMergeInsertion(std::deque<int>& sequence);
		void	sort(std::vector<int>& sequence, std::vector<int>::iterator first, std::vector<int>::iterator last);
		void	insertionSort(std::vector<int>::iterator first, std::vector<int>::iterator last);
		void	mergeSort();

		const std::string&		getOldSequence() const;
		const std::vector<int>&	getVector() const;
		const std::deque<int>&	getDeque() const;
		const double&			getVecExecTime() const;
		const double&			getDeqExecTime() const;
		template <typename T>
		std::string				getOrderedSequence(const T& container) const;

};

std::ostream&	operator<<(std::ostream& os, const PmergeMe& pMerge);

#endif