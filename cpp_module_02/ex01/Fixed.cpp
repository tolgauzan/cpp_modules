/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 23:58:08 by tuzan             #+#    #+#             */
/*   Updated: 2025/11/05 01:59:09 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed()
	: _raw(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return (*this);	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n)
	: _raw(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
	: _raw(roundf(f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
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

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}