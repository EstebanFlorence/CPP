#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::string& sequence)
: vecExecTime(0), deqExecTime(0)
{
	if (!isValid(sequence))
		throw std::runtime_error("Invalid Sequence");
	oldSequence = sequence;
}

PmergeMe::PmergeMe(const PmergeMe& copy)
: oldSequence(copy.oldSequence), vecSequence(copy.vecSequence), deqSequence(copy.deqSequence),
vecExecTime(copy.vecExecTime), deqExecTime(copy.deqExecTime)
{}

PmergeMe::~PmergeMe() {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return *this;

	this->vecSequence = other.vecSequence;
	this->deqSequence = other.deqSequence;
	this->vecExecTime = other.vecExecTime;
	this->deqExecTime = other.deqExecTime;
	this->oldSequence = other.oldSequence;

	return *this;
}


bool	PmergeMe::isValid(const std::string& input)
{
	std::istringstream	iss(input);
	int					num;

	while (iss >> num)
	{
		if (num <= 0)
			return false;
		vecSequence.push_back(num);
		deqSequence.push_back(num);
	}
	if (!iss.eof())
		return false;

	return true;
}

void	PmergeMe::run()
{
	clock_t	start = clock();
	pMergeInsertion(vecSequence, vecSequence.begin(), vecSequence.end());
	clock_t	end = clock();
	vecExecTime = static_cast<double>((end - start)) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;

	start = clock();
	pMergeInsertion(deqSequence, deqSequence.begin(), deqSequence.end());
	end = clock();
	deqExecTime = static_cast<double>((end - start)) / static_cast<double>(CLOCKS_PER_SEC) * 1000000.0;

}

// bool	PmergeMe::pMergeInsertion(std::deque<int>& sequence)
// {
// 	clock_t	start = clock();

// 	clock_t	end = clock();
// 	deqExecTime = static_cast<double>((end - start) / CLOCKS_PER_SEC);

// 	return true;
// }

// void	PmergeMe::mergeSort()
// {

// }

const std::string&	PmergeMe::getOldSequence() const
{ return oldSequence; }

const std::vector<int>&	PmergeMe::getVector() const
{ return vecSequence; }

const std::deque<int>&	PmergeMe::getDeque() const
{ return deqSequence; }

const double&	PmergeMe::getVecExecTime() const
{ return vecExecTime; }

const double&	PmergeMe::getDeqExecTime() const
{ return deqExecTime; }

template <typename T>
std::string	PmergeMe::getOrderedSequence(const T& container) const
{
	std::ostringstream	oss;

	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (it != container.begin())
			oss << " ";
		oss << *it;
	}

	return oss.str();
}

std::ostream&	operator<<(std::ostream& os, const PmergeMe& pMerge)
{
	os << "Before: " << pMerge.getOldSequence() << "\nAfter: " << pMerge.getOrderedSequence(pMerge.getVector())  
	<< "\nTime to process a range of\t" << pMerge.getVector().size() << " elements with std::vector : " 
	<< pMerge.getVecExecTime() << " us\n"
	<< "Time to process a range of\t" << pMerge.getDeque().size() << " elements with std::deque : " 
	<< pMerge.getDeqExecTime() << " us";

	return os;
}
