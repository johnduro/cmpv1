// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Math.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/24 19:09:03 by mle-roy           #+#    #+#             //
//   Updated: 2015/04/25 18:02:20 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MATH_HPP
# define MATH_HPP

#include <cmath>

class Math
{
private:
	static double  	_powerOfTen(int num);
	static double  	_square_suite(double rst, double j, double a);

	Math();
	~Math();
	Math(Math const &src);
	Math &   operator=(Math const &rhs);

public:
	static int        PGCD(int a, int b);

	template<typename T>
	static T          ABS(T a);

	static double     POW(double x, int p);
	static bool       isPrime(int x);
	static int        getComaNb(double x);
	static double     SQRT(double a);
};

template<typename T>
T   Math::ABS(T x)
{
	if (x < 0)
		x *= -1;
	return x;
}

#endif // ** MATH_HPP ** //
