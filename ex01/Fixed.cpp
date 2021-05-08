#include "Fixed.hpp"

Fixed::Fixed() {
	cout << "Default constructor called" << endl;
	this->_value = 0;
}

Fixed::Fixed(const int num) {
	// TODO: why does it handle negative values?
	this->_value = num << this->_fractional_bits;
}

Fixed::Fixed(const float num) {
	int		num_int_rep;
	// TODO: how this formula works?
	this->_value = round(num * (1 << this->_fractional_bits));
}

Fixed::Fixed(const Fixed& src) {
	cout << "Copy constructor called" << endl;
	*this = src;
}

Fixed::~Fixed() {
	cout << "Desctructor called" << endl;
}

Fixed&	Fixed::operator=(const Fixed& src) {
	cout << "Assign operator called" << endl;
	if (this != &src)
		this->_value = src._value;
	return *this;
}

int		Fixed::getRawBits() const {
	cout << "getRawBits called" << endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	cout << "setRawBits called" << endl;
	this->_value = raw;
}

ostream&	operator <<(ostream& out, const Fixed& src) {
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
