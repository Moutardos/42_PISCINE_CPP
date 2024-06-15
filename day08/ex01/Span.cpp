#include "Span.hpp"

Span::Span(void) {


}

Span::Span(Span const &ref) {
	*this = ref;
}

Span	&Span::operator=(Span const &ref) {
	(void)ref;
	return (*this);
}

Span::~Span(void) {

}

Span::Span(unsigned int size) : _size(size), _spanReady(false) {

	_vec.resize(0);
}
void	Span::addNumber		(int nb) {

	this->_spanReady = false;
	if (_vec.size() >= _size)
		throw	std::exception();
	_vec.push_back(nb);
}
void print(const int &i) {
    std::cout << i << ' ';
}

int	Span::shortestSpan(void) {

	setSpan();
	return (this->_shortestSpan);
}


int	Span::highestSpan(void) {

	setSpan();
	return (this->_highestSpan);
}
void	Span::setSpan(void)
{
	if (!this->_spanReady)
	{
		std::sort(this->_vec.begin(), this->_vec.end());
		Span::_ShortestSpan s = std::for_each(this->_vec.begin(), this->_vec.end(), _ShortestSpan());
		this->_shortestSpan = s.getShortestSpan();
		this->_highestSpan = *std::max_element(this->_vec.begin(), this->_vec.end()) - *std::min_element(this->_vec.begin(), this->_vec.end());  
		this->_spanReady = true;
	}
	
}
