// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Computor.hpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: mle-roy <mle-roy@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/25 17:52:30 by mle-roy           #+#    #+#             //
//   Updated: 2015/04/25 18:25:53 by mle-roy          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef COMPUTOR_HPP
# define COMPUTOR_HPP

#include <list>
#include <stdexcept>
#include <string>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "Fraction.hpp"

struct Coeff
{
	double			value;
	double			degree;
};


class Computor
{
// ** PRIVATE ** //
private:

	std::string			_str;
	std::string			_left;
	std::string			_right;
	std::list<Coeff>	_coeffs;
	int					_maxDegree;
	double				_a;
	double				_b;
	double				_c;
	bool				_debug;

	Computor( const Computor & src );
	Computor &		operator=( const Computor & src );
	void			_initComputor( void );
	void			_replaceSubstract( void );
	void			_getLeftRight( void );
	void			_handle(std::string & part, int sign);
	void			_reducedForm( void );
	void			_printCoeffs( std::string info );
	void			_findSolutions(bool arg);
	void			_findABC( void );
	void			_debugList();
	void 			_Alpha(std::string str, double real, double image);
	void 			_checkOthers(std::string str);
	void 			_checkToken(std::string token);
	void 			_checkReducedForm( void );
	void			_degOneSolution(bool fraction);
	void			_degTwoSolution(bool fraction);

// ** PUBLIC ** //

public:
	Computor( void );
	~Computor( void );

	void			treatEquation( std::string eq, bool arg, bool debug );


// ** EXCEPTIONS ** //

	class ComputorException : public std::runtime_error
	{
	private:
		ComputorException const & operator=(ComputorException const &) throw();
		ComputorException() throw();

	public:
		ComputorException(std::string const & errorMsg) throw();
		~ComputorException() throw();
		virtual const char* 		what() const throw();
	};

};

#endif // ** COMPUTOR_HPP ** //
