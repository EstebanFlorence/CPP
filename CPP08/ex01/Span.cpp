#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n)
: N(n)
{
	container.reserve(N);
}

Span::Span(const Span& copy)
: N(copy.N), container(copy.container)
{}

Span::~Span() {}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->container = other.container;
	}
	return *this;
}

unsigned int	Span::operator[](int index) const
{
	if (index < 0)
		throw std::out_of_range("Negative Index");
	else if (static_cast<unsigned int>(index) >= this->N)
		throw std::out_of_range("Index out of bounds");

	return this->container[index];
}


unsigned int	Span::getSize() const
{ return N; }

void	Span::addNumber(int num)
{
	if (container.size() >= N)
		throw std::out_of_range("Span is full");
	container.push_back(num);
}

int	Span::shortestSpan()
{
	if (container.size() < 2)
		throw std::runtime_error("Not enough numbers in Span");

	std::sort(container.begin(), container.end());
	int	span = container[1] - container[0];
	for (unsigned int i = 0; i < container.size() - 1; i++)
		span = std::min(span, container[i + 1] - container[i]);
	
	return span;
}

int	Span::longestSpan()
{
	if (container.size() < 2)
		throw std::runtime_error("Not enough numbers in Span");

	std::vector<int>::const_iterator	maxElement = std::max_element(container.begin(), container.end());
	std::vector<int>::const_iterator	minElement = std::min_element(container.begin(), container.end());

	return *maxElement - *minElement;
}
