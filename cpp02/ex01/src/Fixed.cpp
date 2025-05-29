#include "../includes/Fixed.hpp"

Fixed::Fixed(void)
{
	_num = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int inum)
{
	_num = inum * (1 << _bits);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float fnum)
{
	_num = (int)roundf(fnum * (1 << _bits));
	std::cout << "Float constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed &fixed)
{
	this->_num = fixed._num;
	std::cout << "Copy assignment operator called\n";
	return (*this);
}


int	Fixed::getRawBits(void)
{
	std::cout << "getRawBits member function called\n";
	return (_num);
}
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_num = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_num / (float)(1 << _bits));
}

int		Fixed::toInt(void) const
{
	return (_num / (1 << _bits));
}

// Static methods

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1._num > f2._num)
		return (f2);
	return (f1);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1._num > f2._num)
		return (f2);
	return (f1);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1._num > f2._num)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1._num > f2._num)
		return (f1);
	return (f2);
}

// Numerical operators

Fixed&	Fixed::operator++()
{
	_num++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	++_num;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	_num--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--_num;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& fixed)
{
	Fixed ret = Fixed();
	ret._num = _num - fixed._num;
	return (ret);
}

Fixed	Fixed::operator+(const Fixed& fixed)
{
	Fixed ret = Fixed();
	ret._num = _num + fixed._num;
	return (ret);
}

Fixed	Fixed::operator*(const Fixed& fixed)
{
	Fixed ret = Fixed();
	ret._num = (_num * fixed._num) / (1 << _bits);
	return (ret);
}

Fixed	Fixed::operator/(const Fixed& fixed)
{
	Fixed ret = Fixed();
	ret._num = _num  * (1 << _bits) / fixed._num;
	return (ret);
}


// Boolean overloads
bool	Fixed::operator>(const Fixed& fixed)
{
	return (_num > fixed._num);
}

bool	Fixed::operator<(const Fixed& fixed)
{
	return (_num < fixed._num);
}

bool	Fixed::operator>=(const Fixed& fixed)
{
	return (_num >= fixed._num);
}

bool	Fixed::operator<=(const Fixed& fixed)
{
	return (_num <= fixed._num);
}

bool	Fixed::operator==(const Fixed& fixed)
{
	return (_num == fixed._num);
}

bool	Fixed::operator!=(const Fixed& fixed)
{
	return (_num != fixed._num);
}

// String stuff

std::ostream&	operator<<(std::ostream &oss, const Fixed& fixed)
{
	oss << fixed.toFloat();
	return (oss);
}

