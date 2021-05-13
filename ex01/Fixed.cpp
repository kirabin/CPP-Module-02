#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int num) {
	// TODO: why does it handle negative values?
	this->_value = num << this->_fractional_bits;
}

Fixed::Fixed(const float num) {
	// TODO: how this formula works?
	this->_value = roundf(num * (1 << this->_fractional_bits));
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	std::cout << "Desctructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src) {
	std::cout << "Assign operator called" << std::endl;
	if (this != &src)
		this->_value = src._value;
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits called" << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits called" << std::endl;
	this->_value = raw;
}

std::ostream&	operator <<(std::ostream& out, const Fixed& src) {
	out << src.toFloat();
	return out;
}

float		Fixed::toFloat() const {
	// TODO: how this formula works?
	return (double)this->_value / (double)(1 << this->_fractional_bits);
}

int			Fixed::toInt() const {
	return this->_value >> this->_fractional_bits;
}
