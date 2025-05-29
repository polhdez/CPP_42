#include <iostream>
#include <sstream>
#include <cmath>

class Fixed
{
	private:
	int					_num;
	static const int	_bits = 8;

	public:
	Fixed(void);
	Fixed(const int inum);
	Fixed(const float fnum);
	Fixed(const Fixed& fixed);
	Fixed&	operator=(const Fixed& fixed);
	~Fixed();

	// Methods
	int		getRawBits(void);
	void	setRawBits(int const raw);
	float	toFloat(void)const;
	int		toInt(void)const;

	// Static methods
	static Fixed&		min(Fixed& f1, Fixed& f2);
	static const Fixed&	min(const Fixed& f1, const Fixed& f2);
	static Fixed&		max(Fixed& f1, Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);

	// Numerical operators
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	Fixed	operator-(const Fixed& fixed);
	Fixed	operator+(const Fixed& fixed);
	Fixed	operator*(const Fixed& fixed);
	Fixed	operator/(const Fixed& fixed);
	bool	operator>(const Fixed& fixed);
	bool	operator<(const Fixed& fixed);
	bool	operator>=(const Fixed& fixed);
	bool	operator<=(const Fixed& fixed);
	bool	operator==(const Fixed& fixed);
	bool	operator!=(const Fixed& fixed);

};

// Operator overloads
std::ostream&	operator<<(std::ostream &os, const Fixed& fixed);
