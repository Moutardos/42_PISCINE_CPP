#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>

class	Span {

	public:
		Span			(void);
		Span			(Span const &ref);
		Span &operator=	(Span const &ref);
		~Span			(void);
		Span			(unsigned int size);
		
		void	addNumber		(int nb);
		int		shortestSpan	(void);
		int		highestSpan		(void);

	private:
		unsigned int		_size;
		std::vector<int>	_vec;
		bool				_spanReady;
		int	_shortestSpan;
		int	_highestSpan;
		struct	_ShortestSpan /*functor*/{

			public:
				_ShortestSpan	(void) {};
				void operator()(int n)
				{
					int	span;
					
					if (turn > 0)
					{
						span = std::abs(_lastNb - n);
						if (span < _shortestSpan || _shortestSpan == -1)
							_shortestSpan = span;
					}
					turn++;
					_lastNb = n;
				}
				int	getShortestSpan() {return _shortestSpan;};

			private:
				int	turn = 0;
				int	_shortestSpan = -1;
				int	_lastNb;
		};
		void	setSpan	(void);
};

#endif