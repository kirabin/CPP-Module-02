#include "Fixed.hpp"

Fixed::Fixed() {
	cout << "Default constructor called" << endl;
	this->value = 0;
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
		this->value = src.value;
	return *this;
}

int		Fixed::getRawBits() const {
	cout << "getRawBits called" << endl;
	return this->value;
}

void	Fixed::setRawBits(int const raw) {
	cout << "setRawBits called" << endl;
	this->value = raw;
}
