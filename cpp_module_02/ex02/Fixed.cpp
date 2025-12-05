/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:58:17 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/05 03:56:42 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
	: _raw(0)
{
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);	
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const int n)
	: _raw(n << _fractionalBits)
{
}

Fixed::Fixed(const float f)
	: _raw(roundf(f * (1 << _fractionalBits)))
{	
}

int	Fixed::getRawBits(void) const
{
	return (_raw);
}

void	Fixed::setRawBits(int const raw)
{
	_raw = raw;
}

int	Fixed::toInt() const
{
	return (this->getRawBits() >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractionalBits));
}

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed		result;
	long long	upper_raw = static_cast<long long>(this->getRawBits()) * other.getRawBits();

	result.setRawBits(static_cast<int>(upper_raw >> _fractionalBits));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed		result;
	long long	upper_raw = (static_cast<long long>(this->getRawBits()) << _fractionalBits) / other.getRawBits();

	result.setRawBits(static_cast<int>(upper_raw));
	return (result);
}

Fixed&	Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (temp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}