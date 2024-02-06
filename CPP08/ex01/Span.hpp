#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class	Span
{
	private:
		unsigned int		N;
		std::vector<int>	container;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& copy);
		~Span();

		Span&			operator=(const Span& other);
		unsigned int	operator[](int index) const;

		unsigned int	getSize() const;
		void			addNumber(int num);
		int				shortestSpan();
		int				longestSpan();
};

#endif