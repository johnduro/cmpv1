
#include <string>
#include <cctype>
#include "Computor.hpp"


// ** PRIVATE ** //

void			Computor::_initComputor( void )
{
	this->_str.clear();
	this->_left.clear();
	this->_right.clear();
	this->_coeffs.clear();
	this->_maxDegree = 0;
}

void			Computor::_replaceSubstract( void )
{
	std::string::iterator		begin = this->_str.begin();
	std::string::iterator		back;
	bool						remove;
	size_t						pos = 0;

	while (pos < this->_str.lenght() && ((pos = this->_str.find('-', pos)) != std::string::npos))
	{
		remove = true ;
		// back = begin + pos;
		// while (back != begin && (*back == '+' || isspace(*back)))
		for (back = begin + pos; back != begin && *back == '+'; back--)
		{
			if (*back == '+')
				remove = false ;
		}
		if (remove)
		{
			this->_str.replace(pos, 1, "+-");
			pos++;
		}
		pos++;
	}
}

void			Computor::_getLeftRight( void )
{
	size_t		pos;

	pos = this->_str.find('=');
	if (pos == std::string::npos)
		throw ComputorException("Parsing error : no '=' in equation");
	else if (pos == 0)
		throw ComputorException("Parsing error : '=' at start of equation");
	else if ((pos + 1) == this->_str.length())
		throw ComputorException("Parsing error : '=' at end of equation");
	this->_left = this->_str.substr(0, pos - 1);
	this->_right = this->_str.substr(pos + 1);
	if ((this->_str.find('=', ++pos)) != std::string::npos)
		throw ComputorException("Parsing error : multiple '=' present in equation");
}

void			Computor::_handle(std::string & part, int sign)
{
	std::istringstream		buffer(part);
	std::string				token;
	Coeff					coeff;
	size_t					pos;
	size_t					pos2;

	while (std::getline(buffer, token, '+'))
	{
		coeff.value = 0;
		coeff.degree = 0; //mettre tout le temps a 1 ?
		if ((pos = token.find('*')) != std::string::npos)
		{
			if (token.find('x', 0, pos) != std::string::npos || token.find('X', 0, pos) != std::string::npos)
			{
				coeff.value = (std::stod(token.substr(pos + 1)) * sign);
				if ((pos2 = token.find('^', 0, pos)) != std::string::npos)
					coeff.degree = std::stoi(token.substr(pos2 + 1, pos - 1));
				else
					coeff.degree = 1;
			}
			else
			{
				coeff.value = (std::stod(token) * sign); //s arrete bien ?
				if ((pos2 = token.find('^', pos)) != std::string::npos)
					coeff.degree = std::stoi(token.substr(pos2 + 1));
				else
					coeff.degree = 1;
			}
		}
		else
		{
			if (token.find('x') != std::string::npos || token.find('X') != std::string::npos)
			{
				coeff.value = 1 * sign;
				if ((pos2 = token.find('^', pos)) != std::string::npos)
					coeff.degree = std::stoi(token.substr(pos2 + 1));
				else
					coeff.degree = 1;
			}
			else
			{
				coeff.value = (std::stod(token) * sign);
				coeff.degree = 0;
			}
		}
		this->_coeffs.push_back(coeff);
	}
}

// ** PUBLIC ** //

Computor::Computor( void )
{}

Computor::~Computor( void )
{}

void			Computor::treatEquation( std::string eq )
{
	std::cout << "Treating equation : " << eq << std::endl;
	this->_initComputor();
	this->_str = eq;
	this->_str.erase(std::remove_if(this->_str.begin(), this->_str.end(), ::isspace), this->_str.end());
	//except ?
	this->_replaceSubtract();
	this->_getLeftRight();
	try
	{
		this->_handle(&this->left, 1);
		this->_handle(&this->right, -1);
	}
	catch (std::exception & e)
	{
		std::cout << "Error : " << e.what() << std::endl;
		throw ComputorException("Handle error");
	}

	std::cout << "---------------------------------------" << std::endl;
}


// ** EXCEPTIONS ** //

Computor::ComputorException::ComputorException( std::string const & errorMsg ) throw()
	: std::runtime_error(errorMsg)
{

}

const char*					Computor::ComputorException::what() const throw()
{
	std::string ret = "Computor exception : " + std::string(std::runtime_error::what());
	return ret.c_str();
}

Computor::ComputorException::~ComputorException() throw()
{
	return ;
}
