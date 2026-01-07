#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
#include <ostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed();
		Fixed(const int n);
		Fixed(const float n);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);

#endif
