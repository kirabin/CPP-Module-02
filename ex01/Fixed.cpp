#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;
const int Fixed::_exponent = 1 << Fixed::_fractional_bits;

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int num) {
	this->_value = num * _exponent;
}

Fixed::Fixed(const float num) {
	this->_value = roundf(num * _exponent);
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;

	this->_value = src._value;
}

Fixed::~Fixed() {
	std::cout << "Desctructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& src) {
	std::cout << "Assign operator called" << std::endl;

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
	return (float)this->_value / _exponent;
}

int			Fixed::toInt() const {
	return this->_value / _exponent;
}
