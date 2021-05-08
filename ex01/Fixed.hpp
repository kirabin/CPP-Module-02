#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>
# include <ostream>
# include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Fixed {

	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed& src);
		~Fixed();

		Fixed&		operator =(const Fixed& src);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;

	private:
		static const int	_fractional_bits = 8;
		int					_value;

};
// TODO: why outside of class scope?
ostream&	operator <<(ostream& out, const Fixed& src);

#endif
